/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */
#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution0 {
public:
    bool checkIfExist(vector<int>& a) {
        int n = a.size();
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(a[i]*2==a[j] || a[i]==2*a[j])
                    return true;
            } 
        }
        return false;
    }
};

class Solution1 {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        set<int> save;
        for(int i=0;i<n;i++){
            if(arr[i]%2==1){
                int twice=2*arr[i];
                if(save.count(twice))
                    return true;
                save.insert(arr[i]);
            }

            else{
                int half = arr[i]/2;
                int twice = 2*arr[i];
                if(save.count(half) || save.count(twice) )
                    return true;
                else
                    save.insert(arr[i]);
            }
        }
         return false;
    }
};

// binary search 
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n= arr.size();
        sort(arr.begin(),arr.end()); // double exist 
        for(int i=0;i<n;i++){
            int ans = search(arr,arr[i]);
            if(ans !=i && ans !=-1) 
                return true;
        }
        return false;
    }
    int search(vector<int>& arr, int target){
        int n= arr.size();
        int l= 0;
        int r=n-1;
        while(l<=r){
            int mid= l+(r-l)/2;
            if(arr[mid]>2*target)
                r= mid-1;
            else if(arr[mid]<2*target)
                l= mid+1;
            else 
                return mid;
        }
        return -1;
    }
};


class Solution {
public:
    bool checkIfExist(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> mp;
    
        for(int i=0;i<n;i++){
            // 5*2 
            if(mp.find(nums[i]*2)!=mp.end())
                return true;
            //  10%2==0 or 3%2!=0 can give 1 as ans
            if(nums[i]%2==0 && mp.find(nums[i]/2)!=mp.end())
                return true;
            mp[nums[i]]++;
        }
        return false;
    }
};

// @lc code=end


int main(){
    Solution sol;
    vector<int> arr={3,5,7,10};
    bool out=sol.checkIfExist(arr);
    cout<<out;
    return 0;
}