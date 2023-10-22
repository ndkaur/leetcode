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
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int sum =INT_MAX;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]< nums[j] && nums[k]<nums[j]){
                        int s = nums[i]+nums[j]+nums[k];
                        sum = min(s, sum);
                    }
                }
            }
        }
        return sum==INT_MAX ? -1 : sum;
    }
};

int main(){

    return 0;
}