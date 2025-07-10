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
    string reversePrefix(string word, char ch) {
        int n = word.size();
        string temp ="";
        int idx = -1;
        for(int i=0; i<n; i++){
            temp+=word[i];
            if(word[i]==ch){
                idx = i;
                break;
            }
        }
        if(idx==-1)
            return word;
        reverse(temp.begin(), temp.end());
        for(int i=idx+1; i<n; i++){
            temp+= word[i];
        }
        return temp;
    }
};


class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int i =0;
        for(i=0; i<n; i++){
            if(word[i]==ch){
                break;
            }
        }
        if(i==n)
            return word;
        int l=0;
        int r =i;
        string ans = word;
        while(l<=r){
            swap(ans[l], ans[r]);
            l++;
            r--;
        }
        return ans;
    }
};

int main(){

    return 0;
}