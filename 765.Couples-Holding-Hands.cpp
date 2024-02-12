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

// union find 
class Solution {
public:
    vector<int> parent;
    int findParent(int x){
        if(parent[x]==x)
            return x;
        return parent[x] = findParent(parent[x]);
    }
    bool unionn(int a, int b){
        a = findParent(a);
        b = findParent(b);
        if(a==b) // already sitting together 
            return false;
        // if not sitting together join them by making parents same
        parent[a]=b;
        return true;
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        if(n==0)
            return 0;
        
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }

        // 0 2 1 3 -> make the same parent of two adj values 
        for(int i=0; i<n; i+=2){
            // 0 parent as 0 , and 2 parent as 0 also 
            parent[row[i]] = row[i];
            parent[row[i+1]] = row[i];
        }
        // now iterate on indexes and see if 1, 2 are in the same group or not
        int cnt = 0;

        for(int i=0; i<n; i+=2){
            if(unionn(i, i+1)) // both are having different parents so join them 
                cnt++;
        }

        return cnt;
    }
};


int main(){

    return 0;
}