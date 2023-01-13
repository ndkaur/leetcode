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

// O(max(m,n))
class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        map<char,int> mp1,mp2;
        for(int i=0; i<n; i++){
            mp1[word1[i]]++;
        }
        for(int i=0; i<m; i++){
            mp2[word2[i]]++;
        }
     
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                // efcd  so e -> 0  , f-> 1 + 97 = 98 
                char c1 = i + 'a';   
                char c2 = j + 'a';
                if(mp1.count(c1) && mp2.count(c2)){ // swap
                    // remove 
                    --mp1[c1];
                    --mp2[c2];
                    if(mp1[c1] == 0)
                        mp1.erase(c1);
                    if(mp2[c2] == 0)
                        mp2.erase(c2);

                    // add 
                    mp1[c2]++;
                    mp2[c1]++;

                    // distinct chars // size of map on basis of keys 
                    if(mp1.size() == mp2.size())
                        return true;


                    // reverting back the changes for next iteration
                    // remove new added
                    mp1[c2]--;
                    mp2[c1]--;
                    if(mp1[c2] == 0)
                        mp1.erase(c2); 
                    if(mp2[c1] == 0)
                        mp2.erase(c1);
                    // add back removed chars and 
                    mp1[c1]++;
                    mp2[c2]++;
                }
            }
        }
        return false;
    }
};

int main(){

    return 0;
}