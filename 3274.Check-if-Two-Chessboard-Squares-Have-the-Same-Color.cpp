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
    string check(int num1, int num2){
        if(num1%2==0 && num2%2==0){
            return "black";
        }
        else if(num1%2!=0 && num2%2!=0){
            return "black";
        }
        else{
            return "white";
        }
    }
    bool checkTwoChessboards(string co1, string co2) {
        // number = row
        // alphabet = column
        // even even = black ,  odd odd = balck 
        // even odd = white , odd even = white 
        int a1 = (co1[0]-'a')+1;
        int n1 = (co1[1]-'0');

        int a2 = (co2[0]-'a')+1;
        int n2 = (co2[1]-'0');

        string val1 = check(a1, n1);
        string val2 = check(a2, n2);
        if(val1==val2)
            return true;
        return false;
    }
};

int main(){

    return 0;
}