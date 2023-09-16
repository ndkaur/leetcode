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
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int j =(n+1)/2;
        while(i<n/2 && j<n){
            if(nums[i]<nums[j]){
                nums[i]=0;
                nums[j]=0;
            }
            i++;
            j++;
        }
        int cnt =0;
        for(int num:nums){
            if(num!=0)
                cnt++;
        }
        return cnt;
    }
};



int main(){

    return 0;
}