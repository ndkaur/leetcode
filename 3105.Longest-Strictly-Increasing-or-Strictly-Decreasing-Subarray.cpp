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


class Solution0 {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = 1;

        int cnt = 1;
        for(int i=0; i<n-1; i++){
            if(nums[i]< nums[i+1]){
                cnt++;
            }
            else{
                cnt = 1;
            }
            mx = max(mx, cnt);
        }
        
        cnt = 1; 
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]){
                    cnt++;
            }
            else{
                cnt=1;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};


class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            int cnt=1;
            for(int j=i+1; j<n; j++){
                if(nums[j-1]<nums[j]){ // increasing order 
                    cnt++;
                }
                else{
                    break;
                }
            }
            ans=max(ans,cnt);
        }
        
        for(int i=0; i<n; i++){
            int cnt=1;
            for(int j=i+1; j<n; j++){
                if(nums[j-1]>nums[j]){
                    cnt++;
                }
                else{
                    break;
                }
            }
            ans=max(ans,cnt);
        }
        
        return ans;
    }
};

int main(){

    return 0;
}