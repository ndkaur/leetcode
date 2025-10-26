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
    long long removeZeros(long long n) {
        long long ans=0;
        while(n){
            long long rem = n%10;
            if(rem!=0)
                ans = ans*10+rem;
            n = n/10;
        }
        string temp = to_string(ans);
        reverse(temp.begin(), temp.end());
        return stoll(temp);
    }
};


int main(){

    return 0;
}