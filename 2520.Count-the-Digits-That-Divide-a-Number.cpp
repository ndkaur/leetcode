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
    int countDigits(int num) {
        int cnt=0;
        int n = num;
        
        while(num != 0){
            int rem = num % 10;
            if(n % rem == 0)
                cnt++;
            if(num > 0)
                num = num / 10;
        }
        return cnt;
    }
};

int main(){

    return 0;
}