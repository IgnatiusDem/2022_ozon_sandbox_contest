/** @file main.cpp
 *  @brief Report
 *
 *  The director of an IT corporation evaluates the performance
 *  of employees according to various indicators and criteria.
 *  One of these criteria is formulated as follows: having started
 *  a certain task, the employee must complete it without switching
 *  to other tasks.
 *
 *  In order to check employees for compliance with this criterion,
 *  the director demanded from each employee a report on what tasks
 *  he had performed in the last n days. The report is a sequence
 *  of n integers a1,a2,...,an, where ai is the ID of the task that
 *  the employee performed on the i—th day.
 *
 *  You need to write a program that checks whether an employee meets
 *  the criteria for his report. The employee meets this criterion if
 *  there is no such task x that was performed with a break (i.e. on
 *  some day i, the employee performed task x, on days i+1 to j−1, he
 *  was engaged in other tasks, and on day j, the employee continued to
 *  perform task x, while j >i+1). In other words, each task performed
 *  by an employee should take one continuous period of days.
 *
 *  @author Demidov Ignatii
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t; // count of input data sets
    std::cin>>t;

    for(int i=0;i<t;i++){
        int n; // count of employee reports
        std::cin>>n;
        std::vector<std::pair<int,int>> days;

        for(int i=0;i<n;i++){
            int task; // task report
            std::cin>>task;
            days.push_back({task,i});
        }
        std::sort(days.begin(),days.end());

        bool isOk=true;
        for(int i=0;i<days.size();i++){
            if(i!=(days.size()-1)&&days[i].first==days[i+1].first){
                if((days[i+1].second-days[i].second)>1){
                    isOk=false;
                    i=days.size();
                }
            }
        }

        if(isOk)std::cout<<"YES"<<std::endl;
        else std::cout<<"NO"<<std::endl;
    }
}