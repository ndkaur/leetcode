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
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }

        for(int i=0; i<n; i++){
            if(nums[i]%2==0 && mp[nums[i]]==1){
                return nums[i];
            }
        }
        return -1;
    }
};



int main(){

    return 0;
}