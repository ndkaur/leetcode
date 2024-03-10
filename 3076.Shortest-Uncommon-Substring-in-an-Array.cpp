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

class Solution { // O(n * m^2) 
public:
    static bool comp(string a, string b){
        if(a.size()<b.size()){
            return true;
        }
        if(a.size()==b.size() && a<b)
            return true;
        return false;
    }
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        map<string,int> mp;
        vector<string> ans(n,"");
        vector<vector<string>> substrings(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<arr[i].size(); j++){
                string temp ="";
                for(int k=j; k<arr[i].size(); k++){
                    temp += arr[i][k];
                    bool found = false;
                    for(const auto& itr: substrings[i]){
                        if(itr==temp){
                            found = true; 
                            break;
                        }
                    }
                    if(found)
                        continue;
                    mp[temp]++;
                    substrings[i].push_back(temp);
                }
            }
            sort(substrings[i].begin(), substrings[i].end(), comp);
        }

        for(int i=0; i<n; i++){
            for(auto str:substrings[i]){
                if(mp[str]==1){
                    ans[i] = str;
                    break;
                }
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}