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
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        // next greter elem -> mono decresing stack 
        vector<int> next_gre(n,-1);
        stack<int> stk;
        for(int i=0; i<n; i++){
            while(stk.size() && nums[stk.top()]<nums[i]){
                stk.pop();
            }
            if(stk.size()){
                next_gre[i]= stk.top();
            }
            stk.push(i);
        }

        // empty the stack for reuse
        while(stk.size()){
            stk.pop();
        }
        // prev greter elem->mono dec stk
        vector<int> prev_gre(n,n);
        for(int i=n-1; i>=0; i--){
            while(stk.size() && nums[stk.top()]<nums[i]){
                stk.pop();
            }
            if(stk.size()){
                prev_gre[i] = stk.top();
            }
            stk.push(i);
        }

        long long ans = 0;
        for(int i=0; i<n; i++){
            if(prev_gre[i]!=n && next_gre[i]!=-1)
                ans++;
        }
        return ans;
    }
};



class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        // next greter elem -> mono decresing stack 
        stack<int> stk;

        for(int i=0; i<n; i++){
            while(stk.size() && nums[stk.top()]<nums[i]){
                stk.pop();
                // we check size after popint because we want elemt to be remining to make the boundary 
                if(stk.size()){
                    ans++;
                }
            }
            stk.push(i);
        }

        return ans;
    }
};


int main(){

    return 0;
}