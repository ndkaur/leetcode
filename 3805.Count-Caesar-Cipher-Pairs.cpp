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
    long long countPairs(vector<string>& words) {
        int n = words.size();
        map<string, int> mp;
        long long cnt = 0;
        for(auto word:words){
            string normalized(word.size(), 'a'); 
            
            int shift = word[0]-'a'; // normalizing acc to first char of word
            
            for(int i=0; i<word.size(); i++){
                // word is string , convert to char 
                // word-shift , if negative incase add 26 
                // again add 'a' to convrt back into char  => new char normalized one
                normalized[i] = ((word[i]-'a')-shift + 26) %26+ 'a'; 
            }
            cnt+= mp[normalized];
            mp[normalized]++;
        }
        return cnt;
    }
};

// make pair of normalized values of difference according to the first char and make it 'a'  and note the steps , use those steps to make other reining chars normalized forms 
// ab = [0,1]
// aa = [0,0]
// za = [0,1] making chars to z
// aa = [0,0]
// take map and count the same pairs count
// fusion 
// f->a = 5 = a 
// u= 20-5 = 15 =p 
// s= 18-5 = n
// i= 8-5 = 3 = d
// o = 14-5 = 9 =j
// n = 13-5 = 8 = i



int main(){

    return 0;
}