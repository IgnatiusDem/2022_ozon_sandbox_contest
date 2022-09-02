/** @file main.cpp
 *  @brief Time segments
 *
 *  A set of time intervals is set. Each segment is specified in
 *  the format HH:MM:SS-HH:MM:SS, that is, the hours, minutes and
 *  seconds of the left border of the segment are set first, and
 *  then the hours, minutes and seconds of the right border.
 *
 *  Validation of a given set of time intervals is performed. In
 *  other words, the following conditions are checked:
 *
 *  1. the hours, minutes and seconds are set correctly (that is,
 *  the hours are in the range from 0 to 23, and the minutes and
 *  seconds are in the range from 0 to 59);
 *  2. the left boundary of the segment is no later than its right
 *  boundary (but the boundaries may be equal);
 *  3. no pair of segments intersect (even at boundary points in time).
 *
 *  YES is output if the specified set of time intervals passes
 *  validation, and NO otherwise.
 *
 *  Testing is carried out on t independent sets of test data.
 *
 *  @author Demidov Ignatii
 *  @bug No known bugs.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Time{
    Time()=default;

    int hour;
    int minutes;
    int seconds;
};

bool operator > (const Time& a, const Time& b){
    if(a.hour>b.hour) return true;
    if(a.hour==b.hour&&a.minutes>b.minutes) return true;
    if(a.hour==b.hour&&a.minutes==b.minutes&&
       a.seconds>b.seconds) return true;
    return false;
}

bool operator < (const Time& a, const Time& b){
    if(a.hour<b.hour) return true;
    if(a.hour==b.hour&&a.minutes<b.minutes) return true;
    if(a.hour==b.hour&&a.minutes==b.minutes&&
       a.seconds<b.seconds) return true;
    return false;
}

bool operator >= (const Time& a, const Time& b){
    if(a.hour<b.hour) return false;
    if(a.hour==b.hour&&a.minutes<b.minutes) return false;
    if(a.hour==b.hour&&a.minutes==b.minutes&&
       a.seconds<b.seconds) return false;
    return true;
}

bool operator <= (const Time& a, const Time& b){
    if(a.hour>b.hour) return false;
    if(a.hour==b.hour&&a.minutes>b.minutes) return false;
    if(a.hour==b.hour&&a.minutes==b.minutes&&
       a.seconds>b.seconds) return false;
    return true;
}

void getTime(std::string& s,
             Time& time,
             int& start,
             bool& check){
    std::string tmp="";
    tmp+=s[start];
    tmp+=s[start+1];
    time.hour=std::stoi(tmp);
    start+=3;

    tmp="";
    tmp+=s[start];
    tmp+=s[start+1];
    time.minutes=std::stoi(tmp);
    start+=3;

    tmp="";
    tmp+=s[start];
    tmp+=s[start+1];
    time.seconds=std::stoi(tmp);
    start+=3;

    if(time.hour<0||time.hour>23) check=false;
    else if(time.minutes<0||time.minutes>59) check=false;
    else if(time.seconds<0||time.seconds>59) check=false;
}

bool checkCrossTime(std::pair<Time,Time>& time1,
                    std::pair<Time,Time>& time2){
    if(time1.first<=time2.second&&time1.second>=time2.first) return false;
    return true;
}

int main() {
    int t; //count of test data sets
    std::cin>>t;

    for(int i=0;i<t;i++){
        int n; //count of time segments
        std::cin>>n;
        bool isOk=true;
        std::vector<std::pair<Time,Time>> times;

        for(int j=0;j<n;j++){
            std::string s; // time interval format HH:MM:SS-HH:MM:SS
            std::cin>>s;
            Time left=Time();
            Time right=Time();
            int start=0;
            getTime(s,left,start,isOk);
            if(isOk) getTime(s,right,start,isOk);
            if(isOk) isOk=left<=right;
            if(isOk) times.push_back({left,right});
            else j==n;
        }
        std::sort(times.begin(),times.end());

        if(isOk) {
            for (int j = 0; j < times.size(); j++) {
                if(j!=times.size()-1){
                    isOk = checkCrossTime(times[j], times[j+1]);
                }
                if (!isOk) j = times.size();
            }
        }

        if(isOk)std::cout<<"YES"<<std::endl;
        else std::cout<<"NO"<<std::endl;
    }
}
