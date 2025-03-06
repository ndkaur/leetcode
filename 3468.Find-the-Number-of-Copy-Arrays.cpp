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
        int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
            int n = original.size();
            // copy[i] - copy[i-1] = or[i]-or[i-1]
            // copy[i] - copy[i-1] = diff( original array is known )
            // copy[i] = diff + copy[i-1]
            // x , x+diff , x+diff+diff,
            // copy array ->  x,     x+1,        x+2,         x+3
            // bounds->    {1,2},   {2,3},       {3,4},       {4,5} 
            // range->     1<=x<=2,  2<=x+1<=3   3<=x+2<=4    4<=x+3<=5
            // range ->    1<=x<=2,  1<=x<=2,     1<=x<=2,    1<=x<=2
            // so taking the final range , max( left) , min(right) -> 1<=x<=2 
            // no of copy arrays -> upper-lower+1 =  2-1+1 = 2
            int lower = bounds[0][0];
            int upper = bounds[0][1];
            int prevdiff = 0;
            for(int i=1; i<n; i++){
                int diff = original[i]-original[i-1];
                diff+= prevdiff;
                // updating the range
                lower = max(lower, bounds[i][0]-diff);
                upper = min(upper, bounds[i][1]-diff);
                prevdiff = diff;
            }
    
            int ans = upper-lower +1;
            return ans<0 ? 0: ans;
        }
    };
    

int main(){

    return 0;
}