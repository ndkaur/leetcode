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
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        int i =0;
        int j = 0;
        map<int,int> mp;
        long long mx = 0;
        long long sum =0;
        while(j<n){
            sum += nums[j];
            mp[nums[j]]++;
            // slide window if window len is greater than k
            while(j-i+1>k){
                mp[nums[i]]--;
                sum-= nums[i];
            
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            // if len <=k 
            if(j-i+1==k){
                // next condition = m unique chars 
                if(mp.size()>=m){
                    mx = max(mx,sum);
                }
            }
            j++;
        }
        return mx;
    }
};

int main(){

    return 0;
}