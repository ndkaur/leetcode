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
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        bool allzero = true;
        for(int num:nums){
            xorr ^= num;
            if(num!=0)
                allzero = false;
        }

        if(allzero==true)
            return 0;
        
        if (xorr!=0)
            return n;
        if(n>1)
            return n-1;
        return 0;
    }
};



int main(){

    return 0;
}