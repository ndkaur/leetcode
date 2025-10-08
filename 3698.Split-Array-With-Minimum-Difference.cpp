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
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> psum(n,0);
        psum[0]= nums[0];

        // but in case as {4,3} there is no common point where they are similar and return true so this approch need to be modified 
        // insted of checking left and right and then calulating the sum of left side and right side 
        // if we directly stor left usm and right sum and then take the diff its will result {4,3} for this case 
        vector<bool> left(n,0), right(n,0);
        left[0]=1;
        right[n-1]=1;

        long long tsum = nums[0];

        for(int i=1; i<n; i++){
            tsum +=nums[i];
            psum[i] = psum[i-1]+nums[i];
            if(nums[i-1]<nums[i])
                left[i]=1;
            else 
                break;
        }

        for(int i=n-2; i>=0; i--){
            if(nums[i]>nums[i+1])
                right[i]=1;
            else 
                break;
        }


        long long mn = LLONG_MAX;
        long long diff ;

        for(int i=1; i<n; i++){
            if(left[i]==1 && right[i]==1){
                // left side curr elm is added 
                long long lfirst = psum[i];
                long long rfirst = tsum-psum[i];
                diff = abs(lfirst-rfirst);
                
                mn = min(mn, diff);
                // right side cur elm is added
                
                long long lsecond = psum[i-1];
                long long rsecond = tsum-lsecond;
                diff = abs(lsecond-rsecond);
                
                mn = min(mn, diff);
            }
        }
        return mn==LLONG_MAX ? -1:mn;
    }
};



class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long n = (long long)nums.size();
        long long ans = 1e15+9;

        vector<long long> prefix(n, 1e15), suffix(n, 1e13);
        prefix[0] = nums[0];
        suffix[n-1]= nums[n-1];

        for(int i=1; i<n; i++){
            if(nums[i-1]<nums[i]){
                prefix[i] = prefix[i-1]+nums[i];
            }
            else{  // this makes sure that we only pick the subarrys 
                break;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(nums[i]>nums[i+1]){
                suffix[i] = suffix[i+1]+nums[i];
            }
            else{
                break;
            }
        }

        // when the curr value is picked up with right subaary prefix[i-1]- suf[i]
        // when the curr value is picked up with left sum then 
        // we have already shifted to next index so technically the formaula remians the same 

        for(int i=1; i<n; i++){
            ans = min(ans, abs(prefix[i-1]-suffix[i]));
        }

        return ans>1e10 ? -1: ans;
    }
};




int main(){

    return 0;
}