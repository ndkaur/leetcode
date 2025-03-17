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
        int totalNumbers(vector<int>& digits) {
            int n = digits.size();
            int cnt =0;
            set<int> st;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    for(int k=0; k<n; k++){
                        if(i!=j && i!=k && j!=k){
                            if(digits[i]!=0){
                                // 3 digit num , last digit even whole num even
                                if(digits[k]%2==0){
                                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                                    st.insert(num);
                                }
                            }
                        }
                    }
                }
            }
            return st.size();
        }
    };


int main(){

    return 0;
}