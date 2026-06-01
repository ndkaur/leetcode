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
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        int cnt =1;
        for(int i=1; i<n; i++){
            if(ans.back()==nums[i] && cnt<k){
                cnt++;
                ans.push_back(nums[i]);
            }
            else if(ans.back()!=nums[i]){
                cnt = 1;
                ans.push_back(nums[i]);
            }
            else{
                continue;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}