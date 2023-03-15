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

// we need to find the count of sums that are +ve.
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt =0;
        long long sum =0;
        for(int i=n-1; i>=0; i--){
            sum += nums[i];
            if(sum>0)
                cnt++;
        }
        return cnt;
    }
};

int main(){

    return 0;
}