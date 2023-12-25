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
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        unordered_set<int> h; 

        for(int i=0; i<hFences.size(); i++){
            for(int j=0; j<hFences.size(); j++){
                h.insert(abs(hFences[i]-hFences[j]));
            }
        }

        long long mx = 0;
        long long mod = 1e9+7;

        for(int i=0; i<vFences.size(); i++){
            for(int j=0; j<vFences.size(); j++){
                if(i!=j && h.find(abs(vFences[i]-vFences[j]))!=h.end()){ // diff found
                    mx = max(mx, (long long)abs(vFences[i]-vFences[j]));
                }
            }
        }
        return (mx==0) ? -1 : ((mx*mx)%mod);
    }
};


// find the most max common diff of both and multiply them


int main(){

    return 0;
}