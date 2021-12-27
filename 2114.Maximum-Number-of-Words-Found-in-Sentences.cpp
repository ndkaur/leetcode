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
    int mostWordsFound(vector<string>& sentences) {
		int n= sentences.size();
        int c=0;
		int mx=INT_MIN;
		for(auto i:sentences){
			string x=i;
			for(auto j:x){
				if(j==' ')
					c++;
			}
			mx= max(mx,c);
			c=0;
		}
		return mx+1;
    }
};

int main(){
      Solution sol;
      vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
      int ans = sol.mostWordsFound(sentences);
      cout<<ans;
      return 0;
}