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
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            int cnt =0;
            int l=0;
            // suppose r ptr is standing at last indx of arry , then till how 
            // much idx it can form a valid group of length k = n+k
            int limit = n+k-1;
            while(l<n){
                int r = l+1;
                // move r till its alternating values
                while(r<limit && colors[(r-1)%n]!=colors[r%n]){
                    r++;
                }
    
                // when at idx where prev color and curr color not equal
                // and we have traveled the k length
                if(r-l>=k){
                    // total_len-k+1
                    cnt+= (r-l)-k+1;
                }
                // move the l ptr
                l=r;
            }
            return cnt;
        }
    };


int main(){

    return 0;
}