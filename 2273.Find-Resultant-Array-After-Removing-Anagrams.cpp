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
    vector<string> removeAnagrams(vector<string>& words) {
        
        for(int i=1;i<words.size();i++){
            string x= words[i];
            sort(x.begin(),x.end());
            string y= words[i-1];
            sort(y.begin(),y.end());
            if(x==y){
                words.erase(words.begin()+i);
                i--;
            }
        }
        return words;
    }
};

class Solution { // az  azz -> ans = "az", "azz"
public:
    bool isang(string a, string b){
        vector<int> cnt(26);

        for(auto i:a){
            cnt[i-'a']++;
        }
        for(auto j:b){
            cnt[j-'a']--;
        }
        for(auto c:cnt){
            if(c!=0)
                return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
       
        for(int i=0; i<n; ){
            int j=i+1;
            while(j<n && isang(words[i], words[j])){
                j++;
            }
            ans.push_back(words[i]);
            i=j;
        }
        return ans;

    }
};

int main(){

    return 0;
}