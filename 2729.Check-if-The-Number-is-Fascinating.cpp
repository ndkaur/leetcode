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
    bool isFascinating(int n) {
        int n2 = n*2;
        int n3 = n*3;
        string num = to_string(n)+to_string(n2)+to_string(n3);
        vector<int> arr(10,0);
        for(int i=0; i<num.size(); i++){
            if(num[i]-'0'==0)
                return false;
            if(arr[num[i]-'0']==1)
                return false;
            arr[num[i]-'0'] =1;
        }
        return true;
    }
};

int main(){

    return 0;
}