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
    int minimumCost(vector<int>& nums) {
       int n = nums.size();
        if(n==3)
            return nums[0]+nums[1]+nums[2];
        int sum =0;
        sum +=nums[0];
        vector<int> temp;
        for(int i=1; i<n; i++){
            temp.push_back(nums[i]);
        }
        sort(temp.begin(), temp.end());
        sum+=temp[0];
        sum+=temp[1];
        return sum;
    }
};






int main(){

    return 0;
}