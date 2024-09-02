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
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long  sum = 0;
        for(auto c:chalk){
            sum+=c;
        }
        // this will help skip the extra circulations in brute force
        k= k%sum;

        for(int i=0; i<n; i++){
            if(k-chalk[i]<0)
                return i;
            else 
                k = k-chalk[i];
        }
        return n-1;
    }
}; 


int main(){

    return 0;
}