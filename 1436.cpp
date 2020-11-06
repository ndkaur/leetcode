#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> sources;
        for(auto path: paths){
            string &source = path[0];
            sources.insert(source);
        }
        
        for(auto path: paths){
            string &dest = path[1];
            if(sources.count(dest)==0)
                return dest;
        }
        return "";
    }
};

int main(){
    Solution sol;
    vector<vector<string>> paths={{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    string ans=sol.destCity(paths);
    for(auto c:ans){
        cout<<c;
    }
    return 0;
}