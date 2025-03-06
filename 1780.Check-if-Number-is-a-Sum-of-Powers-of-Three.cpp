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
        bool checkPowersOfThree(int n) {
            // like in base 10 we convery decimal to binary by diving by 2 
            // if we divide number by 3 it will convert to base 3 
            // fo base 3 powers will be either 0, 1 or 2 
            // but when 2 occur no chance to repesent in piwer of 3
            while(n>0){
                if(n%3==2){
                    return false;
                }
                n= n/3;
            }
            return true;
        }
    };

int main(){

    return 0;
}