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
    int countDistinct(vector<int>& nums, int k, int p) {
        set<string> s;
        int n= nums.size();
        for(int i=0;i<n;i++){
            int count=0;
            string str="";
            for(int j=i;j<n;j++){
                str+= nums[j] +'0'; //'0' mark the end of string
                if(nums[j]%p==0)
                    count++;
                if(count<=k)
                    s.insert(str);
                else break;
            }
        }
        return s.size();
    }
};

int main(){
    Solution sol;
    vector<int> nums={2,3,3,2,2};
    int k= 2;
    int p=2;
    int ans= sol.countDistinct(nums,k,p);
    cout<<ans;
    return 0;
}