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
    int countWays(vector<int>& nums) {
        int n = nums.size();
        //selected and the total number of selected students is strictly greater than nums[i].
        //not selected and the total number of selected students is strictly less than nums[i].
        sort(nums.begin(), nums.end());
        int cnt =0;
        
        if(nums[0]>0){
            cnt++;
        }
        // select->  i+1 > nums[i]
        // not -> i+1 < nums[i]
        
        for(int i=0; i<n; i++){
            if(i+1 > nums[i] && (i+1)<n && nums[i+1]>(i+1)){ // cases when select
                cnt++;
            }
            else if(i+1 > nums[i] && (i+1)==n){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}