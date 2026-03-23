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
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        vector<long long> arr(n);
        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
            long long g = __gcd(nums[i], mx);
            arr[i] = g;
        }
        sort(arr.begin(), arr.end());
        int i = 0;
        int j = n-1;
        long long sum  = 0;

        while(i<j){
            long long val = __gcd(arr[i], arr[j]);
            sum += val;
            i++;
            j--;
        }
        return sum;
    }
};


int main(){

    return 0;
}