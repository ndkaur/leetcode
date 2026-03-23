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


class Solution0 { //tle
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return -1;

        vector<long long> sum(n,0);
        long long s = 0;
        for(int i=0; i<n; i++){
            sum[i]= s;
            s+= nums[i];
        }

        vector<long long> pro(n,0);
        long long p = 1;
        for(int i=n-1; i>=0; i--){
            pro[i] = p;
            p *= nums[i];
        }

       
        for(int i=0; i<n; i++){
            if(sum[i]==pro[i])
                return i;
        }
        return -1;
    }
};


// instead of recomputing , store sum and contune product on the go
class Solution1 { 
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return -1;

        vector<long long> sum(n);
        long long s = 0;
        for(int i=0; i<n; i++){
            sum[i]= s;
            s+= nums[i];
        }

        long long limit= 1e14;
        long long p = 1;

        for(int i=n-1; i>=0; i--){
            if(sum[i]==p)
                return i;
            if(p>limit)
                continue;
            p*= nums[i];

            if(p>limit)
                p = limit+1;
        }

        return -1;
    }
};


class Solution { 
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        long long s = 0;
        for(int n:nums){
            s+=n;
        }

        int ans = -1;

        long long p = 1;

        for(int i=n-1; i>=0; i--){
            s -=nums[i];
            if(s==p)
                return i;
            if(s<p)
                break;
            p *=nums[i];
        }
        
        return -1;
    }
};


int main(){

    return 0;
}