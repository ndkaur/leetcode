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
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0;
        long long result = 0;
        for (int index = 0; index < nums.size(); ++index) {
            sum += nums[index];
            result = max(result, (sum + index) / (index + 1));
        }
        return (int) result;
    }
};

int main(){

    return 0;
}