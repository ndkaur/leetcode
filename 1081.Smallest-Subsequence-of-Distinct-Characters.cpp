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
    string smallestSubsequence(string s) {
        int n  = s.size();
        vector<int> last_freq(26);
        for(int i=0; i<n; i++){
            last_freq[s[i]-'a'] = i;
        }

        string ans = "";
        vector<int> visited(26);

        for(int i=0; i<n; i++){
            if(visited[s[i]-'a'])
                continue;
            
            while(ans.size() && ans.back()>s[i] && last_freq[ans.back()-'a']>i){
                visited[ans.back()-'a']=0;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            visited[s[i]-'a']=1;
        }
        return ans;
    }
};

// 2 things makes it ok for us to add
// 1) prev added elem must be smaller than curr elem so to maintian lexiographicall order
// 2) we only add a curr elm when we know that its the last occurence of the curr elem and after this we can add it 

int main(){

    return 0;
}