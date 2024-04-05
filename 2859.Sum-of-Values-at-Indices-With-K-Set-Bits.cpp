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
        int cnt = 0;
        for(int i=0; i<32; i++){
            if(num & (1<<i))
                cnt++;
        }
        return cnt;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            if(setBit(i)==k){
                sum += nums[i];
            }
        }
        return sum;
    }
};

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp;
        for(int i=0; i<n; i++){
            int cnt = setbit(i);
            // cout<<cnt<<endl;
            int idx = i;
            if(cnt==k)
                temp.push_back(idx);
        }
        
        int sum =0;
        for(auto idx:temp){
            sum += nums[idx];
        }
        return sum;
    }
    unsigned int setbit(int n){
        unsigned int cnt =0;
        while(n){
            n &= (n-1);
            cnt++;
        }
        return cnt;
    }
};

int main(){

    return 0;
}