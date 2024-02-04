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
    bool check(string& temp, string& word){
        int n = word.size();
        // if its a start or same char then its matching 
        for(int i=0; i<n; i++){
            // if not a star and no chars are same then not matching
            if(temp[i]!='*' && word[i]!=temp[i]){
                return false;
            }
        }
        return true;
    }
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        int cnt = 0;
        // abacaba , substr(k)+ (# k time) = caba***  , check(caba***, abacaba) ,cnt = 1
        // caba*** , substr(k)+(* k times) = a******, check(a******, abacaba) , cnt= 2 
        // so as we removed cnt has to increase no matter if it gets equal or not 
        // so this gives hint to use do while loop 
        string temp = word;
        do{ 
            // directly skip the first k elemts and use the remaing string
            // and add * in place of those removed k elemts 
            // then check if the temp and word are equal
            temp = temp.substr(k) + string(k, '*');
            cnt++;
        }while(check(temp, word)==false);

        return cnt;
    }
};


int main(){

    return 0;
}