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
    int distanceTraveled(int mainTank, int addTank) {
        int ans =0;
        while(mainTank>=5 && addTank){
            ans+= 50;
            addTank--;
            mainTank-= 5;
            mainTank++; // adding 1
        }
        ans+= mainTank*10;
        return ans;
    }
};
//50+50
// 9-5 = 4+1 =5 
// 5-5 =0 


int main(){

    return 0;
}