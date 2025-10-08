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
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        int i = 0;

        while(n){
            int rem = n%10;
            if(rem!=0){
                ans.push_back(rem* pow(10,i));
            }
            i++;
            n = n/10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 102  i=0
// 102%10 =2 !=0  ,  2*10^0 = 2 , i=1   {2}
// 10
// 10%10 = 0  n=1  i=2
// 1%10 = 1 , 1*10^2 = 100  {100}
// ans = {2,100} -> {100,2}


int main(){

    return 0;
}