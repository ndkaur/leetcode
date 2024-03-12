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


// simple greedy 
class Solution {
public:
    int maxJump(vector<int>& stones) {
        // we want min cost 
        int n = stones.size();
        int ans = stones[1]-stones[0];
        for(int i=1; i<n-1; i++){
            ans = max(ans, stones[i+1]-stones[i-1]);
        }
        return ans;
    }
};

// standing on curr rock , we take cur+1 for moving ahead 
// but when coming back we cant take the curr or curr+1 , so we need to take curr-1
// so standing at curr -> max(going ahead, coming back) ,
// max(curr[i+1]-curr[i], curr[i+1]-curr[i-1])  
// each time its obvioos that array is increasing order so curr[i+1] -curr[i-1] will always be max , so directly take it 

// 0 2 5 6 7 
// ans = 2, 5 , 4,  2 = max = 5


// much complicated , binary search 
class Solution {
public: 
    bool isPossible(int mx, vector<int>& stones){
        int n = stones.size();
        vector<bool> visited(n,0);
        // forward direction 
        int idx = 0;
        while(idx<n-1){
            int j = idx;
            while(j+1<n && stones[j+1]<=stones[idx]+mx){
                j++;
            }
            if(j==idx)
                return false;
            idx = j;
            visited[idx]=true;
        }
        // backward direction 
        vector<int> rem;
        for(int i=0; i<n-1; i++){
            if(visited[i]==false)
                rem.push_back(i);
        }
        rem.push_back(n-1);

        idx = rem.size()-1;
        while(idx>0){
            int j = idx;
            while(j>0 && stones[rem[j-1]]>=stones[rem[j]]-mx){
                j--;
            }
            if(j==idx)
                return false;
            idx = j;
        }
        return true;
    }

    int maxJump(vector<int>& stones) {
        // we want min cost 
        int n = stones.size();
        int l = 0; // low as 0 will never be the max distance of the path -> not possible 
        int r = stones[n-1] - stones[0];

        while(l<=r){
            int mid = l+(r-l)/2;
            if(isPossible(mid, stones)){ // we want as min from the max 
                // mid is possible so seach for more min 
                r = mid-1;
            }
            else 
                l = mid+1;
        }
        return l;
    }
};


int main(){

    return 0;
}