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

// haystack = "leetcode", needle = "leeto"
//  haystack = "sadbutsad", needle = "sad"
class Solution {
public:
    int strStr(string hay, string needle) {
        int n = hay.size();
        int m = needle.size();
        int s = 0; 
        int e = 0;
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            cnt = 0;
            if(hay[i] == needle[0]){
                s = i;
                e = i;
                // check remaining chars of needle
                for(auto ch:needle){
                    if(hay[e] != ch)
                        break;
                    cnt++;
                    e++;
                }
                if(cnt == m)
                    return i;
            }
        }
        return -1;
    }
};

int main(){

    return 0;
}