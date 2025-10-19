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
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;
        queue<string> q;
        unordered_set<string> visited;
        q.push(s);
        visited.insert(s);

        while(q.size()){
            string curr = q.front();
            q.pop();
            if(curr<ans){
                ans = curr;
            }

            string add = curr;
            for(int i=1; i<add.size(); i+=2){// odd indexes
                // its a string -> convert into num ->covert back into string
                add[i] = (((add[i]-'0')+a)%10) + '0';
            }
                
            if(!visited.count(add)){
                visited.insert(add);
                q.push(add);
            }
            // 2255-> 5522
            string rotate = curr.substr(curr.size()-b) + curr.substr(0, curr.size()-b);
            if(!visited.count(rotate)){
                visited.insert(rotate);
                q.push(rotate);
            }  
        }
        return ans;
    }
};


int main(){

    return 0;
}