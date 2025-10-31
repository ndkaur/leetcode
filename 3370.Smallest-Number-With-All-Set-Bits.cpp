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


class Solution0 {
public:
    bool check(int num){
        while(num>0){
            if((num&1)==0)
                return false;
            num= num>>1;
        }
        return true;
    }
    int smallestNumber(int n) {
        for(int i=n; i<=1023; i++){
            if(check(i)){
                return i;
                break;
            }
        }
        return 0;
    }
};


class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0;
        int i =0;
        while(n>0){
            // keep on seting the bits 
            ans = ans | (1<<i);
            i++;
            n = n>>1;
        }
        return ans;
    }
};

int main(){

    return 0;
}