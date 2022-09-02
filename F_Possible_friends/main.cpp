/** @file main.cpp
 *  @brief Possible friends
 *
 *  In many social networks, users have the option to specify other
 *  users as their friends. In addition, there is often a friend
 *  recommendation system that shows users people they know indirectly
 *  (through one of their friends) and suggests adding these people to
 *  the friends list. You have to develop a system for recommending
 *  friends.
 *
 *  There are n users in the social network we are interested in, each
 *  of which is assigned a unique id from 1 to n. Each user of this
 *  network has no more than 5 friends. Obviously, no user is a friend
 *  to himself, and if user x is in user y's friends list, then user y
 *  is also in user x's friends list.
 *
 *  Let's describe how the list of possible friends for each user should
 *  be formed. For user x, the list should include users y such that:
 *
 *  1. y is not a friend of x and is not the same as x;
 *  2. user y and user x have at least one mutual friend;
 *  3. there is no user y' who satisfies the first two constraints and
 *  who has strictly more mutual friends with x than y has with x.
 *
 *  In other words, the list of possible friends of user x includes all
 *  such users who are not his friends, for whom the number of mutual
 *  friends with x is maximum. Note that the list of possible friends
 *  may be empty
 *
 *  @return For each user from 1 to n, output in a separate line a list of
 *  his possible friends in the following format:
 *  1. if the list of possible friends is empty, print a single integer 0;
 *  2. otherwise, output the IDs of the user's possible friends in
 *  ascending order.
 *
 *  @author Demidov Ignatii
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

int main() {
    int n,m; // number of users and number of pairs of friends
    std::cin>>n>>m;
    std::vector<std::set<int>> users(n);

    for(int i=0;i<m;i++){
        int first,second; // a couple of friends
        std::cin>>first>>second;
        users[first-1].insert(second);
        users[second-1].insert(first);
    }

    std::vector<std::set<int>> ans(n);
    for(int i=0;i<users.size();i++){
        int maxMatch=0;
        std::map<int,int> possibleFriends;
        for(auto fr:users[i]){
            for(auto pos:users[fr-1]){
                auto isExist=users[i].find(pos);
                if(isExist==users[i].end()){
                    if(pos!=(i+1)){
                        auto search=possibleFriends.find(pos);
                        if(search==possibleFriends.end()){
                            possibleFriends[pos]=1;
                            maxMatch=std::max(maxMatch,1);
                        }else{
                            search->second++;
                            maxMatch=std::max(maxMatch,search->second);
                        }
                    }
                }
            }
        }
        if(!possibleFriends.empty()){
            for(auto it:possibleFriends){
                if(it.second==maxMatch){
                    std::cout<<it.first<<' ';
                }
            }
            std::cout<<std::endl;
        }else{
            std::cout<<0<<std::endl;
        }
    }
}