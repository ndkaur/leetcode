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
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            int cnt =0;
            for(int j=queries[i][0]; j<=queries[i][1]; j++){
                if(check(words[j]))
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    bool check(string& s){
        set<char> st ={'a','e','i','o','u'};
        int n= s.size();
        if(st.find(s[0])!= st.end() && st.find(s[n-1])!= st.end())
            return true;
        return false;
    }
};

// prefix sum ->sum of the number of all strings possible till that idx 
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> pref(words.size()+1);
        int i=0;
        // actual value is stored one index ahead 
        for(auto word:words){
            pref[i+1] = pref[i]+ (check(word));
            i++;
        }
        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            // in range (l,r) the value of strings till r is stored at index r+1
            ans.push_back(pref[queries[i][1]+1] - pref[queries[i][0]]);
        }
        return ans;
    }
    bool check(string& s){
        set<char> st ={'a','e','i','o','u'};
        int n= s.size();
        if(st.find(s[0])!= st.end() && st.find(s[n-1])!= st.end())
            return true;
        return false;
    }
};



class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector<int> prefixSum(n+1,0);
        set<char> st = {'a','e','i','o','u'};
        
        for(int i=0; i<n; i++){
            if(st.count(words[i].front()) && st.count(words[i].back())){
                prefixSum[i+1] = prefixSum[i] + 1;
            }
            else {
                prefixSum[i+1] = prefixSum[i]; // runing sum maintainece
            }
        }

        vector<int> ans;

        for(auto& q:queries){
            int start = q[0];
            int end = q[1];
            ans.push_back(prefixSum[end+1] - prefixSum[start]);
        }
        return ans;
    }
};

//  words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
// pref(6)
// pref is no of vowels word till that idx 
//  0  1  2  3  4  5  ->idx
//  0  1  1  2  3  4  ->cnt

//  ans = 
//  [0,2] -> ans[0]= (pref[2+1] - pref[0]) = 2-0 = 2
//  [1,4] -> ans[1] = (pref[4+1] - pref[1]) = 4 - 1 = 3
//  [1,1] -> ans[2] = (pref[1+1] - pref[1]) = 1-1 =0
//  ans = {2,3,0}





int main(){

    return 0;
}