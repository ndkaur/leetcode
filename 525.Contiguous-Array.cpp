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


class Solution0 { // brute force 
public:
    int findMaxLength(vector<int>& nums) {
		int maxlen = 0;
        for(int i=0; i<nums.size(); i++){
            int zeroes = 0, ones = 0;
            for(int j=i; j<nums.size(); j++){
                if(nums[j]==0){
                    zeroes++;
                } 
                else{
                    ones++;
                }
                if(zeroes==ones){
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return maxlen;
    }
};



class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int oneCnt = 0;
        int zeroCnt = 0;
        int ans = 0;
        unordered_map<int,int> mp; // diff btw cnts , idx 
        mp[0] = -1;
        for(int i=0; i<n; i++){
            if(nums[i]==0)
                zeroCnt++;
            else 
                oneCnt++;

            int diff = zeroCnt-oneCnt;
            if(mp.find(diff)!=mp.end()){
                ans = max(ans, i-mp[diff]);
            }
            else 
                mp[diff] = i;
        }
        return ans;
    }
};

// 0 1 2 3 4  idx
// 0 1 0 1 0  nums

// zcnt = 2    ocnt =  2
// ans = 1-(-1)= (2, 3-(-1)) = 4 

//   diff  idx 
// mp  0 =  -1     
//     1 =  0 
// 


class Solution { 
public:
    int findMaxLength(vector<int>& nums) {
		int n = nums.size();
        int sum = 0;
        int mx = 0;

        unordered_map<int,int> mp;
        mp[0] = -1;
        
        for(int i=0; i<n; i++){
            sum += nums[i]==1 ? 1 : -1;
            if(mp.count(sum)){
                mx = max(mx, i-mp[sum]);
            }
            else 
                mp[sum] = i;
        }
        return mx;
    }
};


int main(){

    return 0;
}