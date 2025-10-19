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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            long long pro =nums[i];
            if(nums[i]<k){
                cnt++;
                for(int j=i+1; j<n; j++){
                    pro *= nums[j];
                    if(pro<k){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0)
            return 0;

        int l = 0;
        int r = 0;
        int cnt = 0;
        int pro = 1;

        while(r<n){
            pro *= nums[r];
            r++;
            while(l<r && pro>=k){
                pro = pro/nums[l];
                l++;
            }
            cnt += r-l;
        }
        return cnt;
    }
};



class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k<=1)
            return 0;
        int pro =1;
        int cnt =0;
        int l =0;
        int r =0;

        while(r<n){
            pro = pro*nums[r];
            while(pro>=k){
                pro = pro/nums[l];
                l++;
            }
            cnt+= r-l+1;
            r++;
        }
        return cnt;
    }
};



int main(){

    return 0;
}