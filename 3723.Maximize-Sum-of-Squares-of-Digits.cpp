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
    string maxSumOfSquares(int num, int sum) {
        // num= size, sum = the digits sum
        // max num we can take is 9 , if we take 9 size no of times and still cant make the sum , ie 9*size > sum then not possibel 
        if(sum>9*num)
            return "";

        string ans;
        for(int i=0; i<num; i++){
            // we want max so max can be 9 
            int digit = min(9, sum);
            // num to string digit ='0'
            ans.push_back('0'+digit);
            sum-=digit;
        }
        return ans;
    }
};


int main(){

    return 0;
}