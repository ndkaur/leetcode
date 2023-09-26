/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */
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

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        // store the last index of each char in the string 
        vector<int> last_freq(26);
        for(int i=0; i<n; i++){
            last_freq[s[i]-'a'] = i;
        }
        // vector to check if visited or not 
        vector<int> visited(26);
        string ans = "";

        for(int i=0; i<n; i++){
            if(visited[s[i]-'a']) // if already visited then skip
                continue;
            // 1st condition:- ans string must not be empty
            // 2nd conditon:- the current element is greater than the last element added in the ans string
            // 3rd conditon:-  the last element of the string ans must not be at its last freq index 
            while(ans.size() && ans.back()>s[i] && last_freq[ans.back()-'a']>i){
                visited[ans.back()-'a'] = 0;
                ans.pop_back();
            }
            // add the curr char to ans and mark as visited
            ans.push_back(s[i]);
            visited[s[i]-'a']=1;
        }
        return ans;
    }
};

// 0 1 2 3 4
// b c a b c

// last freq = a-> 2 , b->3,  c->4 

// visited = 
// ans = " "
// i=0  ans = b  visited = {b}
// i=1  b>c no its not so no pop  
//  ans =  bc  visited = { b,c}
// i= 2  c>a yes , check last freq of c = 4>2 yes so pop vis ={ b}
// ans = b  , again check b>a , last freq of b=3 >2 so pop vis = {}
// ans = " "
// i=3  ans = a
// i=4  ans = ab  because a<b 
// i=5 ans= abc because  b<c




// @lc code=end


int main(){

    return 0;
}