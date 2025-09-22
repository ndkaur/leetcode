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


class Router {
public:
    queue<vector<int>> q;// to maintian fifo
    map<vector<int>, int> duplicate;  // to track duplicates

    unordered_map<int, vector<int>> time_ranges; // destination, timmes 
    // this will keep track of for hat destination we have what all timestamps , when we need getCount we can find the no of ranges between that destinations time ub lb 

    unordered_map<int,int> removedPackets; // destination, cnt
    // this will keep track of cnt of packets removed with the destination so that we dont take them in the getCount function

    int sz=0;

    Router(int memoryLimit) {
        sz = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};

        if(duplicate.count(packet)) // if duplicates occur 
            return false;
        
        if(q.size()==sz){ // reached the max limit of the queue 
            vector<int> temp = q.front();
            duplicate.erase(temp); 
            // keeping cnt of all removed packets 
            int dest = temp[1];
            removedPackets[dest]++;
            q.pop();
        }

        q.push(packet);
        duplicate[packet]++;
        // keeping  all the packets time for that destination
        time_ranges[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty())
            return {};

        vector<int> val = q.front();
        q.pop();
        duplicate.erase(val);
        // removing it and keeping cnt of removed
        int dest =  val[1];
        removedPackets[dest]++;

        return val;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        // if that destination is alredy rmoved then no cnt 
        if(time_ranges.find(destination)==time_ranges.end())
            return 0;
        
        auto &all_times = time_ranges[destination];
        // we also need the no of times that destination was removed 
        int removed_cnt = removedPackets[destination];
        // lb -> elm >= than val // left side range   = start
        // ub -> elm > then val // right side = end
        // start indx + cnt of values we will skip 
        auto start = lower_bound(all_times.begin()+removed_cnt, all_times.end(), startTime);
        auto end = upper_bound(all_times.begin()+removed_cnt, all_times.end(), endTime);

        return int(end-start);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

int main(){

    return 0;
}