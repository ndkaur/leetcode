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
    int minMaxDifference(int num) {
        string s = to_string(num);
        string small = s;
        string large = s;
        char mx = s[0];
        char mn = s[0];
        // 1181 // 9989 //  0080
        // 90  // 99 // 00
        int  i=0;
        while(true){
            if(s[i]!='9'){ // if 0th idx is not 9 then it will break 
            // or if 0th idx is 9 then go to nxt idx and so on
                mx = s[i];
                break;
            }
            else{
                i++;
            }
        }
        replace(large.begin(), large.end(),mx,'9');
        replace(small.begin(), small.end(), mn, '0');
        return stoi(large) - stoi(small);
    }
};

int main(){

    return 0;
}