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

// logic here is finding the maximum element and minimum element from the remaining range from the curr elem = i ie range will be i+1 , end 
// so we can before hand store the next min ele and next max elem
// (nums[i] - mnele) * mxele 
//  we can make it easy by  mnele  i mxele 
// so now the formula becomes =>  (mnele - nums[i]) * mxelem 
// in this way i<j<k will also be satisfied

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        vector<int> nextmx(n,-1);
        int nmx = INT_MIN;
        for(int i=n-2; i>=0; i--){
            nmx = max(nmx , nums[i+1]);
            nextmx[i] = nmx;
        }

        vector<int> prevmx(n,-1); 
        int pmx =INT_MIN;
        for(int i=1; i<n; i++){
            pmx = max(pmx, nums[i-1]);
            prevmx[i] = pmx;
        }

        // now using the formula  (prevmx -nums[i]) * nextmx
        // prevmx[0] =-1 and nextmx[n-1] =-1 
        // so start from i=1 till i<n-1

        for(int i=1; i<n-1; i++){
            long long curr = (long long)(prevmx[i]-nums[i])*(long long)nextmx[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};

int main(){

    return 0;
}

