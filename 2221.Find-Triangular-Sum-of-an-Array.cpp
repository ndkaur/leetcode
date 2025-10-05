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
    int triangularSum(vector<int>& nums) {
        vector<int> temp(nums.size()-1,0);
        
        while(nums.size()!=1){
            for(int i=0; i<nums.size()-1; i++){
                int sum = nums[i]+nums[i+1];
                sum = sum%10;
                temp[i] = sum;
            }
            nums = temp;
            temp.resize(nums.size()-1);
        }
        return nums[0];
    }
};


int main(){

    return 0;
}