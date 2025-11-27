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
    int smallestRepunitDivByK(int k) {
        int i = 1 % k;
        int len = 1;

        while(i%k!=0){
            i= (i*10+1)%k;
            len++;
            if(len>k)
                return -1;
        }

        if(len==1 && (1 % k!=0))
            return -1;

        return len;
    }
};

int main(){

    return 0;
}