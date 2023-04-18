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
    int addMinimum(string word) {
        int n= word.size();
        int ans =0;
        int i=0;
        while(i<n){
            int cnt=0;
            if(word[i] == 'a'){
                cnt++;
                i++;
            }
            if(i<n && word[i]=='b'){
                cnt++; 
                i++;
            }
            if(i<n && word[i] == 'c'){
                cnt++; 
                i++;
            }
            ans+= 3-cnt;
        }
        return ans;
    }
};

//  word = "b"
// cnt= 1
// ans = 3-1=2

// word = "aaa"
// i=0 cnt =1
// ans= 3-1 = 2
// i=1 cnt =1
// ans = 2+2 =4
// i=2 cnt of a = 1
// ans = 4 +(3-1) = 4+2 = 6

// word = abc 
// cnt= 3
// ans = 3-3 = 0

int main(){

    return 0;
}