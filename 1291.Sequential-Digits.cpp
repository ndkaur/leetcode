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
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums = {12,23,34,45,56,67,78,89,
                            123,234,345,456,567,678,789,
                            1234,2345,3456,4567,5678,6789,
                            12345,23456,34567,45678,56789,
                            123456,234567,345678,456789,
                            1234567,2345678,3456789,
                            12345678,23456789,
                            123456789};
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(low<=nums[i] && nums[i]<=high)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};


class Solution1 {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i=1; i<=9; i++){
            q.push(i);
        }
        vector<int> ans;
        while(q.size()){
            int val = q.front();
            q.pop();
            if(low<=val && val<=high){
                ans.push_back(val);
            }

            if(val>high)
                break;
            
            int rem = val%10;
            if(rem<9){
                int num = val*10 + (rem+1);
                q.push(num);
            }
        }
        return ans;
    }
};


class Solution {
public:
    void dfs(int low,int high,int i,int num, vector<int>& ans){
        if(num>=low && num<=high){
            ans.push_back(num);
        }

        if(num>high || i>9){
            return;
        }

        dfs(low,high,i+1,num*10+i, ans);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        // 1 , 12  , i , next num = num*10+i+1
        // 2 , 23
        for(int i=1;i<=9;i++){
            dfs(low,high,i,0, ans);  
        }

        sort(ans.begin(),ans.end());
        return ans;   
    }
};


int main(){

    return 0;
}