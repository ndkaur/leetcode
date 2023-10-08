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
    int differenceOfSums(int n, int m) {
        int sum1=0;
        int sum2 =0;
        for(int i=1; i<=n; i++){
            if(i%m!=0){
                sum1+= i;
            }
            else 
                sum2+=i;
        }
        return sum1-sum2;
    }
};

int main(){

    return 0;
}