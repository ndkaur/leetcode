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
    string categorizeBox(int length, int width, int height, int mass) {
        long long vol = (long long)length * (long long)width * (long long)height;
        
        bool cond1 =  (vol >= 1e9 || (length >= 1e4 || width>= 1e4 || height >= 1e4));
        bool cond2 = mass >= 100;

        if(cond1 && cond2)
            return "Both";
        else if(cond1)
            return "Bulky";
        else if(cond2)
            return "Heavy";
        else 
            return "Neither";
    }
};

int main(){

    return 0;
}