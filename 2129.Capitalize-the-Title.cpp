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
    string capitalizeTitle(string s) {
      	int n= s.size();
      	for(int i=0;i<n;i++) {
			if(s[i]==' ') continue;
			int j = i, cnt = 0;
			while(j<n && s[j]!=' '){
				s[j] = tolower(s[j]);
				++j, cnt++;
			}
			if(cnt>2){
				s[i]= toupper(s[i]);
			}
			i = j;
      }
      return s;
    }
};

int main(){
      Solution sol;
      string s="capiTalIze tH titLe";
      string ans = sol.capitalizeTitle(s);
      for(auto c:ans){
            cout<<c;
      }
   return 0;
}