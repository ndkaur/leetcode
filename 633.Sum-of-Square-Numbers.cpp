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


class Solution { // time = O(Sqrt(C))
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = sqrt(c);
        while(left<=right){
            long cur = left*left + right*right;
            if(cur<c){
                left++;
            }
            else if(cur>c){
                right--;
            }
            else
                return true;
        }
        return false;
    }
};


int main(){

    return 0;
}