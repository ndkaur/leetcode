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
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i=0; i<n; i++){
            int str = max(0, i-nums[i]);
            for(int j=str; j<=i; j++){
                sum += nums[j];
            }
        }
        return sum;
    }
};

int main(){

    return 0;
}