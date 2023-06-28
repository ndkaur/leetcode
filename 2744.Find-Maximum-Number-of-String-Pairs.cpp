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
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n= words.size();
        int cnt =0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                string r = func(words[j]);
                if(words[i]== r)
                    cnt++;
            }
        }
        return cnt;
    }
    string func(string& word){
        string ans;
        for(int i=word.size()-1; i>=0; i--){
            ans+= word[i];
        }
        return ans;
    }
};

int main(){

    return 0;
}