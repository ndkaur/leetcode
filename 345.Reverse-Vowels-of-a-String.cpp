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
    bool isVowel(char ch){
        vector<char> v = {'a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        auto it = find(v.begin(), v.end(), ch);

        if(it!=v.end()){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int n = s.size();
        vector<char> temp;
        for(auto ch:s){
            if(isVowel(ch)){
                temp.push_back(ch);
            }
        }
        reverse(temp.begin(), temp.end());
        int j =0;
        for(int i=0; i<n; i++){
            if(isVowel(s[i])){
                s[i]= temp[j];
                j++;
            }
        }
        return s;
    }
};

int main(){

    return 0;
}