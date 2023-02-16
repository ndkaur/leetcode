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
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int i =0;
        int j = n-1;
        while(i<j){
            string n1 = to_string(nums[i]);
            string n2 = to_string(nums[j]);
            string sum = n1+n2;
            ans += stoi(sum);
            i++;
            j--;
        }
        if(i==j)
            ans += nums[i];
        return ans;
    }
};


int main(){

    return 0;
}