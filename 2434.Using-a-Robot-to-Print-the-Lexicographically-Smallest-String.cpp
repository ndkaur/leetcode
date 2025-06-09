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
    char low(vector<int>& freq){
        for(int i=0; i<26; i++){
            if(freq[i]!=0)
                return 'a'+i; // return the char 
        }
        // no char count left in freq array
        return 'a';
    }
    string robotWithString(string s) {
        int n = s.size();
        stack<char> stk;
        string ans ="";
        vector<int> freq(26,0);
        for(auto ch:s){
            freq[ch-'a']++;
        }

        for(char ch:s){
            stk.push(ch);
            freq[ch-'a']--;
            while(stk.size()>0 && stk.top()<=low(freq)){
                char temp = stk.top();
                ans+=temp;
                stk.pop();
            }
        }

        while(stk.size()>0){
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};

int main(){

    return 0;
}
