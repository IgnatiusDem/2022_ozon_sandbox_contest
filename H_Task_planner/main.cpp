/** @file main.cpp
 *  @brief Task planner
 *
 *  You have built your own server from n heterogeneous processors and
 *  now you have decided to create a simple task scheduler for it.
 *
 *  Your server consists of n processors. But since the processors are
 *  different, they achieve the same speed at different power
 *  consumption. Namely, the i-th processor in the load spends ai
 *  energy in one second.
 *
 *  Your server will receive m tasks as a test load. You know two values
 *  about each task: tj and lj — the moment of time when task j arrives
 *  and the task execution time in seconds.
 *
 *  To begin with, you decided to implement a simple scheduler that
 *  behaves as follows: at the time of tj arrival of the task, you
 *  select a free processor with minimal power consumption and perform
 *  this task on the selected processor for the entire specified time.
 *  If there are no free processors by the time the task arrives, then
 *  you simply discard the task.
 *
 *  The processor on which task j is running will be occupied for
 *  exactly lj seconds, that is, it will be released exactly at the
 *  moment tj+lj and at the same moment
 *
 *  @return Output a number — the total power consumption of the server,
 *  if the power consumption in idle time can be neglected.
 *
 *  @author Demidov Ignatii
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n,m;
    std::cin>>n>>m;
    std::vector<std::pair<long long,long long>> processor;

    for(int i=0;i<n;i++){
        long long tmp;
        std::cin>>tmp;
        processor.push_back({tmp,0});
    }
    std::sort(processor.begin(),processor.end());
    long long t=0;
    for(int i=0;i<m;i++){
        long long timeIn,taskTime;
        std::cin>>timeIn>>taskTime;
        for(int j=0;j<processor.size();j++) {
            if (processor[j].second <= timeIn) {
                processor[j].second = timeIn + taskTime;
                t+=processor[j].first*taskTime;
                j=processor.size();
            }
        }
    }
    std::cout<<t<<std::endl;
}
