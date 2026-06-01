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
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> q;
        q.push(0);
        vector<int> visited(n,0);
        visited[0]=1;
        int far = 0;

        while(q.size()){
            int idx = q.front();
            q.pop();
            if(idx==n-1)
                return true;
            
            int l = max(far+1, idx+minJump);
            int r = min(idx+maxJump, n-1);

            for(int k=l; k<=r; k++){
                if(s[k]=='0' && !visited[k]){
                    visited[k]=1;
                    q.push(k);
                }
            }
            far = max(far, r);
        }
        return false;
    }
};


int main(){

    return 0;
}