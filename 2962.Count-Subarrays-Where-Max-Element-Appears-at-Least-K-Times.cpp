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
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        long long cnt = 0;
        long long ans = 0;

        while(j<n){
            if(nums[j]==mx){
                cnt++;
            }
            // we want number of subaarys not the len 
            while(cnt>=k){ 
                // valid window then remianing elements will also contribute to the count of the number of subarrays cause its atleast mentioned 
                ans += n-j; // then all the reamining elem will also be valid 
                if(nums[i]==mx){
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int l = 0;
        int r = 0;
        int mxcnt = 0;
        long long ans =0;
        while(r<n){
            if(nums[r]==mx){
                mxcnt++;
            }
            while(mxcnt>=k){
                if(nums[l]==mx){
                    mxcnt--;
                }
                l++;
            }
            ans += l;
            r++;
        }
        return ans;
    }
};

int main(){

    return 0;
}