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
    int alternateDigitSum(int n) {
        vector<int> nums;
        while(n > 0){
            int rem = n %10;
            nums.push_back(rem);
            if(n > 0)
                n= n/10;
        }  
        // 1 2 5
        bool isplus = 1;
        int ans = 0;
        for(int i=nums.size()-1; i>=0; i--){
            if(isplus){
                ans +=  nums[i];
            }
            else{
                ans -= nums[i];
            }
            isplus = !isplus;
        }
        return ans;
    }
};

int main(){

    return 0;
}