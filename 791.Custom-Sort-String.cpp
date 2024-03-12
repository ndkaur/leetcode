#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
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
    string customSortString(string order, string s) {
        int n = order.size();
        map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        string ans="";
        for(int i=0; i<order.size(); i++){
            auto ch = order[i];
            if(mp.find(ch)!=mp.end()){
                int freq = mp[ch];
                for(int j=0; j<freq; j++){
                    ans += ch;
                }
                mp.erase(ch);
            }
        }

        for(auto itr:mp){
            int freq = itr.second;
            if(freq!=0){
                while(freq--){
                    ans+= itr.first;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string order="cba";
    string str= "abcd";
    string ans = sol.customSortString(order,str);
    for(auto i:ans)
        cout<<i;
    return 0;
}