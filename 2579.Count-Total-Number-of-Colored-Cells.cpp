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
        long long coloredCells(int n) {
            long long ans =1;
            int idx =1;
            for(int i=1; i<n; i++){
                ans += (4*idx);
                idx++;
            }
            return ans;
        }
    };
    
    // 1-> 1
    // 2-> 5 ->1+4
    // 3-> 13-> 1+4+8
    // 4->25 ->1+4+8+12

class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1)
            return 1;
        long long s =1;
        int i=1;
        while(n>1){
            s = s + (4*i);
            i++;
            n--;
        }
        return s;
    }
};

// 1 2 3  4
// 1 5 13 25
//  4  8  12


int main(){

    return 0;
}