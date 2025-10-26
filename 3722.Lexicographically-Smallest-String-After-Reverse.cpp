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
    string lexSmallest(string s) {
        int n = s.size();
        string ans = s;
        for(int k=1; k<=n; k++){
            string temp = s;
            reverse(temp.begin(), temp.begin()+k);
            ans = min(ans, temp);

            // last 
            string str = s;
            reverse(str.end()-k, str.end());
            ans = min(ans, str);
        }
        return ans;
    }
};



int main(){

    return 0;
}