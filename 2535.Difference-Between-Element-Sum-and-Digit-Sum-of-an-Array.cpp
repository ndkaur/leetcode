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
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int esum = 0;
        for(int num:nums){
            esum += num;
        }
        int dsum =0;
        for(int i=0; i<n; i++){
            if(nums[i] > 9){
                int num = nums[i];
                while(num){
                    int rem = num % 10;
                    dsum += rem;
                    if(num > 0)
                        num = num / 10;
                }
            }
            else {
                dsum += nums[i];
            }
        }
        return abs(dsum -esum);
    }
};

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int esum = 0;
        int dsum =0;
        for(int i=0; i<n; i++){
            esum += nums[i];
            while(nums[i]){
                dsum += nums[i] % 10;
                if(nums[i] > 0)
                    nums[i] = nums[i] / 10;
            }
        }
        return abs(dsum -esum);
    }
};

int main(){

    return 0;
}