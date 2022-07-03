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
    string decodeMessage(string key, string message) {
        int n= key.size();
        int m= message.size();
        unordered_map<char,char> mp;
        int i=0;
        for(auto k:key){
            if(k != ' ' && !mp.count(k)){
                mp[k]= i +'a';
                i++;
            }
        }
        string ans;
        for(auto m:message){
           ans.push_back(m!=' ' ? mp[m] : m);
        }
        return ans;
    }
};

class Solution0 {
public:
    string decodeMessage(string key, string message) {
        int n= key.size();
        int m= message.size();
        map<char,char> mp;
        int ch=97; // a
        set<char> s;
        for(auto k:key){
            if(k>=123) // exceeded z
                break;
            // space or key found
            if(k==' ' || s.find(k)!=s.end()){
                continue;
            }
            mp[k]= char(ch);
            s.insert(k);
            ch++;
        }
        string ans;
        for(auto m:message){
            if(m ==' '){
                ans.push_back(' ');
            } else
                ans.push_back(mp[m]);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string key= "the quick brown fox jumps over the lazy dog";
    string message= "vkbs bs t suepuv";
    string ans= sol.decodeMessage(key, message);
    for(auto c:ans)
        cout<<c;
    return 0;
}