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
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n= nums.size();
        int m= queries.size();

        sort(nums.begin(), nums.end());

        vector<int> ans(m,0);
        vector<int> pref;

        int sum=0;
        for(int i=0; i<n; i++){
            sum+= nums[i];
            pref.push_back(sum);
        }
        
        for(int i=0; i<m; i++){
            for(int j=0;j<n; j++){
                if(pref[j] <= queries[i]){
                    ans[i] = j+1;
                }
                else 
                    break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> answerQueries(vector<int>& a, vector<int>& b) {
        vector<int>ans;
        // Required maxium size that's why it need to sorted (lower value come first).          
        sort(a.begin(),a.end());
        //question required return size of sum so need to calculate Prefix sum for 
        for(int i=1;i<a.size();i++){
            a[i]=a[i]+a[i-1];
        }
        
        for(int i=0;i<b.size();i++){
            //upper bound => It always return just upper index (if answer exits or not). 
            int ind = upper_bound(a.begin(),a.end(),b[i])-a.begin();
            ans.push_back(ind);
        }
        return ans;
    }
};

int main(){

    return 0;
}