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


class Solution0 { // tle
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());

        int cnt =0;
        for(auto itr:st){
            int val = itr;
            if(val==0)
                continue;

            bool found = true;
            for(int i=0; i<n; i++){
                if(nums[i]==val){
                    // if no min val found then we can make it 0 in one move only 
                    if(found==true){// smaller found so need a diffrent cnt for it 
                        found = false;
                        cnt++;
                    }
                } 
                else if(nums[i]<val){
                    found = true;
                }    
            }
        }
        return cnt;
    }
};

// we only add a new cnt when a new smaller elem is found as compared to our current elem 
// so what if we maintian a monotonic stack that store the next smaller elem index
// next smaller elem -> break condition should be when smaller found -> stk.top()>next elm
// incresing stack -> a<b<c next elm is greater but breaks when next elm is smaller 

class Solution { 
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        stack<int> stk;

        for(int i=0; i<n; i++){
            // break condition -> when smaller elem is found then the curr elm 
            // new smaller found then for that number we make it as a sperate subarray and we have alredy added its count and when its same occurence value comes we will increase the cnt ,  but the same curr elm exist then it will be considered the part of the same subarray 
            while(stk.size() && stk.top()>nums[i]){
                stk.pop();
            }
            if(nums[i]==0)
                continue;
            
            if(stk.empty() || stk.top()<nums[i]){ // increasing order all em greater    
                stk.push(nums[i]);
                cnt++;
            }
        }

        return cnt;
    }
};


int main(){

    return 0;
}