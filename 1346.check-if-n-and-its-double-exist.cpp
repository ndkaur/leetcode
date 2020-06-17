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
class Solution {
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
class Solution {
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
// @lc code=end


int main(){
    Solution sol;
    vector<int> arr={3,1,7,11};
    bool out=sol.checkIfExist(arr);
    cout<<out;
    return 0;
}