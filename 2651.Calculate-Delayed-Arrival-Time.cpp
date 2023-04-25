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
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int sum = arrivalTime + delayedTime;
        if(sum == 24)   
            return 0;
        else if(sum >24)
            return sum-=24;
        else 
            return sum;
    }
};

int main(){

    return 0;
}