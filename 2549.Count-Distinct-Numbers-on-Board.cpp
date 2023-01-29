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
    int distinctIntegers(int n) {
        if(n == 1) return 1;
        return n  - 1;
    }
};

class Solution {
public:
    int distinctIntegers(int n) {
        queue<int> q;
        q.push(n);
        int cnt =1;
        set<int> s;
        while(q.size()){
            int t = q.front();
            q.pop();
            for(int i=1; i<=n; i++){
                if(t % i == 1){
                    if(s.count(i) == 0){
                        cnt++;
                        q.push(i);
                        s.insert(i);
                    }
                }
            }
        }
        return cnt;
    }
};





int main(){

    return 0;
}