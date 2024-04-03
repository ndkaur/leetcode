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
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int mx = 0;
        int empty = 0;
        while(numBottles>0 || empty>=numExchange){
            if(empty>=numExchange){
                // we exchange complete value and get 1 full bottle and increse exchange value by 1 and reduce empty bottle
                empty -= numExchange;
                numExchange++;
                numBottles++;
            }
            mx += numBottles;
            empty += numBottles;
            numBottles= 0;
        }
        return mx;
    }
};


class Solution {
public:
    int maxBottlesDrunk(int nb, int ne) {
        int mx = 0;
        while(nb>=ne){
            ans+=ne;
            nb-=ne;
            nb++;
            ne++;
        }
        ans += nb;
        return ans;
    }
};


// numBottle = 13,  numExchange = 6

// mx = 13 +2= 15
// empty = 13 , 13-6 = 7 , 7-7 = 0 + 2 = 2
// numBottles = 0, 1 , 0 , 1 , 0
// numExchange = 6, 7 , 8



int main(){

    return 0;
}