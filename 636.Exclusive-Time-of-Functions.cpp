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
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int prev = 0;
        stack<int> stk;
        vector<int> ans(n,0);

        for(int i=0; i<logs.size(); i++){
            string str = logs[i];

            auto pos = str.find(':');
            int id = stoi(str.substr(0, pos));
            str.erase(0,pos+1);
            
            pos = str.find(':');
            string type = str.substr(0,pos);
            str.erase(0, pos+1);

            int currTime = stoi(str);

            if(type=="start"){
                if(stk.size()>0){
                    ans[stk.top()] += currTime -prev;
                }
                stk.push(id);
                prev = currTime;
            }
            else{
                ans[stk.top()] += currTime-prev+1;
                stk.pop();
                prev = currTime+1;
            }
        }
        return ans;
    }
};

// when its start-> curr time-prevtime
// when its end -> we add extra 1 , curr-prev+1 

// logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]

int main(){

    return 0;
}