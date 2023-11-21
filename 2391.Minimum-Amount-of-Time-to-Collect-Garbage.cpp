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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // 1 minute if pick the garbage + time to travel between houses
        int n = garbage.size();
        // garbage = ["G","P","GP","GG"], travel = [2,4,3]
        // res = 1 min to paick all =  6 
        // res = prefix sum of travel =  2 6 9
        // last = // G->3  , P->2 
        // c= P -> res += t[last[c]-1] = travel[1] = 6 
        // res = 6 + 6 = 12
        //  c= G  res += travel[last[G]-1] = travel[2] = 9 
        // res = 12+9 = 21 
        vector<int> last(128);
        int res = 0;
        // marking the last occurence of char 
        for(int i=0; i<n; i++){
            res += garbage[i].size();
            for(auto ch:garbage[i]){
                last[ch] = i;
            }
        }
        // prefix sum of travel
        for(int i=1; i<travel.size(); i++){
            travel[i] += travel[i-1];
        }
        // calculating the total res
        for(auto ch:"PGM"){
            if(last[ch])
                res+= travel[last[ch]-1]; // last occurence prefix sum
        }
        return res;
    }
};


int main(){

    return 0;
}