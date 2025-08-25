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
    int mod = 1e9+7;
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<long long int> dist(n);
         
        for(long long int i=0; i<n; i++){
            if(s[i]=='R'){
                dist[i] = (long long int)nums[i]+d;
            }
            else {
                dist[i] = (long long int)nums[i]-d;
            }
        }

        sort(dist.begin(), dist.end());

        long long int prefsum = 0;
        long long int ans = 0;

        // distance at i = i*val - prefsum
        for(long long i=0; i<n; i++){
            ans = (ans+ i*(long long)dist[i]- prefsum)%mod;
    
            prefsum = (prefsum+ dist[i])%mod;
        }
        return ans;
    }
};

// the direction change after collison of robot doesnt matter, we can ignore the colision and it will still give us the same resulting array 

// now we have resulting array of final indexes and we have to find distance between all indexes
// we need to sort the array as it will help in finding the distance
// 0 1 2 3
// a b c d
// i =0  a-a =0
// i=1  b-a = 1b-prefsum till one idx behing b
// i=2  c-a + c-b = 2c -(a+b) = idx*currVal + (prefsum not incluing curridx)
//i=3 d-a + d-b + d-c = 3d + (a+b+c) = idx* currval - prefsum

int main(){

    return 0;
}