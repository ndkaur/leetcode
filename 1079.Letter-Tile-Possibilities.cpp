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
        int f(vector<int>& freq){
            int cnt =0;
            for(int i=0; i<26; i++){
                if(freq[i]>0){
                    freq[i]--;
                    cnt += 1+ f(freq);
                    freq[i]++;
                }
            }
            return cnt;
        }
        int numTilePossibilities(string tiles) {
            int n = tiles.size();
            vector<int>freq(26,0);
            for(auto ch:tiles){
                freq[ch-'A']++;
            }
            return f(freq);
        }
    };

int main(){

    return 0;
}