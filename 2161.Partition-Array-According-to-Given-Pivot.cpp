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


class Solution0 {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n = nums.size();
            vector<int> ans;
            vector<int> small, great;
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(nums[i]<pivot){
                    small.push_back(nums[i]);
                }
                else if(nums[i]>pivot){
                    great.push_back(nums[i]);
                }
                else{
                    cnt++;
                }
            }
            for(int i=0; i<small.size(); i++){
                ans.push_back(small[i]);
            }
            while(cnt--){
                ans.push_back(pivot);
            }
            for(int i=0; i<great.size(); i++){
                ans.push_back(great[i]);
            }
            return ans;
        }
    };
    
    
    class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n = nums.size();
            vector<int> ans(n,0);
            int left =0;
            int right = n-1;
    
            for(int i=0, j=n-1; i<n; i++,j--){
                if(nums[i]<pivot){
                    ans[left] = nums[i];
                    left++;
                }
                if(nums[j]>pivot){
                    ans[right] = nums[j];
                    right--;
                }
            }
    
            while(left<=right){ // equal values
                ans[left] = pivot;
                left++;
            }
            return ans;
        }
    };


int main(){

    return 0;
}