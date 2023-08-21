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
    int minimumSum(int n, int k) {
        // vector<int> arr;
        int sum =0;
        int i = 1;
        set<int> st;
       
        while(n){
            if(st.find(i)==st.end()){
                sum+=i;
                n--;
            }
            st.insert(k-i);
            i++;
           
        }
          
        return sum;
    }
};

int main(){

    return 0;
}