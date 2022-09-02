/** @file main.cpp
 *  @brief Rhymes
 *
 *  The program of automatic generation of poems. One of the modules
 *  of this program should select rhymes to words from some dictionary.
 *
 *  The dictionary contains n different words. Words will be called
 *  sequences of 1-10 lowercase letters of the Latin alphabet.
 *
 *  The rhyming of two words is the length of their largest common
 *  suffix (we will call a suffix a certain number of letters at the
 *  end of a word). For example:
 *  1. task and flask have a rhyme of 3 (the largest common suffix
 *  is ask);
 *  2. decide and code have a rhyme of 2 (the largest common suffix
 *  is de);
 *  3. id and void have a rhyme of 2 (the largest common suffix is id);
 *  4. code and forces have a rhyme of 0.
 *
 *  The program should process q queries of the following type:
 *  given a word ti (possibly belonging to a dictionary), it is
 *  necessary to find a word from the dictionary that does not match
 *  ti and has the maximum rhyme with ti among all dictionary words
 *  that do not match ti. If there are several suitable words, output
 *  any of them.
 *
 *  @return For each query, output one line — a word from the dictionary
 *  that does not match the one specified in the query and has maximum
 *  rhyme with it (if there are several of them, output any).
 *
 *  @author Demidov Ignatii
 *  @bug No known bugs.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main() {
    int size;
    std::cin>>size;
    std::unordered_map<std::string,std::unordered_set<std::string>> dict;
    std::vector<std::string> words;
    for(int i=0;i<size;i++){
        std::string word;
        std::cin>>word;
        dict[word].insert(word);
        words.push_back(word);
        for(int i=1;i<word.size();i++){
            std::string tmp=word.substr(i);
            dict[tmp].insert(word);
        }
    }

    std::cin>>size;
    for(int i=0;i<size;i++){
        std::string fWord;
        std::cin>>fWord;
        std::string maxWord;
        for(auto word:words){
            if(fWord!=word) {
                maxWord=word;
                break;
            }
        }
        bool isFind=false;
        for(int j=0;j<fWord.size();j++){
            std::string tmp=fWord.substr(j);
            auto suffix=dict.find(tmp);
            if(suffix!=dict.end()){
                for(auto word:suffix->second){
                    if(fWord!=word) {
                        maxWord=word;
                        isFind=true;
                        break;
                    }
                }
            }
            if(isFind) j=fWord.size();
        }

        std::cout<<maxWord<<std::endl;
    }
}
