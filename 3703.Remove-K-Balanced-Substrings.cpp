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
    string removeSubstring(string s, int k) {
        int n = s.size();
        stack<pair<char,int>> stk;
        for(auto ch:s){
            if(stk.size() && stk.top().first==ch){ // same char increase cnt
                stk.top().second++;
            }
            else {
                stk.push({ch,1});
            }
        
            int sz = stk.size();
            // check the pairs of size k
            if(sz>1){
                    // ( )
                auto [last, lastcnt] = stk.top();
                stk.pop();

                auto [second_last, second_last_cnt] = stk.top();
                stk.pop();

                if(second_last=='(' && second_last_cnt>=k && last==')' && lastcnt>=k){
                    second_last_cnt-=k;
                    lastcnt -=k;
                }

                if(second_last_cnt>0) // ( 
                    stk.push({second_last, second_last_cnt});
                if(lastcnt>0) // )
                    stk.push({last, lastcnt}); 
            }
        }

        string ans;
        while(stk.size()){
            auto [ch, cnt] = stk.top();
            stk.pop();
            while(cnt--){
                ans+= ch;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



int main(){

    return 0;
}