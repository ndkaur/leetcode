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
    int minimumArrayLength(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
//         1 1 3 4
        if(n>2 && nums[0]!=nums[1])
            return 1;
//         g=1, 
        int g = nums[0];
        for(int num:nums){
            g = __gcd(g,num);
        }
        int cnt = 0;
        for(int num:nums){
            if(num==g) // 1==1
                cnt++;
        }
        return max(1,(cnt+1)/2);
    }
};



int main(){

    return 0;
}