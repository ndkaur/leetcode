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
    int countWords(vector<string>& words1, vector<string>& words2) {
		int n= words1.size();
		int m = words2.size();
		int ans =0;
		map<string,int>mp1,mp2;
		for(int i=0;i<n;i++){
			mp1[words1[i]]++;
		}
		for(int j=0;j<m;j++){
			mp2[words2[j]]++;
		} 


		// for(int i=0;i<n;i++){
		// 	if(mp1[words1[i]]==1 && mp2.find(words1[i])!=mp2.end()){
		// 		if(mp2[words1[i]]==1){
		// 			ans++;
		// 		}
		// 	}
		// }


		// for(auto x:mp1){
		// 	if(x.second ==1 && mp2[x.first]==1)
		// 		ans++;
		// }

		for(string word:words2){
			if(mp1[word]==1 && mp2[word]==1)
				ans++;
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<string> words1={"a","ab"};
	vector<string> words2={"a","a","a","ab"};
	int ans = sol.countWords(words1,words2);
	cout<<ans;
    return 0;
}