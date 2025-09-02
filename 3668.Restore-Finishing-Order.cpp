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
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = order.size();
        int m = friends.size();
        set<int> st;
        for(auto f:friends){
            st.insert(f);
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(st.find(order[i])!=st.end())
                ans.push_back(order[i]);
        }
        return ans;
    }
};

int main(){

    return 0;
}