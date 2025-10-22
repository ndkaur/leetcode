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
    void solve(int i, string temp, string& target, vector<int>& freq, string& mn){
        int n = target.size();
        if(i==n){
            if(temp>target){
                mn = min(mn, temp);
            }
            return;
        }

        // collecting same chars 
        int idx = target[i]-'a';
        if(freq[idx]>0){
            freq[idx]--;
            // adding the same char 
            solve(i+1, temp+target[i], target, freq, mn);
            // backtrack 
            freq[idx]++;
        }

        // now adding next grater char that has non zero freq
        for(int j=idx+1; j<26; j++){
            if(freq[j]>0){
                temp += 'a'+j; // adding char
                freq[j]--;

                // now adding the remaing chars in soreted order
                for(int k=0; k<26; k++){
                    while(freq[k]>0){
                        temp+= 'a'+k;
                        freq[k]--;
                    }
                }
                mn = min(mn, temp);
                return;
            }
        }
    }
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26,0);
        // greatest string
        sort(s.rbegin(), s.rend());
        if(s<=target)
            return "";
        
        string mn = s;
        for(auto ch:s){
            freq[ch-'a']++;
        }

        solve(0, "", target, freq, mn);
        return mn;
    }
};

// if the greates permutation is smaller than target then its not possible 
// we first match the common elemts 
// when some char occur that doent match , then we take the next greater char of the unmatched char 
// then for remianing string we fill will all the chars in the sorted order 

// prefix(common) + next greater char + all the remianing ordered


int main(){

    return 0;
}