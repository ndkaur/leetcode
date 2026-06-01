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
    int passwordStrength(string password) {
        int n = password.size();
        set<char> st;
        int ans = 0;

        for(int i=0; i<n; i++){
            auto val = password[i];
            if(st.count(val))
                continue;
            else{
                st.insert(val);
                if(val>='a' && val<='z')
                    ans+=1;
                else if(val>='A' && val<='Z')
                    ans+= 2;
                else if(val>='0' && val<='9')
                    ans+= 3;
                else 
                    ans+=5;
            }
        }
        return ans;
    }
};



int main(){

    return 0;
}