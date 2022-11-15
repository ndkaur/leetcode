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
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        set<double> st;
        sort(nums.begin(), nums.end());
        int i=0; 
        int j=n-1;
        while(n>0){
            double avg = (nums[i] + nums[j]) / 2.0;
            i++;
            j--;
            n--;
            st.insert(avg);
        }
        return st.size();
    }
};

int main(){

    return 0;
}