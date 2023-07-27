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
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        for(int i=1; i<=n-1; i++){
            if(i==n-1 && mp[i]!=2)
                return false;
            else if(i!=n-1 && mp[i]!=1)
                return false;
        }
        if(mp.size()!=n-1)
            return false;
        return true;
    }
};

int main(){

    return 0;
}