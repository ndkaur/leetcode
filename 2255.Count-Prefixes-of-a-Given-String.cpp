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
    int countPrefixes(vector<string>& words, string s) {
        int n= words.size();
        int count=0;
        int i,j;
        for(i=0;i<n;i++){
            j=0;
            while(j<words[i].size()){
                if(words[i][j]!=s[j])
                    break;
                j++;
            }
            if(j==words[i].size())
                count++;
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<string> words={"feh","w","w","lwd","c","s","vk","zwlv","n","w","sw","qrd","w","w","mqe","w","w","w","gb","w","qy","xs","br","w","rypg","wh","g","w","w","fh","w","w","sccy"};
    string s= "w";
    int ans = sol.countPrefixes(words,s);
    cout<<ans;
    return 0;
}