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
    int setBit(int num){
        int cnt =0;
        for(int i=31; i>=0; i--){
            if(((num>>i)&1)==1)
                cnt++;
        }
        return cnt;
    }
    bool check(vector<int>& nums){
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1])
                return false;
        }
        return true;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n);
        for(int i=0; i<n; i++){
            cnt[i] = setBit(nums[i]);
        }
        int k =0;
        while(k<n){
            for(int i=1; i<n; i++){
                if(cnt[i]==cnt[i-1] && nums[i]<nums[i-1]){
                    swap(nums[i], nums[i-1]);
                }
            }
            if(check(nums)) 
                return true;
            k++;
        }
        return false;
    }
};

int main(){

    return 0;
}