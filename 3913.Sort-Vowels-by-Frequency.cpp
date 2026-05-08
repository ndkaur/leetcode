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
    bool isVowel(char c){ 
        return c=='a'|| c=='e'||c=='i'||c=='o'||c=='u';
    }

    string sortVowels(string s) {
        int n = s.size();
        unordered_map<char,int> mp; // stores the cnt of each vowel 
        unordered_map<char,int> rank; // stores the first occurence idx for char

        int x=1; // ranking order idx 
        string temp; // sorted string-> to know which char to put on basis of highest frequ in map
        for(auto ch:s){
            if(isVowel(ch)){
                temp.push_back(ch);
                mp[ch]++;
                if(rank[ch]==0){
                    rank[ch]=x;
                    x++;
                }
            }
        }

        sort(temp.begin(), temp.end(), [&](char a, char b){
            if(mp[a]==mp[b]){ // same freq, chose that occur first 
                return rank[a]<rank[b];
            }
            return mp[a]>mp[b]; // decresing order 
        });

        // now the string is formed to put in that order 
        int idx =0;
        for(auto &ch:s){
            if(isVowel(ch)){
                ch = temp[idx];
                idx++;
            }
        }
        return s;
    }
};


int main(){

    return 0;
}