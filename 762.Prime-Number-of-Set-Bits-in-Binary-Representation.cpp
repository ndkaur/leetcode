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
    int cntSetBit(int num){
        int cnt =0;
        for(int i=0; i<32; i++){
            if(num & (1<<i))
                cnt++;
        }
        return cnt;
    }
    
    bool isPrime(int num){
        if(num<=1)
            return false;
        for(int i=2; i<=num/2; i++){
            if(num%i==0)
                return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i=left; i<=right; i++){
            int setBit = cntSetBit(i);
            if(isPrime(setBit)){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}