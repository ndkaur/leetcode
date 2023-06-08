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
    string removeTrailingZeros(string num) {
        int n = num.size();
        string ans;
        int i =n-1;
        while(i>=0 && num[i]-'0'==0){
            i--;
        }
        int j =0;
        // or just take out the substring (0,i+1)
        while(j<=i){
            ans+=num[j];
            j++;
        }
        return ans;
    }
};

int main(){

    return 0;
}