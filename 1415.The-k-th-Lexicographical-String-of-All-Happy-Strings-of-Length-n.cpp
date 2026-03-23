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
    void f(int n, int k, int& cnt, string& ans, string& temp, char lastchar){
        if(temp.size()==n){
            cnt++;
            if(cnt==k){
                ans = temp;
            }
            return;
        }

        vector<char> arr = {'a','b', 'c'};
        for(int i=0; i<3; i++){
            char ch = arr[i];
            if(ch!=lastchar){
                temp.push_back(ch);
                f(n, k, cnt, ans, temp, ch);
                temp.pop_back();
                if(!ans.empty())
                    return;
            }
        }
    }
    string getHappyString(int n, int k) {
        int cnt = 0;
        string ans = "";
        string temp="";
        f(n, k, cnt, ans, temp, ' ');
        return ans;
    }
};



int main(){

    return 0;
}