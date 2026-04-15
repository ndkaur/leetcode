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
    int firstMatchingIndex(string s) {
        int n = s.size();
        int i =0;
        int j = n-1;
        while(i<=j){
            if(s[i]==s[j])
                return i;
            i++;
            j--;
        }
        return -1;
    }
};


int main(){

    return 0;
}