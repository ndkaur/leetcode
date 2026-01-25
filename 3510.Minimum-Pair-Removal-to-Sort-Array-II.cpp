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



class Solution {//T.C : O(n * logn)
public:
    typedef long long ll;
    int minimumPairRemoval(vector<int>& numbers) {
        int n = numbers.size();
        vector<ll> nums(n);
        for(int i=0; i<n; i++){
            nums[i] = numbers[i];
        }
        // pop eaxct value from pq is tough so use set
        // priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq; // sum, idx
        set<pair<ll, int>> st;
        vector<int> prev_idx(n);
        vector<int> next_idx(n);

        for(int i=0; i<n; i++){
            next_idx[i] = i+1;
            prev_idx[i]= i-1;
        }

        int bad_pairs = 0;
        for(int i=0; i<n-1; i++){
            if(nums[i]> nums[i+1]){ // decresing order
                bad_pairs++;
            }
            st.insert({nums[i]+nums[i+1], i});
        }

        int cnt = 0;

        while(bad_pairs>0){
            // prev_curr, curr, next_curr, next_next_curr
            int curr = st.begin()->second; // min heap , min sum at top
            int next_curr = next_idx[curr];
            int prev_curr = prev_idx[curr];
            int next_next_curr = next_idx[next_curr];

            st.erase(begin(st));

            // checking if the curr pair is bad then count will decrese
            if(nums[curr]>nums[next_curr]){
                bad_pairs--;
            }

            // when new sum will be added both the left and right side will be affected 
                // checking if prev_curr  will contribute to the  bad_pair cnt or not 
            if(prev_curr>=0){
                // prev_curr, curr, next_curr, next_next_curr
                // prev_curr, (sum), next_next_curr

                // earlier it was a bad pair but now its not 
                if(nums[prev_curr]>nums[curr] && nums[prev_curr]<=nums[curr]+nums[next_curr]){
                    bad_pairs--;
                }
                // earlier its not a bad pair but now it is 
                else if(nums[prev_curr]<=nums[curr] && nums[prev_curr]> nums[curr]+nums[next_curr]){
                    bad_pairs++;
                }
            }

            // checking if  next_next_curr will contribute to the bad_pair count or not 
            // prev_curr, curr, next_curr, next_next_curr
            if(next_next_curr<n){
                // earlier not a bad pair but new sum is bad pair
                if(nums[next_curr]<=nums[next_next_curr] && nums[curr]+nums[next_curr] > nums[next_next_curr]){
                    bad_pairs++;
                }
                // earlier was a bad pair but new sum is good pair
                else if(nums[next_curr]>nums[next_next_curr] && nums[curr]+nums[next_curr]<=nums[next_next_curr]){
                    bad_pairs--;
                }
            }

            // new sums from both sides will also be removed and added  
            // prev_curr, curr, next_curr, next_next_curr
            // prev_curr, (sum), next_next_curr

            if(prev_curr>=0){
                st.erase({nums[prev_curr]+nums[curr], prev_curr});
                st.insert({nums[prev_curr]+nums[curr]+nums[next_curr], prev_curr});
            }

            if(next_next_curr<n){
                st.erase({nums[next_curr]+nums[next_next_curr], next_curr});
                st.insert({nums[curr]+nums[next_curr]+nums[next_next_curr], curr});
                prev_idx[next_next_curr] = curr;
            }

            // prev_curr, curr, next_curr, next_next_curr
            // prev_curr, (sum), next_next_curr
            next_idx[curr]= next_next_curr;
            nums[curr] = nums[curr]+nums[next_curr];

            cnt++;
        }
        return cnt;
    }
};



int main(){

    return 0;
}