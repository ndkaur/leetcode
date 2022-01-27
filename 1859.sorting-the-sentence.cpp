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

// ascii  0->48   9->57
class Solution {
public:
    string sortSentence(string s) {
        int n=s.size();
        string word;
        vector<string> count(10);
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){ // is a number  
                count[s[i]-'0'] = word +" "; // 3 ->51-48=3
                word="";
                i++;
            }
            else // word 
                word+=s[i];
        }
        string ans;
        for(string word:count){
            ans+= word;
        }
        ans.pop_back();
        return ans;
    }
};

int main(){
    Solution sol;
    string s= "is2 sentence4 This1 a3";
    string ans= sol.sortSentence(s);
    for(auto x:ans)
        cout<<x;
    return 0;
}