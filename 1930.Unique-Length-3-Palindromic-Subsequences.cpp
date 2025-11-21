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


class Solution { // time-> O(N)
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        // we store first and last occurence of each char then find the unique chars inbetween that first and last occurence 
        vector<int> first(26,-1);
        vector<int> last(26,-1);

        for(int i=0; i<n; i++){
            if(first[s[i]-'a']==-1){
                first[s[i]-'a']=i;
            }
            last[s[i]-'a']=i;
        }

        int ans = 0;
        // counting unique char inbetween first ans last occurence of each char
        for(int i=0; i<26; i++){ // char 
            unordered_set<char> distinct;
            for(int j=first[i]+1; j<last[i]; j++){
                distinct.insert(s[j]);
            }
            ans+= distinct.size();
        }
        return ans;
    }
};

int main(){

    return 0;
}