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
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0;
        long long result = 0;
        for (int index = 0; index < nums.size(); ++index) {
            sum += nums[index];
            result = max(result, (sum + index) / (index + 1));
        }
        return (int) result;
    }
};


class Solution {
public:
    bool isPossible(vector<int>& nums, int mid){
        int n = nums.size();
        long ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i]>mid){ // nums[i]>mx so we need to decrese 1 this cnt times
                long cnt = (nums[i]-mid);
                if(cnt>ans)
                    return false;
                ans = ans - cnt;
            }
            else  // nums[i] < mid, so increase nums[i] by cnt no of times
                ans += (mid-nums[i]);
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = 1e9;
        int ans = 0;
        while(l<=h){
            int mid=  l+(h-l)/2; 
            // mid is like the max value we are sending 
            if(isPossible(nums, mid)){
                ans = mid;
                h = mid-1;
            }
            else 
                l = mid+1;
        }
        return ans;
    }
};

int main(){

    return 0;
}