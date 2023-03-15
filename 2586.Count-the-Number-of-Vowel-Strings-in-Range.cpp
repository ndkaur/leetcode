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

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int n = words.size();
        int cnt = 0;
        set<char> s = {'a', 'e', 'i','o','u'};
        for(int i=left; i<=right; i++){
            int sz = words[i].size();
            if(s.find(words[i][0])!=s.end() && s.find(words[i][sz-1])!=s.end())
                cnt++;
        }
        return cnt;
    }
};

int main(){

    return 0;
}