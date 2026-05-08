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
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            int val = nums[i];
            bool even = val%2==0 ? true: false;
            int cnt=0; 
            for(int j=i+1; j<n; j++){
                if(even==true && nums[j]%2!=0){
                    cnt++;
                }
                else if(even==false && nums[j]%2==0){
                    cnt++;
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};



int main(){

    return 0;
}