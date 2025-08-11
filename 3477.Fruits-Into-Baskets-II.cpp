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
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> visited(n,0);
        int cnt =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(fruits[i]<=baskets[j] && !visited[j]){
                    visited[j]=1;
                    break;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(!visited[i])
                cnt++;
        }
        return cnt;
    }
};


int main(){

    return 0;
}