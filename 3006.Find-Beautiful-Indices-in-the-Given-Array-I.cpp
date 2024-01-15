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
    void patternMatch(string& s, string& a, vector<int>& arr){
        int n = s.size();
        int j = 0;
        for(int i=0; i<n; i++){
            if(s[i]==a[j] && j<a.size()){
                j++;
            }
            else{
                if(j==a.size()){ // matched and j reached end of string a 
                // the length j moved will be i-j eg , i=4 my  and a.size() =2 
                // so i now reched 6 so the ith index in the beginning will be at 6-2 = 4 
                    arr.push_back(i-j);
                }
                j=0;// check again of same string if present again 
                if(s[i]==a[j])
                    j++;
            }
        }
        // the string occur at last index
        if(j==a.size()){
            arr.push_back(n-j);
        }
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size();
        vector<int> aidx, bidx, ans;
        patternMatch(s,a, aidx);
        patternMatch(s, b, bidx);

        for(int i:aidx){
            for(int j:bidx){
                if(abs(i-j)<=k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    void patternMatch(string& s, string& a, vector<int>& arr){
        int n = s.size();
        int m = a.size(); // small string
        // make seperate substring of length of string 
        for(int i=0; i<=n-m; i++){
            // substr -> start idx, length of string
            if(s.substr(i,a.size())==a){
                arr.push_back(i);
            }
        }
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size();
        vector<int> aidx, bidx, ans;
        patternMatch(s,a, aidx);
        patternMatch(s, b, bidx);

        for(int i:aidx){
            for(int j:bidx){
                if(abs(i-j)<=k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};



int main(){

    return 0;
}