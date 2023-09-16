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
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        if(is_sorted(nums.begin(), nums.end()))
            return 0;
        for(int i=n-1; i>=0; i--){
            int num = nums.back();
            nums.pop_back();
            cnt++;
            if(cnt==n){
                cnt =0;
                break;
            }
            nums.insert(nums.begin(), num);
            if(is_sorted(nums.begin(), nums.end()))
                break;
        }
        return cnt>0 ? cnt: -1;
    }
};

int main(){

    return 0;
}