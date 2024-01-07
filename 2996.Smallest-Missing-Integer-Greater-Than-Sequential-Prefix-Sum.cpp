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
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i-1]+1==nums[i])
                sum += nums[i];
            else 
                break;
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i]==sum)
                sum++;
        }
        return sum;
    }
};

// [3,4,5,1,12,14,13]
// cntsum = 3 +4 +5= 12 
//  1 3 4 5 12 13 14 <- sort
//   12 +1 =13+1= 14 +1 =15

int main(){

    return 0;
}