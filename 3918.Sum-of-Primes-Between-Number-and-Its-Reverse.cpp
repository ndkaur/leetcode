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
    int find(int n){
        int temp = 0;
        while(n){
            int rem = n%10;
            temp = temp*10+rem;
            n = n/10;
        }
        return temp;
    }
    bool isPrime(int val){
        if(val==1)
            return false;
        for(int i=2; i<=val/2; i++){
            if(val%i==0)
                return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int rev = find(n);
        int sum =0;
        for(int i=min(n,rev); i<=max(n,rev); i++){
            if(isPrime(i)){
                sum+=i;
            }
        }
        return sum;
    }
};



int main(){

    return 0;
}