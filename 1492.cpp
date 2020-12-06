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

class Solution1 {
public:
    int kthFactor(int n, int k) {
        int count=0;
        int res;
        for(int i=1;i<n+1;i++){
            if(n%i==0){
                count++;
                if(count==k)
                    return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for(int i=2; i*i<=n ;i++){
            if(n%i==0){
                int f1=i;
                int f2=n/i;
                factors.push_back(f1);
                if(f1!=f2)
                    factors.push_back(f2);
            }
        }
        factors.push_back(1);
        factors.push_back(n);
        sort(factors.begin(),factors.end());
        if(k>factors.size())
            return -1;
        return factors[k-1];
    }
};



int main(){
    Solution sol;
    int n=12;
    int k=3;
    int ans=sol.kthFactor(n,k);
    cout<<ans;
    return 0;
}