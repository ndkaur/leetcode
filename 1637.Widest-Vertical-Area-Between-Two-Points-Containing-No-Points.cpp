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


class Solution { //O(nlogn)
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        set<int> st;
        for(auto point:points){
            st.insert(point[0]);
        }
        int mx= 0;
        int prev =INT_MIN;
        for(int itr:st){
            if(prev!=INT_MIN)
                mx = max(mx, itr-prev);
            prev = itr;
        }
        return mx;
    }
}; 

int main(){

    return 0;
}