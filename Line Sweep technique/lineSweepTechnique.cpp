#include<bits/stdc++.h>
using namespace std;

//1854 : Maximum Population Year
int maximumPopulation(vector<vector<int>>& logs) {
vector<pair<int, int>> events;
for(auto &log : logs){
events.push_back({log[0], +1});
events.push_back({log[1], -1});
}
sort(events.begin(), events.end());
int currPop = 0;
int maxPop = 0;
int result = 2050;
for(auto &event : events){
currPop += event.second;
if(currPop > maxPop){
    maxPop = currPop;
    result = event.first;
}
}
return result;
}


//1109 : Corporate Flight Bookings
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
vector<int> diff(n+2, 0);
for(auto &booking : bookings){
    diff[booking[0]]+= booking[2];
    diff[booking[1]+1]-= booking[2];
}
vector<int>result;
int cumSum = 0;
for(int i = 1; i <= n; i++){
    cumSum += diff[i];
    result.push_back(cumSum);
}
return result;
}

//253 : Meeting Rooms 2 (LC premium , gfg free)
int minMeetingRooms(vector<int> &start, vector<int> &end) {
    // code here
    vector<pair<int, int>> events;
    int n =  start.size();
    for(int i = 0; i < n; i++){
        events.push_back({start[i], +1});
        events.push_back({end[i], -1});
    }
    sort(events.begin(), events.end());
    int cumSum = 0;
    int overlap = 0;
    for(auto &event : events){
        cumSum += event.second;
        if(cumSum>overlap){
            overlap = cumSum;
        }
    }
    return overlap;
}