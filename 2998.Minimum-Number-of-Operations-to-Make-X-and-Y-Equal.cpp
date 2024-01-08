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
    int f(int x, int y, vector<int>& dp){
        if(x<=y)
            return y-x;
        
        if(dp[x]!=-1)
            return dp[x];
        
        // case 1
        int mn = abs(x-y); // inc or decrement 

        // case2  
        // when the mupltiple of 5 is smaller than x 
        // then 1 operation to divide xby 5 + the reaminder number of operations
        // eg -> x = 27 and we think of 25 so  1+ (27%5) = 1+2 = 3 
        // when we use 3 operations ie decrement 27 by 3 we get 25 so then use f(25)
        mn = min(mn, 1 + x%5 + f(x/5, y, dp)); 

        // case 3 
        // when we think of multiple larger than x 
        // eg-> x= 26 and we think of 30 
        //we need to increment x to reach to 30
        // so to make 26 -> 30 we need to add 4 -> 26+4 = 30
        // and 4 can be made using 5-(1) = 5 - (x%5)  
        // and +1 for the division operation 
        //  eg->x =52 , we think of 55  so 1 + 3 + (52/5 +1 )
        // 52/5 =10  and 52%5 = 2  but we made 52 by adding 3 as 55 so 55/5 = 11 then check for f(11) , to make our x = 11 add +1
        mn = min(mn, 1 + (5-(x%5)) + f(x/5+1 , y, dp));

        // case 4
        // we think of multiple of 11 smaller than x
        // eg-> x= 25 , multiple = 22  
        mn = min(mn, 1+ (x%11) + f(x/11, y, dp));

        //  case 5
        // we think of multiple greater than x
        // eg-> x= 26 , multiple= 33 
        // so we need to increment 26 to 33 by 33-26 = 7 
        // how to get 7 -> (11 - 26%11 )= 11 - 4 = 7
        mn = min(mn, 1 + (11-(x%11)) + f(x/11 + 1, y, dp));
       
        return dp[x] = mn;
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        vector<int> dp(1e4+1, -1);
        return f(x, y, dp);
    }
};

// x<y simply the diff will be the answer
// direcly divisible by 5 

// multiple of 5 which are smaller than x  -> increment
// x = 27 -> multiple of 5 smaller than 27 is 25 
// we need to subtract the reminder -> 27%5 + 1 = 2+1 = 3 operations

// multiple of 5 which are greater than x -> decrement
// directly divisible by 11
// multiple of 11 whoch are smaller than x -> increment
// multiple of 11 which are greater than x -> decrement



int main(){

    return 0;
}