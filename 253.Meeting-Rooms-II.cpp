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

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // no of non overlaping intervals 
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        
        priority_queue<int,vector<int>, greater<int>> pq;
         //s1<=e2,  use condition-> s2<=e1   , top ={s1,e1}, curr={s2,e2}
        for(auto inter:intervals){
            // if merge then = s2<=e1 ie  interval[0] <= pq.top()
            // we want not merge = s2>=e1  ie  inter[0]>=pq.top()
            // end time of earlier meeting < start time of next then room empty 
            if(pq.size() && pq.top()<=inter[0]){
                pq.pop();
            }
            pq.push({inter[1]});
        }
        return pq.size();
    }
};

int main(){

    return 0;
}