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
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int a,b;
        for(int i=0; i<n; i++){
            if(nums[i]==1)
                a=i;
            else if(nums[i]==n)
                b=i;
        }
        if(a<b){
            // swps for a =same 
            // swpas for b will be lenght -b
            return a+n-1-b;
        }
        else { // b>a, a is far from strting 
            return a+n-1-b-1;
        }
        
    }
};

int main(){

    return 0;
}