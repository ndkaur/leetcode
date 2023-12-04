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
    string largestGoodInteger(string num) {
        int n = num.size();
        int mx = -1;
        for(int i=0; i<n-2; i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                int val =  num[i]-'0'; // convert the string into num
                mx = max(mx, val);
            }
        }
        // all 3 chars are same so add the mx to the string 3 times 
        return mx!=-1 ? string(3, '0' + mx) : "";
    } 
};

int main(){

    return 0;
}