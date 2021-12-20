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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n= words.size();
        for(auto s: words){
            if(check(s))
                return s;
        }
        return "";
    }
    bool check(string &w){
        int n= w.size();
        int i=0,j=n-1;
        while(w[i]==w[j] && i<j){
            i++;
            j--;
        }
        return i>=j;
    }
};

int main(){
	Solution sol;
	vector<string> words={"abc","car","ada"};
	string ans = sol.firstPalindrome(words);
	for(auto i:ans)
		cout<<i;
   return 0;
}