#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
    vector<int> used;
public:
    vector<int> constructDistancedSequence(int n) {
       vector<int> ans(2*n-1);
       used.assign(n+1,0);
       dfs(ans,0);
       return ans;
    }
    bool dfs(vector<int>&ans, int i){
        if(i==ans.size()) 
            return true;// filled all nos 
        if(ans[i]) 
            return dfs(ans, i+1); // filled then next index
        for(int j=used.size()-1;j>0;j--){
            if(used[j]) // already filled 
                continue;
            if(j!=1  && (i+j >=ans.size() || ans[i+j]))
                continue;
            used[j] =1;
            ans[i]=j;
            if(j!=1)//not filled
                ans[i+j]=j;
            if(dfs(ans,i+1))
                return true;
            ans[i]=0;
            if(j!=1)
                ans[i+j]=0;
            used[j]=0;

        }
        return false;
    }
};

int main(){
    Solution sol;
    int n=3;
    vector<int> ans=sol.constructDistancedSequence(n);
    print(ans);
    return 0;
}