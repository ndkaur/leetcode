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
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        
        while(numBottles >= numExchange){
            ans += numBottles/numExchange;
            int rem = numBottles%numExchange; 
            numBottles = (numBottles/numExchange) +  rem;
        }
        return ans;
    }
};


class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};

// 3 + 3 + 3 + 3 + 1  
// 15 + 3 + 1

int main(){

    return 0;
}