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
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k==1)
            return n;
        vector<pair<int,int>> intervals;
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int diff = 0; diff<n; diff++){
            for(int i=0, j=i+diff; j<n; i++, j++){
                if(diff == 0){
                    dp[i][j] = 1;
                }
                else if(diff == 1){
                    dp[i][j] = (s[i] == s[j]) ? 2 : 0;
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = 2 + dp[i+1][j-1];
                    }
                }
                if(dp[i][j] >= k){   
                   intervals.push_back({j,i});
                } 
            }
        }
        for(auto p:intervals){
            cout<<p.first<<","<<p.second<<endl;
            cout<<endl;
        }
        // intervals array we have , now check overlap 
        sort(intervals.begin() , intervals.end());
        int ans =0;
        int l=-1;
        for(auto p:intervals){
            if(p.second > l){
                l = p.first;
                ans++;
            }
        }
        
        return ans;
    }
};




int main(){
    Solution sol;
    // string s ="fttfjofpnpfydwdwdnns";
    string s = "abaccdbbd";
    int k = 3;
    int ans = sol.maxPalindromes(s,k);
    cout<<"value = "<<ans;
    return 0;
}