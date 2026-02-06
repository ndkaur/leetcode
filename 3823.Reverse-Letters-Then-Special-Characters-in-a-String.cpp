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
    string reverseByType(string s) {
        int n = s.size();
        vector<int> alp, special;
        for(int i=0; i<n; i++){
            if(isalpha(s[i])){
                alp.push_back(s[i]);
            }
            else    
                special.push_back(s[i]);
        }

        reverse(alp.begin(), alp.end());
        reverse(special.begin(), special.end());

        string ans = "";
        int a= 0;
        int si= 0;
        for(int i=0; i<n; i++){
            if(isalpha(s[i]) && a<alp.size()){
                ans+= alp[a];
                a++;
            }
            else{
                if(si<special.size()){
                    ans+= special[si];
                    si++;
                }
            }
        }
        return ans;
    }   
};


int main(){

    return 0;
}