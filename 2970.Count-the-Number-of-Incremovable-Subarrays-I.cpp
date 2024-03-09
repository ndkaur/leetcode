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
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                // removing i to j subarray 
                // checking remainig is increasing array 
                bool flag = true;
                int last = -1; // storing the prevv num for comparision
                // subarray can be inbetween the array so we need to check all remaining elements 
                for(int k=0; k<n; k++){
                    if(k>=i && k<=j){ // elem within subarray are skipped
                        continue;
                    }
                    if(last >=nums[k]){
                        flag = false;
                        break;
                    }
                    last = nums[k];
                }
                if(flag)
                    cnt++;
            }
        }
        return cnt;
    }
};


class Solution {
public:
    bool check(vector<int>& nums){
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i-1]>=nums[i])
                return false;
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                vector<int> temp;
                // checking the remaning array 
                for(int k=0; k<i; k++){
                    temp.push_back(nums[k]);
                }
                for(int k= j+1; k<n; k++){
                    temp.push_back(nums[k]);
                }
                if(check(temp))
                    cnt++;
            }
        }
        return cnt; 
    }
};

int main(){

    return 0;
}