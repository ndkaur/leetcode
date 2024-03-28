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


// if we observe we need to find exactly k integers subarrays 
// but if we see finding subarray with atmost k intergers is much easier 
// and we know a trick which is atmost(k)-atmost(k-1) == k 
// atmost stands for less or equal to the given valuse of k 
// how we reached the conclusion of using atmost approach 
//  in a subarray that we picked it can be possible that it has some smaller 
// subarrays of len maybe 2 3 ....k  so we need to consider that also 
// but if we use diredt sliding window apparoach then its not possible to include those 


class Solution {
public:
    int findAtmost(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int cnt = 0;
        map<int,int> mp;

        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k){
        return findAtmost(nums, k) -  findAtmost(nums, k-1);
    }
};



int main(){

    return 0;
}