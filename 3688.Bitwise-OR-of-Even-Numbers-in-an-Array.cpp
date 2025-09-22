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
    int evenNumberBitwiseORs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int num:nums){
            if(num%2==0){
                ans = ans | num;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}