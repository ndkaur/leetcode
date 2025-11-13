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
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        // if the gcd of the whole array != 1 then we cant make any one , so return -1 
        // if in the array any 1 already exists then we can easliy make all other elem as 1, so ans will be the count of non- one elems
        // so when there is no 1 , but its a valid nums array , so then 
        //eg -> 6,10,15  or nums= 2,6,3,15 
        // then we have to find the smallest subarray that has gcd as 1 
        // and we are able to make a 1 , how may operatons will eb required to make other values as 1 ? 
        
        int gcdd = 0;
        int no_of_ones = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==1)
                no_of_ones++;
            gcdd = __gcd(gcdd, nums[i]);
        }
        if(gcdd!=1)
            return -1;
        if(no_of_ones>0){
            return n-no_of_ones;
        }

        // find the length of smllest subarray whose gcd is 1 
        int mn = INT_MAX;
        for(int i=0; i<n; i++){
            int g = nums[i];
            for(int j=i+1; j<n; j++){
                g = __gcd(g, nums[j]);
                if(g==1){
                    // subarray len + total length - 1(for the 1 alredy made)
                    mn = min(mn, j-i+(n-1));
                    break;
                }
            }
        }
     
        return mn;
    }
};

// 6 10 15
// 6 5 15
// 1 5 15
// 1 1 15
// 1 1 1

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = count(nums.begin(), nums.end(),1); // even if a single 1 is found
        if(cnt)
            return (n-cnt);
        
        int ans =INT_MAX;

        for(int i=0; i<n; i++){
            int g= nums[i];
            for(int j=i+1; j<n; j++){
                g= __gcd(g, nums[j]);
                if(g==1){
                    ans = min(ans, j-i+(n-1));
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main(){

    return 0;
}