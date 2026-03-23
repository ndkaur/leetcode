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
    int countCommas(int n) {
        string temp = to_string(n);
        int sz = temp.size();
        if(sz<4)
            return 0;
        int ans= 0;
        // while(sz>=4){
        //     int new_sz = sz;
        //     new_sz--;
        //     string val ="1";
        //     while(new_sz){
        //         val+="0";
        //         new_sz--;
        //     }
        //     int num= stoi(val);
        //     ans = abs(n-num)+1;
        //     sz--;
        // }
        ans = abs(n-1000)+1;
        return ans;

    }
};

// 10^5 -> 1

int main(){

    return 0;
}