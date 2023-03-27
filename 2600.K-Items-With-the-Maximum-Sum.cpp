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
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum =0;
        while(k){
            if(numOnes){
                 while(numOnes && k){
                    sum+=1;
                    numOnes--;
                    k--;
                }
            }
            else if(numZeros){
                while(numZeros && k){
                    sum+=0;
                    numZeros--;
                    k--;
                }
            }
           else{
               while(numNegOnes && k){
                   k--;
                   sum-=1;
                   numNegOnes--;
               }
           }
        }
        return sum;
    }
};

int main(){

    return 0;
}