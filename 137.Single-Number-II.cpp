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
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<32; i++){
            int sum = 0;
            for(int num:nums){
                int bit = (num>>i)&1;
                sum += bit;
            }
            sum = sum%3;
            ans = ans | sum<<i;
        }
        return ans;
    }
};
// 10 , 10 , 11, 10 , i=0, sum = 1
// ans = 1
// i=1, sum =4, 4%3=1  
// ans = 1 | 1<<=1 = 1|10 = 11

int main(){

    return 0;
}