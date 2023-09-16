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


 // (x1^x2)+(y1^y2)= k
        //    0   +  5    = 5
        //    1   +  4    = 5
        //    i   +  k-i  = k 
        // ...
        // ...
        //    k   + 0    = k 
class Solution {
public:
    int countPairs(vector<vector<int>>& coord, int k) {
        int n = coord.size();
        map<vector<int>,int> mp;
        int ans = 0;

        for(auto itr:coord){
            // j will go from 0 to k 
            int j =0;
            while(j<=k){
                int x = itr[0]^j;
                int y = itr[1]^(k-j);
                vector<int> temp = {x,y};
                if(mp.find(temp)!=mp.end()){
                    ans += mp[temp]; // add the freq of temp occurence 
                }
                j++; // check one itr for all values of j=0 to k
            }
            mp[itr]++;
        }
        return ans;
    }
};

int main(){

    return 0;
}