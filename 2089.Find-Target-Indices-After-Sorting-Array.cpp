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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

class Solution0 {  // tc->(nlogn +n)
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
              if(nums[i]==target){
                    ans.push_back(i);
              }
        }
        return ans;
    }
};

class Solution { //O(nlogn + logn +n+ mlogm)-> nlogn h
public:
    int bsearch(vector<int>& nums, int target){
        int n= nums.size();
        
        int l=-1;
        int r= n;
       
        while(1+l<r){
            int mid= l+(r-l)/2;
            if(nums[mid]>target){
                r= mid;
            }
            else if(nums[mid]<target)
                l= mid;
            else 
                return mid;
        }
        return -1;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int idx= bsearch(nums,target);
        int n= nums.size();
        //  so if dublicates exist it will be one idx behind or ahead cause sorted array 
        if(idx==-1) return {};
        int i= idx-1;
        vector<int> ans;
        while(i>=0){
            if(nums[i]==target)
                ans.push_back(i);
            else 
                break;
            i--;
        }
        ans.push_back(idx); // insert the mid itself
        i= idx+1;
        while(i<n){
            if(nums[i]==target)
                    ans.push_back(i);
            else
                break;
            i++;     
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution sol;
	vector<int> nums={1,2,5,2,3};
	int target=2;
	vector<int> ans=sol.targetIndices(nums,target);
	print(ans);
   return 0;
}

