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
    bool isSubstringPresent(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        // abcba
        // abcba
        // leetcode
        // edocteel
        int len = 0;
        for(int i=0; i<s.size()-1; i++){
            for(int j=0; j<temp.size()-1; j++){
                if(s[i]==temp[j] && s[i+1]==temp[j+1]){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){

    return 0;
}