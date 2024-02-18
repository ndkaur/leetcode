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
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int mx = 0;
        set<int> st;

        for(int i=0; i<n; i++){
            string temp = to_string(arr1[i]);
            for(int i=1; i<=temp.size(); i++){
                string sub = temp.substr(0, i);
                st.insert(stoi(sub));
            }
        }

        for(int i=0; i<m; i++){
            string temp = to_string(arr2[i]);
            for(int i=1; i<=temp.size(); i++){
                string sub = temp.substr(0, i);
                if(st.find(stoi(sub))!=st.end()){
                    mx = max(mx, (int)sub.size());
                }
            }
        }
        return mx;
    }
};


class Solution0 {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int mx = 0;
        set<int> st;

        for(int i=0; i<n; i++){
            string temp = to_string(arr1[i]);
            for(int i=1; i<=temp.size(); i++){
                string sub = temp.substr(0, i);
                st.insert(stoi(sub));
            }
        }

        for(int i=0; i<m; i++){
            string temp = to_string(arr2[i]);
            for(int i=1; i<=temp.size(); i++){
                string sub = temp.substr(0, i);
                if(st.find(stoi(sub))!=st.end()){
                    mx = max(mx, (int)sub.size());
                }
            }
        }
        return mx;
    }
};


class Solution {
public:
    int length(int n){
        string ans = to_string(n);
        return ans.size();
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        
        unordered_set<int> st;
        for(int a:arr1){
            while(a>0){
                st.insert(a);
                a = a/10;
            }
        }
        int mx =0;
        for(int a:arr2){
            while(a>0){
                if(st.find(a)!=st.end()){
                    mx = max(mx, length(a));
                    break;
                }
                a= a/10;
            }
        }
        return mx;
    }
};


int main(){

    return 0;
}