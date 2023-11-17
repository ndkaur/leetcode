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
    #define ll long long
    long long distributeCandies(int n, int limit) {
        long long cnt = 0;
        for(int i=0; i<=min(n,limit); i++){
            // i  = first child
            ll rem = n-i;
            // we will divide rem into two parts and if both of the parts are less thna or equal to limit then possible , so limit * limit < rem not possible  
            if(rem>2*limit)
                continue;
            // j = candies given to 2nd child 
            ll jmx = min((ll)limit, rem);
            // now after giving candies to 2nd child rem candies will change 
            rem = rem - jmx;
            // now give candies to 3rd child if the rem is in limit ie total-rem = j-rem
            // so we can direcly calculate the number of premutaions of the distribution 
            ll k =  jmx-rem +1;

            cnt += max(0ll, k);
        }
        return cnt;
    }
};

int main(){

    return 0;
}