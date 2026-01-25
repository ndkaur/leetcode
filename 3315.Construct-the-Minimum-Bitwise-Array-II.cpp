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


class Solution { // O(NlogK) , k = largest num in nums
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int val = nums[i];
            if(val==2){
                ans[i]= -1;
                continue;
            }

            int cnt = 0;
            int num = val;
            while((val&1)==1){ // consecutive set bit count
                cnt++;
                val = val>>1;
            }

            // the last consecutive set bit toggle it  to 0
            // 111 = 7 , cnt = 3,  3-1 = 2 ,,, 1<<2 = 100 = 4 
            // 7-4 = 3
            int second_val = 1<<(cnt-1); 
            int first_val = num-second_val;
            ans[i] = first_val;
        }
        return ans;
    }
};


// If the binary ends in 01 (like 5 and 13), then the answer is to just subtract 1.
// If the binary consists of all 1s (like 7 and 31), the answer is to remove the leftmost 1.
// but in 11-> 1011 its ans is 1001 = 9 ie we change the last 1 in the longest consecutive chain of 1s

int main(){

    return 0;
}