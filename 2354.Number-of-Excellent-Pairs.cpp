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
    int setbit(int n){
        int cnt=0;
        while(n){
            cnt+= n%2;
            n= n/2;
        }
        return cnt;
    }

    long long countExcellentPairs(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        // to store the set bit of each num in nums array 
        vector<int> bits;

        for(auto& i:s){
            int x= setbit(i); // no os set bits 
            // store the set bits in array 
            bits.push_back(x);
        }
        sort(bits.begin(), bits.end());

        long long ans=0;
        // gretaer than or equal to k 
        for(int i=0;i<bits.size();i++){
            auto it = lower_bound(bits.begin(), bits.end(), k-bits[i]);
            ans+= (bits.end()- it);
        }
        return ans;
    }
};

// We find the lower_bound for k-v[i], now all the numbers to the right of the lower_bound will form an excellent pair.

// Time complexity: O(N logN)

class Solution {
public:
    int setbit(int n){
        int cnt=0;
        // 10^9 so at max 30 bits can be there 
        for(int j=29 ;j>=0;j--){
            if((1<<j)&n)
                cnt++;
        }
        return cnt;
    }

    long long countExcellentPairs(vector<int>& nums, int k) {
        int n= nums.size();
        set<int> s;
        for(auto i:nums)
            s.insert(i);
        // to store the set bit of each num in nums array 
        vector<int> bits;

        for(auto i:s){
            int x= setbit(i); // no os set bits 
            // store the set bits in array 
            bits.push_back(x);
        }
        sort(bits.begin(), bits.end());
        // now simply count the nums whose sum greater ot equal to k
        int m= bits.size();
        int l=0;
        int r= m-1;
        long long ans=0;
        while(l<m && r>=0){
            if(bits[l]+ bits[r]<k)
                l++;
            else{ // greater or equal then add
                ans += m-l;// count the remaining ele
                r--;
            }
        }
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> nums={5,1,1};
    int k= 10;
    int ans= sol.countExcellentPairs(nums,k);
    cout<<ans;
    return 0;
}