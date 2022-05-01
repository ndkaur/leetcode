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
    string removeDigit(string number, char digit) {
        int n= number.size();
        string temp;
        for(int i=0;i<n;i++){
            if(number[i]==digit){
                temp= max(temp, number.substr(0,i)+number.substr(i+1));
            }
        }
        return temp;
    }
};

int main(){
    Solution sol;
    string num="123";
    char digit= "3";
    string ans= sol.removeDigit(num, digit);
    for(auto c:ans) cout<<c<<endl;
    return 0;
}