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
    int countOperations(int num1, int num2) {
        int cnt =0;
        while(num1!=0 && num2!=0){
            if(num1>num2){
                num1 = num1-num2;
            }
            else{
                num2 = num2-num1;
                
            }
                cnt++;
        }
        return cnt;
    }
};  

int main(){

    return 0;
}