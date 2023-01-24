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
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long n = nums1.size();
        long  long ans = 0;
        // we want min of nums2 but if we take all maximums and use the minimium among those maxs -> that will give us max ans
        vector<pair<int,int>> nums(n);
        for(int i=0; i<n; i++){
            nums.push_back({nums2[i], nums1[i]});
        }
        // sorting acc to max of nums2
        sort(rbegin(nums), rend(nums));
        priority_queue<int, vector<int>, greater<int>> pq;
        
        long long sum =0;
        for(int i=0; i<n; i++){
            pq.push(nums[i].second); // nums1
            sum += nums[i].second;

            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){ // exact size equal to k 
                ans = max(ans, sum * nums[i].first);
            }
        }
        return ans;
    }
};

// Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
//  nums = {(2,1) , (1,3) , (3,3) , (4,2)}
// sort acc to descending order ->  {(4,2) , (3,3), (2,1), (1,3)}
// pq -> 1 2 3 
//  sum -> 2 + 3 + 1 
//  pq size == k  so ans = 6* 1 = 6
// pq->  1 2 3 3
// sum -> 6+1 = 7  
// pq size > k so pq.pop  , and sum - num = 7 -1 =6
// pq- > 2 3 3
// sum = 6  
// p size == k 
// 6* min  6 * 2 = 12 ans 

int main(){

    return 0;
}

