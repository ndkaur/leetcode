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

class DataStream {
public:
    int sz =0 ;
    int val =0;
    int cnt =0;
    DataStream(int value, int k) {
        sz = k;
        val = value;
    }
    
    bool consec(int num) {
        if(num == val)
            cnt++;
        else
            cnt =0;
        return cnt >= sz;
    }
};



int main(){

    return 0;
}