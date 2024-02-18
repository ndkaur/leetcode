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
    bool check(string& word1, string& word2){
        int n = word1.size();
        int m = word2.size();
        if(word1==word2.substr(0, n) && word1==word2.substr(m-n))
            return true;
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt= 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(check(words[i], words[j])==true){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


int main(){

    return 0;
}