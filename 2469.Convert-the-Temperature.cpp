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
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        double k = celsius + 273.15;
        double f = celsius * 1.80 + 32.00;
        ans = {k,f};
        return ans;
    }
};


int main(){

    return 0;
}