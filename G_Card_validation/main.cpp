/** @file main.cpp
 *  @brief Card validation
 *
 *  A program for validating the correctness of a map for a strategic
 *  computer game.
 *
 *  The map consists of hexagons (hexagons), each of which belongs to
 *  some region of the map. In the game files, the map is represented
 *  as n lines of m characters each (the lines and characters in them
 *  are numbered from one). Every odd character of every even line and
 *  every even character of every odd line is a dot (symbol . with
 *  ASCII code 46); all other characters correspond to hexagons and
 *  are capital letters of the Latin alphabet. The letter indicates
 *  which region the hexagon belongs to.
 *
 *  @return For each set of input data, output the answer in a separate
 *  line — YES if each region of the map represents a connected area,
 *  or NO if it is not.
 *
 *  @author Demidov Ignatii
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

void addCoords(std::map<char,std::vector<std::pair<int,int>>>& coords,
               char& colour, int& row, int& col){
    auto findColour=coords.find(colour);
    if(findColour!=coords.end()){
        findColour->second.push_back({row,col});
    }else{
        std::vector<std::pair<int,int>> tmp={{row,col}};
        coords[colour]=tmp;
    }
}

void dfs(std::vector<bool>& used,
         std::vector<std::vector<int>>& graph,
         int cur){
    used[cur]=true;
    for(int i=0;i<graph[cur].size();i++){
        int next=graph[cur][i];
        if(!used[next]) dfs(used,graph,next);
    }
}

int main() {
    int t; // count of input data sets
    std::cin>>t;
    for(int idxMap=0;idxMap<t;idxMap++){
        int n,m; // count of lines and count of characters in each line
        std::cin>>n>>m;

        std::map<char,std::vector<std::pair<int,int>>> coords;

        for(int row=0;row<n;row++){
            std::string line;
            std::cin>>line;
            int pos=0;
            if(line[0]=='.') pos++;

            for(int col=pos;col<line.size();col+=2){
                addCoords(coords,line[col],row,col);
            }
        }
        bool isOk=true;
        for(auto colour:coords){
            auto vertex=colour.second;

            //create graph
            std::vector<std::vector<int>> graph(vertex.size());
            for(int i=0;i<vertex.size();i++){
                for(int k=i+1;k<vertex.size();k++){
                    if((abs(vertex[i].first-vertex[k].first)==1&&
                        abs(vertex[i].second-vertex[k].second)==1)||
                       (abs(vertex[i].first-vertex[k].first)==0)&&
                       abs(vertex[i].second-vertex[k].second)==2){
                        graph[i].push_back(k);
                        graph[k].push_back(i);
                    }
                }
            }

            //deep search
            int count=0;
            std::vector<bool> used(vertex.size(),false);
            for(int i=0;i<vertex.size();i++){
                if(!used[i]){
                    dfs(used,graph,i);
                    count++;
                }
            }
            if(count>1) {
                isOk=false;
                break;
            }
        }

        if(isOk) std::cout<<"YES"<<std::endl;
        else std::cout<<"NO"<<std::endl;
    }
}
