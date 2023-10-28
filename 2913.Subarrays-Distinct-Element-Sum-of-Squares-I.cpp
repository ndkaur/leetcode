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
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i=0; i<n; i++){
            
            for(int j=i; j<n; j++){
                set<int> st;
                for(int k=i; k<=j; k++){
                    st.insert(nums[k]);
                }
                sum += st.size() * st.size();
            }
            
        }
        return sum;
    }
};

int main(){

    return 0;
}