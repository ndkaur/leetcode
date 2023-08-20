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
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        int cnt=0;
        temp.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            // find element in the array greater than target
            // when no greater number found then add curr number 
            // if greter number found replace it at its index and cnt++
            // and replacement is with wither same num or curr num of array 
            auto ub =upper_bound(temp.begin(),temp.end(),nums[i]);
            if(ub==temp.end()) {
                temp.push_back(nums[i]);
            }else{
                // finding idx of ub 
                int idx =ub-temp.begin();
                temp[idx]=min(temp[idx],nums[i]);
                cnt++;
            }
        }
        return cnt;
    }
};
        // 0 1 2 3 4 5   
// nums = [1,3,2,1,3,3]
// temp = 1 
// i=1  ub(3) no ub so add to temp = { 1 , 3 }
// i= 2 ub(2) at idx =1 of temp so replace  temp ={1,2} cnt = 1
// i=3 ub(1)  at idx =1 of temp so replace temp = { 1,1} cnt = 2 
// i=4 ub(3) no ub so add temp ={1,1,3}
// i=5 ub(3) no ub so add temp = { 1,1,3,3}
// cnt = 2

int main(){

    return 0;
}