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
    string fractionAddition(string expression) {
        // a/b , c/d  ->  (ac + cb)/bd
        // "-1/2+1/2"
        int a = 0;
        int b = 1;
        int i = 0;
        int n = expression.size();

        while(i<n){
            int sign = 1;
            if(expression[i]=='+' || expression[i]=='-'){
                if(expression[i]=='-'){
                    sign = -1;
                }
                i++;
            }

            int c = 0;
            while(i<n && isdigit(expression[i])){
                c = c*10 + (expression[i]-'0');
                i++;
            }
            c= c*sign;

            i++;
            int d = 0;
            while(i<n && isdigit(expression[i])){
                d = d*10 + (expression[i]-'0');
                i++;
            }
            // a/b , c/d  ->  (ad + cb)/bd
            a =  a*d + c*b;
            b = b*d;

            int gcdVal = gcd(abs(a), b);
            a = a/gcdVal;
            b = b/gcdVal;
        }

        return to_string(a)+"/"+to_string(b);
    }
}; 


int main(){

    return 0;
}