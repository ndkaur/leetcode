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

class Solution0 {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        set<int> st;
        for(int i=0; i<n; i++){
            int abnum = abs(nums[i]);
            if(abnum>mx && st.count(-nums[i])){
                mx = abnum;
            }
            st.insert(nums[i]);
        }
        return mx?mx:-1;
    }
};

//-1 -3 2 3
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int h = n-1;
        while(l<h){
            if(nums[l]+nums[h]==0){
                return nums[h];
            }
            else if(nums[l]+nums[h]<0)
                l++;
            else 
                h--;
        }
        return -1;
    }
};

int main(){

    return 0;
}