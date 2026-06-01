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
    int digitFrequencyScore(int n) {
        long long sum = 0;
        map<int,int> mp;
        int val = n;
        while(val){
            int rem = val%10;
            mp[rem]++;
            val = val/10;
        }
        for(auto itr:mp){
            sum += (itr.first*itr.second);
        }
        return sum;
    }
};


int main(){

    return 0;
}