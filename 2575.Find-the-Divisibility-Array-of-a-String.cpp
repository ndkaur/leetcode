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
// stoi erroe as long long needed 
class Solution0 {
public:
    vector<int> divisibilityArray(string word, int m) {
        int  n = word.size();
        vector<int> ans;
        for(int i=1; i<=n; i++){
            string nw = word.substr(0,i);
            int num = stoi(nw);
            if(num%m==0)
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int  n = word.size();
        vector<int> ans;
        long long int num =0;
        for(int i=0; i<n; i++){
            num = num*10 + (word[i]-'0');
            
            if(num%m==0)
                ans.push_back(1);
            else
                ans.push_back(0);
            num = num%m;
        }
        return ans;
    }
};

int main(){

    return 0;
}