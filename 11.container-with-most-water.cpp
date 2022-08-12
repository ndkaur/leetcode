 /*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
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

// @lc code=start

// we need to find the min height and multiply it with the number of lines inbetween the two ptrs 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int left =0;
        int right= n-1;
        int mx=0;
        while(left<right){
            int w= right-left; // no of lines in between 
            int h= min(height[left],height[right]); // min height from both lines of ptrs 
            int area= w*h; // area 
            mx= max(mx,area); // storing the max area 
            if(height[left]>height[right])
                right--;
            else if(height[left]<height[right])
                left++;
            else{
                left++;
                right--;
            }
        }
        return mx;     
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> height={1,8,6,2,5,4,8,3,7};
    int ans = sol.maxArea(height);
    cout<<ans;
    return 0;
}