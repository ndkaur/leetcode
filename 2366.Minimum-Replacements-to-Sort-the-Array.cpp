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
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int last = nums[n-1];
        long long ans = 0;

        for(int i=n-2; i>=0; i--){
            if(nums[i] > last){
                // 3,9,3 ->9>3
                int t =  nums[i]/last;
                if(nums[i]%last!=0){ // rem exist 
                    t++;  // eg -> 9/4 = 2 and 9%4 = 1 so operation=3
                }
                // if we divide the number then the new last will be 
                // 9 -> 3,6
                last = nums[i]/t;
                ans+= t-1;
            }
            else{
                last = nums[i];
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}