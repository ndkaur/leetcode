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


// start , target , special -> {specialSourceX, specialSourceY, specialTargetX, specialTargetY, val }
// 1 ->  go from source to specialSource including(+) the given distance of SpecialSource to SpecialTarget
// start->specialSource + val(specialSoruce->specialTarget)

// doing step 1 will take us to sourceTarget 

// 2 -> now we must check that if we can reach in shorter distance from specialTarget to actual target
// check it and compare with answer , use the minimum of all

// 3-> but there can also be apossiblity that we can find a path with small dist using edges between different special nodes
// so find distance of specialY of idx=i with specialX of idx=j, diff indexes 
// cause a path can be made from -> source -> specialX(i) -> specialY(i) -> specialX(j) ->specialY(j)-> target
// and push it in pq , 

// again pop will happen and we will repeat from step 2 to 3
// caase as we pop we perfom step 2 , where we check if from the current poped index we can reach actual target 


// Time complexity:
// The time complexity of the solution is O(n^2 log n), where n is the number of special roads. 
// The reason for this time complexity is the loop that iterates over all the special roads and 
// the priority queue operations, which have a time complexity of O(log n).

// Space complexity:
// The space complexity of the solution is O(n), 
// which is due to the space occupied by the distance array. 
// The priority queue takes O(n) space as well. Thus, the overall space complexity is O(n).

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& special) {
        int n = special.size();
        int ans = abs(start[0]-target[0]) + abs(start[1]-target[1]); //find min than this

        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        // step1 -> find path from source -> specialPoint1 -> specialPoint2 -> val  and add to pq
        // source to each special vector<int> 
        for(int i=0; i<n; i++){
            dist[i] =  abs(start[0]-special[i][0])+ abs(start[1]-special[i][1]) + special[i][4];
            pq.push({dist[i], i});
        }

        // step 2 
        // see if can find minimum from whats already added in pq 
        while(pq.size()){
            auto d = pq.top().first;
            auto idx = pq.top().second;
            pq.pop();

            if(d!=dist[idx])// maybe already min found at that index
                continue;

            // check if min answer can be made 
            // we currently stand at Specialtarget and have to now go till target
            ans = min(ans, d + abs(target[0]-special[idx][2]) + abs(target[1]-special[idx][3]));

            // step 3 -> now other possibility is we are at SpecialTarget and go to specialSource at different index 
            // and push that in pq and again repeat step 2 of finding min ans from that curr state to target

            // specialTarget(idx) -> specialSource(i) // diff indexes 
            for(int i=0; i<n; i++){
                //  special target(idx) ->  special source(i) -> special target(i) already dist given add it 
                int newd = abs(special[idx][2]-special[i][0]) + abs(special[idx][3]-special[i][1]) + special[i][4];
                if(d + newd < dist[i]){
                    dist[i] = d + newd;
                    pq.push({dist[i], i});
                }
            }
        }
        // this whole process will happen until the pq becomes empty and we will get min ans from source to target 
        return ans;
    }
};


// start -> special X -> special Y + dist  , now 2 options
//  1. directly go to target ...... start -> special X -> special Y + dist -> target ///// update min ans 
// 2. explore more to other special edges... start -> special X(idx=1) -> special Y(idx=1) + dist -> special X(idx=2) -> special Y(idx=2) + dist  /// put in pq repeat steps 1 and 2 




int main(){

    return 0;
}