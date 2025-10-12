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
    bool isbalanced(vector<int>& freq, int cnt){
        for(int f:freq){
            if(f!=0 && f!=cnt)
                return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int mx = 0;
        // for each char we need to keep track of what all chars exist and what is the curr cnt of the char 
        for(int i=0; i<n; i++){
            vector<int> freq(26);
            for(int j=i; j<n; j++){
                int val = s[j]-'a';
                freq[val]++;
                // if all the chars in the freq arr have same freq as the  freq of the curr char then its balanced 
                if(isbalanced(freq, freq[val]))
                    mx = max(mx, j-i+1);
            }
        }
        return mx;
    }
};


// "abbac"
// "zzabccy"
// "aba"



int main(){

    return 0;
}