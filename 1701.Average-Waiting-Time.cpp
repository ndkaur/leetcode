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
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait = 0;
        double curr = 0;
        for(auto c:customers){
            // {arrival, time to prepare}
            curr = max(curr, 1.0 * c[0]) + c[1];
            wait += curr - c[0];
        }
        return 1.0 * wait / customers.size();
    }
};

// curr = 0 , max(0,1)+2 = 3, max(3, 2)+5 = 3+5 =8, max(8,4)+3 = 8+3 =11
// wait = 0, 3-1 = 2 , 8-2 = = 6 , 6+2 = 8 , 11-4 = 7+8 =15
// 15/3 = 5

int main(){

    return 0;
}