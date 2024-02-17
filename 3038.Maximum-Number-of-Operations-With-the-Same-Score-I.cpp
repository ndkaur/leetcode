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
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int temp = nums[0]+nums[1];
        for(int i=0; i<n-1; i+=2){
            int sum = nums[i]+nums[i+1];
            if(temp==sum)
                cnt++;
            else 
                break;
        }
        return cnt;
    }
};



int main(){

    return 0;
}