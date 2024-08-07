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

// n = 4, time = 5  ans = 2
// 1 2 3 4 3 2 1 -> sz = 7
// n = 3, time = 2 ans = 3

class Solution {
public:
    int passThePillow(int n, int time) {
        int idx = 1;
        int dir = 0; // forward
        while(time){
            if(dir == 0)
                idx++;
            else 
                idx--;
            
            if(idx == n) // reached end reverse dir
                dir = 1;
            else if(idx == 1) // in the begining forward dir
                dir =0;
            time--;
        }
        return idx;
    }
};

class Solution {
public:
    int passThePillow(int n, int time) {
        // we have n but we can only jump n-1 times
        int round = time/(n-1);
        int ans = 0;

        if(round%2==0){ // not reverse so 1+time
            ans = 1 + (time%(n-1));
        }
        else{ // reverse jums so n- time
            ans = n-time%(n-1);
        }
        return ans;
    }
};

int main(){

    return 0;
}