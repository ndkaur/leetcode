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
    int findMinimumOperations(string s1, string s2, string s3) {
        int i=0;
        int sz = min({s1.size(), s2.size(), s3.size()});
        int sum = s1.size()+s2.size()+s3.size(); // total len 
        // count = total len  - len of commom substrings 
        if(s1[0]!=s2[0] || s1[0]!=s3[0] || s2[0]!=s3[0])
            return -1;
        
        for(int i=0; i<sz; i++){
            if(s1[i]==s2[i] && s2[i]==s3[i])
                sum = sum-3;
            else 
                break;
        }
        return sum;
    }
};

int main(){

    return 0;
}