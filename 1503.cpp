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
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int time=0;
        for(int l:left){
            time=max(time,l);
        }
        //l+r=n
        //l=n-r
        for(int r:right){
            time=max(time,n-r);
        }
        return time;
    }
};
int main(){
    Solution sol;
    vector<int> left={4,7,15};
    vector<int> right={9,3,13,10};
    int n=20;
    int time=sol.getLastMoment(n,left,right);
    cout<<time;
    return 0;
}