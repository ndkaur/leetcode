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
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> store;
        int n= heights.size();
        for(int i=0; i<n; i++){
            store.push_back({heights[i] , names[i]});
        }
        sort(store.begin(), store.end());
        reverse(store.begin(), store.end());
        vector<string> ans;
        for(auto i:store){
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main(){

    return 0;
}