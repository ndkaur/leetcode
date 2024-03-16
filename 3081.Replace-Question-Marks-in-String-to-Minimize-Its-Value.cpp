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
    string minimizeStringValue(string s) {
        int  n = s.size();
        vector<int> freq(26,0);
        string temp = "";
        for(auto ch:s){
            if(ch!='?'){
                freq[ch-'a']++;
            }
        }

        for(auto i=0; i<n; i++){
            if(s[i]!='?')
                continue;
            // if its ? find char for it 
            
            int idx = 0; // min idx
            int mn = INT_MAX; // min freq
            for(int i=0; i<26; i++){
                if(mn > freq[i]){ // replacing the ch with min freq 
                    mn = freq[i];
                    idx=  i;
                }
            }
            temp += ('a'+idx); 
            freq[idx]++; // now we have used that alphabet 
        }
        sort(temp.begin(), temp.end());

        int j =0;
        // replacing the quesmarks with temp
        for(int i=0;i<n; i++){
            if(s[i]=='?'){
                s[i] = temp[j];
                j++;
            }
        }   
        return s;
    }
};


int main(){

    return 0;
}