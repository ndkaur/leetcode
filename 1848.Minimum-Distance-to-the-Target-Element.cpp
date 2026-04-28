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
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int left = start;
        int right = start;
        int mn = INT_MAX;
        while(left>=0){
            if(nums[left]==target){
                mn = min(mn, start-left);
            }
            left--;
        }
        while(right<n){
            if(nums[right]==target){
                mn = min(mn, right-start);
            }
            right++;
        }
        return mn;
    }
};

int main(){

    return 0;
}