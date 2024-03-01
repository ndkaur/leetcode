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
    string countAndSay(int n) {
        if(n==0)
            return "";
        string ans = "1";
        while(--n){
            string curr = "";
            for(int i=0; i<ans.size(); i++){ //11 ->21 -> 1211
                int cnt =1;
                while(i+1<ans.size() && ans[i]==ans[i+1]){
                    cnt++;
                    i++;
                }
                curr += to_string(cnt) + ans[i];
            }
            ans = curr;
        }
        return ans;
    }
};

// n= 4
// i=1   1  
// i=2, one time one-> 11
// i=3, 2 time one -> 21
// i=4, one time 2 , one time 1 = 1211 


int main(){

    return 0;
}