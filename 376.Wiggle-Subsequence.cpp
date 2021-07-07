#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution0 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n= nums.size();
        if(n<2)return n;
        // max(first +ve , first -ve)
        return 1+ max(check(nums,0,true),check(nums,0,false));
    }
    int check(vector<int>&nums, int idx, bool increase){
        int count =0;
        for(int i=idx+1;i<nums.size();i++){
            if((increase && nums[i]>nums[idx]) || !increase && nums[i]<nums[idx])
                count = max(count,1+ check(nums,i,!increase));
        }
        return count;
    }
};

class Solution1 {
public:
    int wiggleMaxLength(vector<int>& nums){
        int n= nums.size();
        if(n<2)return n;
        vector<int> inc(n);
        vector<int> dec(n);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    inc[i]= max(inc[i],dec[j]+1);
                else if(nums[i]<nums[j])
                    dec[i] = max(dec[i],inc[j]+1);
            }
        }
        return 1+max(inc[n-1],dec[n-1]);
    }
};


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums){
        int n= nums.size();
        if(n<2)return n;
        vector<int> inc(n);
        vector<int> dec(n);
        inc[0]=dec[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc[i]=dec[i-1]+1;
                dec[i]=dec[i-1];
            }
            else if(nums[i]<nums[i-1]){
                dec[i]=inc[i-1]+1;
                inc[i]=inc[i-1];
            }
            else{
                dec[i]=dec[i-1];
                inc[i]=inc[i-1];
            }
        }
        return max(dec[n-1],inc[n-1]);
    }
};


int main(){
    Solution sol;
    vector<int> nums={1,7,4,9,2,5};
    int ans = sol.wiggleMaxLength(nums);
    cout<<ans;
    return 0;
}