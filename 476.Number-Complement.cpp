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
    int findComplement(int num) {
        int i = 0;
        int temp = num;
        // we have to apply the xor operation = length of the num times
        // so to keep track of len we use temp and keep on reducing it in each iteration 
        // i keeps track of the bit we want to check if set or not 
        // xor with 1 check if the bit is 1 then it becomes 0  -> 1^1 = 0
        // 1^0 = 1

        while(temp!=0){
            temp >>= 1;
            num = num ^ (1<<i);
            i+=1;
        }
        return num;
    }
};


class Solution { 
public:
    int findComplement(int num) {
        //  num = 101 we want 10
        // xor    111 
                // 10 
        int mask = 0;
        // we want mask to be of size num
        for(int temp= num; temp; temp>>=1){
            mask = (mask<<1) | 1;
        }
        return mask^num;
    }
};

//5 -> 101 = 10 , 1 , 0
// 101 ^ 1 = 100, 100^10= 110  , 110 ^ 100 = 010 




int main(){

    return 0;
}