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
    int mn = 1e9;
    int check(vector<int> temp){
        sort(temp.begin(), temp.end());
        return temp.back()-temp[0];
    }
    void dfs(int idx,int n, int k, vector<int>& ans, vector<int>& temp){
        // reducing n and k so that we done need to mainting the running product 
        if(k==0){ // all numbers of k size are taken
            if(n==1 && check(temp)<mn){ // the product is made using k nums and its the min 
                mn = check(temp);
                ans= temp;
            }
            return;
        }

        // finding the factors and reducing the target product
        for(int i=idx; i<=n; i++){
            if(n%i==0){
                temp.push_back(i); // factor found
                dfs(idx, n/i, k-1, ans, temp);
                // backtrack if factor not possible 
                temp.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k) {
        vector<int> ans;
        vector<int> temp;
        dfs(1,n,k,ans, temp);
        return ans;
    }
};

// difference of 3 nums that are factors should be the maximum among the 3 numbers but minimum among all the possible pairs 

//{1,2,4,11,22}


int main(){

    return 0;
}