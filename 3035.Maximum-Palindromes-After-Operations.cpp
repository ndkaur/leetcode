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


// we can swap any char with any other 
// but the len of each word must reamin same after swap 
// even freq can be reaggranged in any way 
// but in case of odd we can make pairs but only 1 freq remains whoch is the used as middle char 
// but if we have an odd len more than odd freq , odd fre <= odd len then we can arrange 1 freq  char 

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        // cnt can be odd or even 
        // but in that odd even cnt we want a same ch to occur in even occurence 
        int n = words.size();
        vector<int> cnt(26,0);
        int pairs = 0;
        int ans = 0;
        vector<int> sizes;  // to store size of each word 
        // in case no plaindrome can be made we will use the word which is of len =1 

        for(auto word:words){
            for(auto ch:word){
                cnt[ch-'a']++;
                pairs += (cnt[ch-'a'])%2==0;
            }
            sizes.push_back(word.size());
        } 

        sort(sizes.begin(), sizes.end());
        for(auto sz:sizes){
            int val = sz/2; // 3/2= 1 
            // this means the val pairs are used and then use remaing pairs 
            pairs = pairs-val;
            // checking so that we dont run out of the tootal len of al words 
            ans += (pairs>=0);
        }
        return ans;
    }
};

// cnt -> a=4, b=4 
//  pairs = 1 + 1 + 1 + 1 = 4 
//  sz= {4,2,2}
//  sort sz= {2,2,4}
// 2/2=0, pairs = 4 = 3 
// ans = 1 
// 2/2=0 , pair =4 , ans =2
// 4/2=0, pair= 4, ans= 3 


int main(){

    return 0;
}