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
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        // gcd * lcm = x*y 
        // lcm = x*y / lcm 
        long long int prev = nums[0];
        vector<int> ans;
        for(int i=1; i<n; i++){
            auto val = __gcd(prev, 1LL*nums[i]);
            if(val>1){
                // prev becomes the lcm 
                prev = (prev * 1LL * nums[i])/ val;
            }
            else{
                // here the problem occurs as some test cases dont pass cause we push immediately and maybe in furutre there can be next value lcm coming that could make pair with the curr pushed value 
                ans.push_back(prev);
                prev = nums[i];
            }
        }
        return ans;
    }
};

// we cant go with the simple arrporch of checking each elem and pushing it in answer cause later on we can get some value that can stisty our condition
// so we need to use a stack 


class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        // gcd * lcm = x*y 
        // lcm = x*y / lcm 
        stack<long long int> stk;
        vector<int> ans;
        stk.push(nums[0]);

        for(int i=1; i<n; i++){
            long long int num = nums[i];
            while(stk.size() && ( __gcd(stk.top(), num)>1)){
                num = (num*stk.top())/ __gcd(stk.top(), num);
                stk.pop();
            }
            stk.push(num);
        }

        while(stk.size()){
            ans.push_back(stk.top());
            stk.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};



int main(){

    return 0;
}