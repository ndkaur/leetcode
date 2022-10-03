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
    
	// O(logn)
    int countSetBits(int n){
        int c=0;
        while(n>0){
            int rmsb=n&(-n); // rightmost set bit
            n-=rmsb;
            c++;
        }
        return c;
    }
    
    int minimizeXor(int num1, int num2) {
        int c=countSetBits(num2);
        
        int x=0; // building answer by nullifying MSB's of 'num1' for 'Overall Minimum XOR'
        for(int bit=31;bit>=0;bit--){
            if((num1 & (1<<bit))>0 && c>0){
                x |= (1<<bit);
                c--;
            }
        }
        
	   // setting LSB's of 'x' so that 'count of set bits are same as num2' & keeping value of 'x' as minimum possible 
        for(int bit=0;bit<=31;bit++){
            if(c>0 && (x & (1<<bit))==0){
                x |= (1<<bit);
                c--;
            }
        }
        return x;
    }
};


int main(){
    Solution sol;
    return 0;
}