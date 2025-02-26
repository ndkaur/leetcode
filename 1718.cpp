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
public:
    bool find(int idx, int n, vector<int>& ans, vector<bool>& used){
        // reached at last index 
        if(idx==2*n-1)
            return true; 

        if(ans[idx]!=0) // already filled then move to next index
            return find(idx+1, n, ans, used);

        // greedy filling
        for(int i=n; i>=1; i--){
            if(used[i]==true)
                continue;
            
            used[i]= true;
            ans[idx]=i;
            if(i==1 && find(idx+1, n, ans, used))
                return true;

            // checking for the valid index 
            if(i>1 && (idx+i)<(2*n-1) && ans[idx+i]==0){
                ans[idx+i]=i;
                if(find(idx+1, n, ans, used))
                    return true;
                ans[idx+i] = 0;
            } 

            // if not possible , equidistance
            used[i] = false;
            ans[idx]=0;
        }
        return false;

    }
    vector<int> constructDistancedSequence(int n) {
        // each elem will occur twice only 1 will occur once
        vector<int> ans(2*n-1,0);
        vector<bool> used(n+1, false); // 0 based indexing
        // find function keeps on filling the ans array and return the boolean value
        // that bool value states that is the value we adding at the current index 
        // is it equi-distance to another elem or any other elm already present there 
        find(0, n, ans, used); 
        return ans;
    }
};

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