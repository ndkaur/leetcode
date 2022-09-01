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

// we can  use stack O(N) space->O(N)

// two ptrs O(n) O(1)
class Solution {
public:
    string removeStars(string s) {
        int j=0;
        for(int i=0;i<s.size(); i++){
            if(s[i]=='*'){
                j--;
            }
            else{
                s[j]= s[i];
                j++;
            }
        }
        return s.substr(0,j);
    }
};

int main(){

    return 0;
}