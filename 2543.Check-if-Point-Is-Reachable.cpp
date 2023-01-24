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
    bool isReachable(int targetX, int targetY) {
        int common = __gcd(targetX, targetY);
        while(common % 2 == 0){
            common = common / 2;
        }
        return common == 1;
    }
};

// (x, y - x)
// (x - y, y)
// (2 * x, y)
// (x, 2 * y)
// according to the conditions if we reverse them 
// (x, y + x)
// (x + y, y)
// (x / 2, y) if x % 2 == 0
// (x, y / 2) if y % 2 == 0
// divisible by 2 must be true 
// so find the commom factor and check if it is divisible by true
// if divisible then in the end the result returned will be 1 
// so find gcd then check if that factor is completely divisible by two 
// if so and ans is 1 so return true or return false;


int main(){

    return 0;
}