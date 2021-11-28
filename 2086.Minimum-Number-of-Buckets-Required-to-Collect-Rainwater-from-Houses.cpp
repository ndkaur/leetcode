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
    int minimumBuckets(string s) {
      int n= s.size();
      int ans =0;
      for(int i=0;i<n;i++){
		if(s[i]=='H'){
		  // if left side of house is filled with bucket
			if(i-1>=0 && s[i-1]=='B'){
		  		continue;
			}
		// right side check 
			else if(i+1<n && s[i+1]=='.'){
				ans++;
				s[i+1]='B';
			}
		// left exist and is . 
			else if(i-1>=0 && s[i-1]=='.'){
				ans++;
			}
			else {
				ans=-1;
				return ans;
			}
		}
	  }
	  return ans;
    }
};

int main(){
	Solution sol;
	string s="H..H";
	int ans = sol.minimumBuckets(s);
	cout<<ans;
   return 0;
}