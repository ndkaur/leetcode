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
    bool scoreBalance(string s) {
        int n = s.size();
        int total = 0;
        for (char c : s)
            total += c-'a' + 1;
        
        int leftSum = 0;
        for (int i = 0; i<n-1; i++) {
            leftSum += s[i] - 'a' + 1;
            int rightSum = total - leftSum;
            if (leftSum == rightSum)
                return true;
        }
        return false;
    }
};


int main(){

    return 0;
}