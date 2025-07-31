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


class Solution { // O(2^N)
public:
    int find(int idx, int orr , vector<int>& nums, int& mx){
        int n = nums.size();
        if(idx==n)
            return orr==mx? 1:0;
          
        int pick = find(idx+1, orr|nums[idx], nums, mx); 
        int npick = find(idx+1, orr, nums, mx);
        return pick+npick;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(int num:nums){
            mx = mx|num;
        }
        
        return find(0, 0,nums, mx);
        
    }
};

class Solution {
public:
    void find(int idx, int orr , vector<int>& nums, int& mx, int& cnt){
        int n = nums.size();
        if(orr==mx)
            cnt++;
        for(int i=idx; i<n; i++){
            find(i+1, orr|nums[i], nums, mx, cnt); 
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int orr = nums[0];
        int mx = orr;
        for(int i=1; i<n; i++){
            orr = orr | nums[i];
            mx = max(mx, orr);
        }
        int cnt = 0;
        find(0, 0,nums, mx, cnt);
        return cnt;
    }
};


//101
// 11 
//111 = 7
// 10
//111 


int main(){

    return 0;
}