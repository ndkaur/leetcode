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
    int find(int n){
        if(n==0 || n==1)
            return 1;
        
        return n*find(n-1);
    }
    int trailingZeroes(int n) {
        int fact = find(n);
        int cnt=0;
        while(fact){
            if(fact%10==0)
                cnt++;
            else 
                break;
            fact = fact/10;
        }
        return cnt;
    }
};


class Solution {
public:
    int trailingZeroes(int n) {
        int cnt =0;
        // first trialing zero fact begins from 5
        for(long long i=5; n/i; i=i*5){
            cnt += n/i;
        }
        return cnt;
    }
};

int main(){

    return 0;
}