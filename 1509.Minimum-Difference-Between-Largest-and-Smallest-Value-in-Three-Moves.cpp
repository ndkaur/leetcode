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
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // 0 1 5 10 14 
        if(n<=4){
            return 0; // cause do 3 operations make all elem equal to one elm 
        }
        // we need diff bt min and max elem 
        // if we change 14 to 0 , 0 1 5 10 0 max elm will change so it will not help 
        // we will change elem to the next elem of it 

        //1) change all first 3 small elems change them to 4th elem
        //  0 1 5 10 14 => 10 10 10 10 14 , mx-mn = 14-10 =4
        int ans = nums[n-1] - nums[3];

        // 2) change all last 3 big elm with last 4th elem 
        // 0 1 5 10 14  => 0 1 1 1 1  , mx- mn = 0-1 =1  
        ans = min(ans, nums[n-4]-nums[0]);
        
        //3) change 2 small elem (0)(1) to (2), 1 big elem (n-1) to (n-2)  
        // 0 1 5 10 14  =>  5 5 5 10 10 , mx- mn = 10-5 = 5 
        ans = min(ans, nums[n-2]-nums[2]);

        //4) change 1 small elm (0) to (1) and 2 big elm (n-1)(n-2) to (n-3)
        // 0 1 5 10 14 => 1 1 5 10 10 , mx- mn = 10 -1 = 9 
        ans = min(ans, nums[n-3]-nums[1]);

        return ans;
    }
};




int main(){

    return 0;
}