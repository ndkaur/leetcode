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
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int reqx=0; reqx<k; reqx++){
            int cntx = 0;
            for(int i=0; i<n; i+=2){ // even
                int curr = nums[i]%k; 
                int v1 = abs(reqx-curr);
                int v2 = k-v1;
                cntx += min(v1,v2);
            }

            for(int reqy=0; reqy<k; reqy++){
                int cnty = 0;
                for(int j=1; j<n; j+=2){ // odd
                    int curr = nums[j]%k;
                    int v1 = abs(reqy-curr);
                    int v2 = k-v1;
                    cnty += min(v1,v2);
                }
                if(reqx!=reqy){
                    ans = min(ans, cntx+cnty);
                }
            }
        }
        return ans;
    }
};


// desired rem by adding or subtracting
// curr = 1, req= 2, num = 4%3 =1 , k=3  next num= 5%3 =2
// req-curr = 2-1 =1 , num+1 = 5 adding 
// req-curr = 2-1 = 1,   k-1 = 3-1 = 2 , num= 4-2 = 2 , 2%3 = 2 subtracting  

// adding abs(curr-req)

// subtrating , k- abs(req-curr)



int main(){

    return 0;
}