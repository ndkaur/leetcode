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
    long long sumAndMultiply(int n) {
        long long sum = 0;
        if(n==0)
            return 0;
        string temp = to_string(n);
        string ans="";
        for(int i=0; i<temp.size(); i++){
            if(temp[i]-'0'!=0){
                ans+=temp[i];
                sum+= temp[i]-'0';
            }
        }
        
        long long val = stol(ans);
        return val*sum;
    }
};

int main(){

    return 0;
}