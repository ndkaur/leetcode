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
    string findLatestTime(string s) {
        int n = s.size();

        if(s[0]=='?'){
            if(s[1]=='?'){
                s[0]='1';
                s[1]='1';
            }
            else if(s[1]!='?'){ // ?0 , ?1 = 10, 11 
                if(s[1]=='0' || s[1]=='1'){
                    s[0]='1';
                }
                else{ // ?5, ?9 = 05,09
                    s[0]='0';
                }
            }
        }

        if(s[1]=='?'){ // 1? , 0?
            if(s[0]=='0'){ // 0? -> 09
                s[1]='9';
            }
            else{ //s[0]= 1 ,  1? 11
                s[1]='1';
            }
        }

        if(s[3]=='?'){
            s[3] = '5';
        }
        if(s[4]=='?'){
            s[4]= '9';
        }
        return s;
    }
};

int main(){

    return 0;
}