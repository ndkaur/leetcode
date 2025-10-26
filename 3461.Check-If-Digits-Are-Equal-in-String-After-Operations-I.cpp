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
    bool hasSameDigits(string s) {
        int n = s.size();
        while(s.size()>2){
            string temp="";
            for(int i=1; i<s.size(); i++){
                int rem = (s[i-1]-'0' + s[i]-'0')%10;
                temp += to_string(rem);
            }
            s= temp;
        }
        if(s[0]!=s[1])
            return false;
        return true;
    }
};

int main(){

    return 0;
}