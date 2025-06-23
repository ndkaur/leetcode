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
    int minMaxDifference(int num) {
        string temp = to_string(num);
        int n = temp.size();
        string mx = temp;
        string mn = temp;
        char small = -1;
        char large = -1;
        for(int i=0; i<n; i++){
            if(large==-1 && temp[i]!='9'){// 90
                large = temp[i];
                mx[i]='9';
            }
            else{
                mx[i] = (temp[i]==large)?'9':temp[i];
            }

            if(small==-1 && temp[i]!='0'){//118
                small = temp[i];
                mn[i]='0';
            }
            else{
                mn[i]= (temp[i]==small)?'0':temp[i];
            }
        }
        return stoi(mx)-stoi(mn);
    }
}; 

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string small = s;
        string large = s;
        char mx = s[0];
        char mn = s[0];
        // 1181 // 9989 //  0080
        // 90  // 99 // 00
        int  i=0;
        while(true){
            if(s[i]!='9'){ // if 0th idx is not 9 then it will break 
            // or if 0th idx is 9 then go to nxt idx and so on
                mx = s[i];
                break;
            }
            else{
                i++;
            }
        }
        replace(large.begin(), large.end(),mx,'9');
        replace(small.begin(), small.end(), mn, '0');
        return stoi(large) - stoi(small);
    }
};

int main(){

    return 0;
}