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
    int removeAlmostEqualCharacters(string word) {
        int n = word.size();
        int l=0;
        int r=1;
        int cnt =0;
        while(l<n && r<n){
            if(word[l]==word[r] || abs((word[l]-'a') - (word[r]-'a'))==1){
                l = r+1;
                r = r+2;
                cnt++;
            }
            else{
                l++;
                r++;
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}