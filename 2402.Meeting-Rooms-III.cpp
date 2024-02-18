#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}


class Solution0 {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        // sorting on basis of smallest start time first 
        sort(meetings.begin(), meetings.end());

        vector<long long> store(n,0); // storing the end time of meeting  in each room
        vector<int> roomUsed(n,0); // storing the count the number of times each number is used 


        for(auto meet:meetings){
            int start  = meet[0];
            int end = meet[1];
            bool foundRoom = false;

            long long earlyEndRoomTime = LLONG_MAX;
            int earlyEndRoom = 0;

            // cheking all the rooms if available or not 
            for(int i=0; i<n; i++){
                // checking if any room got empty by the start of new meeting
                if(store[i]<=start){
                    // occupy the room 
                    store[i] = end; // now this room will be availbale at end time
                    roomUsed[i]++; // increase its count 
                    foundRoom = true;
                    break;
                }
                
                // incase we didnt find any room available so we need to keep a store of min time of all rooms that will be free first
                // to check in which room meeting will end at first in minimum time of all
                if(store[i] <  earlyEndRoomTime){
                    earlyEndRoomTime = store[i];
                    earlyEndRoom = i;
                }  
            }

            // if we are not able to found any room 
            if(!foundRoom){
                // room not found we will wait for room to be empty and start from end time to the actual time of the meeting ie end-start
                // pick room which will end first
                store[earlyEndRoom] += (end - start);
                roomUsed[earlyEndRoom]++;
            }
        }

        // finding max room used of all
        int ans = -1;
        int mx =0;

        for(int i=0; i<n; i++){
            if(roomUsed[i]>mx){
                mx = roomUsed[i];
                ans = i;
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        // sorting on basis of smallest start time first 
        sort(meetings.begin(), meetings.end());

        vector<int> roomcnt(n,0);
        // time, room 
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used;
        priority_queue<int,vector<int>, greater<int>> unused;

        // in the begining all rooms are unused
        for(int i=0; i<n; i++){
            unused.push(i);
        }

        for(auto meet:meetings){
            int start = meet[0];
            int end = meet[1];

          // checking by which time the room will get empty and marking it as unsed for next meeting
            // used pq top will be the min time , if that time is less than the curr start time of meeting use it
            while(used.size() && used.top().first<=start){
                int room = used.top().second; 
                used.pop();
                unused.push(room);
            }
            
            // we have empty rooms , directly use them 
            if(unused.size()){
                int room = unused.top();
                unused.pop();
                // now the room is getting occupied till end time 
                used.push({end, room});
                roomcnt[room]++;
            }
            else{ // no empty rooms have to wait to get empty with delay time 
                int room = used.top().second;
                long long endTime = used.top().first;
                used.pop();
                // delayed time = the time at which last meeting ends + the actual time the new meeting will take 
                used.push({endTime + (end-start), room});
                roomcnt[room]++;
            }
        }

        int ans = -1;
        int mx = 0;
        for(int i=0; i<n; i++){
            if(roomcnt[i]>mx){
                mx = roomcnt[i];
                ans = i;
            }
        }
        return ans;
    }
};




int main(){

    return 0;
}