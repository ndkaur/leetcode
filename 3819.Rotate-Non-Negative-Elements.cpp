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
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> parr;

        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                parr.push_back(nums[i]);
            }
        }
        if(parr.size()==0)
            return nums;

        int rotate = k % parr.size();
        int pcnt = parr.size();
        vector<int> temp(pcnt);

        for(int i=0; i<parr.size(); i++){
            int new_idx = (i-rotate);
            if(new_idx<0){
                new_idx += pcnt;
            }

            temp[new_idx] = parr[i];
        }
        
        // now temp arr contains the +ve nums in rotated order
        int idx = 0;
        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                nums[i]= temp[idx];
                idx++;
            }
        }
        return nums;
    }
};


int main(){

    return 0;
}