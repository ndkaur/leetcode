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
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int tsum = 0;
        for(int i=0; i<n; i++){
            tsum += nums[i];
        }
        int cnt = 0;
        int sum = 0;
        for(int i=0; i<n-1; i++){
            sum += nums[i];
            int temp = tsum-sum;
            if(abs(temp-sum)%2==0){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}