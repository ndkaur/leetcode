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
    int distributeCandies(int n, int limit) {
        int cnt =0;
        // one = i , two = n-i , three = n-i-j
        for(int i=0; i<=min(n,limit); i++){
            for(int j=0; j<=min(n-i, limit); j++){
                int k = n-i-j; 
                if(k<=limit){
                    cnt++;
                }
            }
        }
        return cnt;
    }
}; 

// n=5 , limit= 2
// i=0 , j= 0, k = 5-0 = 5 > limit  so no 
//       j= 1 , k= 5-1 = 4 > limit so no 
//       j=2, k=5-2 = 3 > limit so no 
// i=1 , j=0  k= 5-1 =4 > limit so no 
//       j= 1, k= 5-1-1 = 3 > limit so no 
// i=1 , j= 2 , k = 5-1-2 = 2  cnt++ =>  cnt = 1  (1,2,2)
// i=2 , j=0 , k = 5-2 = 3 
// i= 2, j= 1 , k= 5-2-1 = 2  cnt = 2 (2,1,2)
// i= 2 , j= 2, k= 5-2-2 = 1  cnt =3   (2,2,1)

int main(){

    return 0;
}