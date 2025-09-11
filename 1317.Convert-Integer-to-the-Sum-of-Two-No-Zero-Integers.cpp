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
    bool check(int num){
        while(num){
            int rem = num%10;
            if(rem==0)
                return true;
            num = num/10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        int first = 1;
        int second = n-first;
        while(check(first) || check(second)){
            first++;
            second = n-first;
        }
        return {first, second};
    }
};


int main(){

    return 0;
}