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
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        int ans =0;
        queue<int> q;
      
        vector<bool> reachClosedBox(n, false); //Only used to store boxes that are reached but closed.

        for(int i:initialBoxes){
            // if initial box already open then add to queue 
            if(status[i]==1){
                q.push(i);
            }
            else{ // inital box is closed 
                reachClosedBox[i] = true;
            }
        }

        while(q.size()){
            // open box  directly add candies 
            auto idx = q.front();
            q.pop();
            ans += candies[idx];
            // now for that index check its box contain what all boxes and what keys 
            for(auto itr:keys[idx]){
                if(status[itr]==0 && reachClosedBox[itr]==true){ // closed and in the reach array
                    q.push(itr); // its closed but we have its key
                }
                status[itr]=1; // since found the key we can open it change status
            }
            // checking contained boxes 
            for(auto itr:containedBoxes[idx]){
                if(status[itr]==1) // box is open pick it 
                    q.push(itr);
                else // we have already reached it but box is closed 
                    reachClosedBox[itr] = true;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}