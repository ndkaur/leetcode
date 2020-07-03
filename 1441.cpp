#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        n =target.back();
        vector<string> out;
        for(int i=1,j=0;i<=n;i++){
            if(i==target[j]){
                out.push_back("Push");
                j++;
            }
            else{
                out.push_back("Push");
                out.push_back("Pop");
            }
        }
        return out;
    }
};

int main(){
    Solution sol;
    vector<int> target={1,2,3};
    int n=3;
    vector<string> out= sol.buildArray(target,n);
    for(auto x:out){
        cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}