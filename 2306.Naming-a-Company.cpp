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

// tle 
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        map<string,int> mp;
        for(auto idea:ideas){
            mp[idea]++;
        }
        int cnt= 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(swapp(ideas[i], ideas[j], mp)){
                    cnt+=2;
                }
            }
        }
        return cnt;
    }
    bool swapp(string& s1, string& s2, map<string,int>& mp){
        int n = s1.size();
        int m = s2.size();
        string t1 = s1;
        string t2 = s2;
        for(int i=0; i<t1.size(); i++){
            t1[0] = s2[0];
            t2[0] = s1[0];
        }
        if(mp.find(t1) == mp.end() && mp.find(t2) == mp.end()){
            return true;
        }
        return false;
    }
};

// Time complexity : O(n)+O(26^2)
// Space complexity : O(n)
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        long long ans =0;
        unordered_set<string> s[26];
        // inserting in set = {first char , remain chars in word}
        // coffee , donuts, time , toffee
        // set = c-> 2 ={offee} , d->3 = {onuts} , t->19 = {ime, offee}
        for(auto idea:ideas){
            // for first char -> insert whole word
            s[idea[0]-'a'].insert(idea.substr(1));
        }

        // now for each char check others if they have any similar words
        for(int i=0; i<25; i++){
            for(int j=i+1; j<26; j++){
                // i= 2 = c {offee}
                // j = 19 ->t ={ime ,offee}
                int cnt =0;
                // compare the strings at i in set with string of j in set
                for(auto strg: s[i]){
                    if(s[j].count(strg))
                        cnt++;
                }
                // 2* because if i->j pair is unique then j->i pair is also unique 
                // no of unique strings = total strings - non unique(already existing = cnt )
                ans += 2 * (s[i].size() - cnt) * (s[j].size() - cnt);
            }
        }
        return ans;
    }
};

EXPLANATION :- 

// {coffee , donuts, time, toffee}
// c-> 2 = {offee}
// d-> 3 = {onuts}
// t->19 = {ime, offee}
// ans = 2 * (s[i].size() - cnt) * (s[j].size() - cnt)

// when i=2 , j=3 
// s[i] ={offee}
// s[j] = {onuts}
// cnt =0  as no intersection between both the set of i and j 
// ans = 2 * (1-0) * (1-0) = 2 

// when i=2, j=19 
// s[i]= {offee}
// s[j]= {ime, offee}
//  both the sets have common string ie offee so cnt =1 
// ans = 2 * (1-1) * (2-1) = 2*0*1 = 0 

// ans = 2 

// when i=3 , j= 19
// s[i] = {onuts}
//  s[j]= {ime, offee}
// cnt =0  no same strings in both the sets
// ans  =  2 * (1-0) * (2-0) = 2*1*2 = 4

// ans = 2+4 = 6

int main(){

    return 0;
}