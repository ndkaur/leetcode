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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n= nums.size();
        int mx =INT_MIN;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
              mx=max(mx,nums[i]);
              mn=min(mn,nums[i]);
        }
      int smx=0,smn=0;
      for(int i=0;i<n;i++){
            if(nums[i]==mx){
                  smx=i;
            }
            if(nums[i]==mn){
                  smn=i;
            }
      }
      int front= max(smx,smn)+1;
      int last = n-min(smx,smn);
      // last and front both
      int fl= (min(smx,smn)+1)+(n-max(smx,smn));
      return min(min(front,last),fl);
    }
};

int main(){
      Solution sol;
      vector<int> nums={0,-4,19,1,8,-2,-3,5};
      int ans =sol.minimumDeletions(nums);
      cout<<ans;
      return 0;
}  