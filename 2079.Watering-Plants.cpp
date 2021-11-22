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
    int wateringPlants(vector<int>& p, int c) {
        int n= p.size();
        int step=1;
        int ca=c;
        ca= ca-p[0];
        for(int i=1;i<n;i++){
            if(ca>=p[i]){
                step+=1;
                ca=ca-p[i];
            }else if(ca<p[i]){
                ca=c;
                step += (2*i)+1; 
                ca= ca-p[i];
            }
        }
        return step;
    }
};

class Solution0{
public:
    int wateringPlants(vector<int>& p, int capacity) {
    	int res = 0, can = capacity;
    	for (int i = 0; i < p.size(); ++i) {
        	if (can < p[i]) {
            	res += i * 2;
            	can = capacity;
        	}
        	can -= p[i];
    	}
    	return res + p.size();
	}
};

int main(){
	Solution sol;
	vector<int> p= {2,2,3,3};
	int c=5;
	int ans = sol.wateringPlants(p,c);
	cout<<ans;
    return 0;
}