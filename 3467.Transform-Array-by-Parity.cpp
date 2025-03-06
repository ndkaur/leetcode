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
        vector<int> transformArray(vector<int>& nums) {
            int n = nums.size();
            // even = 0, odd = 1
            int even = 0;
            int odd = 0;
            for(int i=0; i<n; i++){
                if(nums[i]%2==0){
                    even++;
                }
                else 
                    odd++;
            }
    
            vector<int> ans;
            while(even--){
                ans.push_back(0);
            }
            while(odd--){
                ans.push_back(1);
            }
            return ans;
        }
    };

int main(){

    return 0;
}