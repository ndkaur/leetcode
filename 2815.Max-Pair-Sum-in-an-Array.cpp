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
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        // nums = [51,71,17,24,42]
        int mxSum = -1;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
               int num1 = nums[i];
               int num2 = nums[j];
               if(check(num1)==check(num2)){
                   mxSum= max(mxSum, num1+num2);
               }
            }
        }
        return mxSum;
    }
    
    int check(int num){ //retrun max digit 
        int n= -1;
        while(num>0){
            int rem = num%10;
            n = max(n, rem);
            num = num/10;
        }
        return n;
    }
};

int main(){

    return 0;
}