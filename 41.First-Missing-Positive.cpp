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


// check for 1 in array if no 1 found then 1 is the ans
// nums -ve , 0 and out of range [1,n] mark them as 1 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        bool oneFound = false;
        for(int i=0; i<n; i++){
            if(nums[i]==1)
                oneFound = true;
            if(nums[i]<=0 || nums[i]>n){
                nums[i]=1;
            }
        }

        if(oneFound==false)
            return 1;

        for(int i=0; i<n; i++){
            int num = abs(nums[i]);
            int idx = num-1;
            if(nums[idx]<0)
                continue;
            nums[idx] *= -1;
        }

        for(int i=0; i<n; i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        // if all the nums in range 1->n present then return next out of range num
        return n+1;
    }
};  

int main(){

    return 0;
}