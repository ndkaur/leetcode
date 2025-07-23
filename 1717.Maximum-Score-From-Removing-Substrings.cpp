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
    int score(string& s,  char a, char b){
        int cnt = 0;
        stack<char> stk;

        for(int i=0; i<s.size(); i++){
            if(!stk.empty() && stk.top()==a && s[i]==b){
                stk.pop();
                cnt++;
            }
            else{
                stk.push(s[i]);
            }
        }
        // reseting the string so that we can find with respect to other "ba"
        s="";
        
        while(stk.size()){
            s+=stk.top();
            stk.pop();
        }
        reverse(s.begin(), s.end());
        return cnt;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.size();

        int cnta =0;
        int cntb = 0;

        if(x>y){
            cnta = score(s, 'a', 'b');
            cntb = score(s, 'b', 'a');
        }
        else{
            cntb = score(s, 'b', 'a');
            cnta = score(s, 'a', 'b');
        } 
        return cnta*x + cntb*y;
    }
};


class Solution {
public:
    string removeAB(string s, int x, int& cnt){
        stack<char> stk;
        for(int i=0; i<s.size(); i++){
            if(!stk.empty() && stk.top()=='a' && s[i]=='b'){
                stk.pop();
                cnt += x;
            }
            else{ // ba = 5
                stk.push(s[i]);
            }
        }
        string temp ="";
        while(stk.size()){
            temp += stk.top();
            stk.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

    string removeBA(string s, int y, int& cnt){
        stack<char> stk;
        for(int i=0; i<s.size(); i++){
            if(!stk.empty() && stk.top()=='b' && s[i]=='a'){
                stk.pop();
                cnt += y;
            }
            else{ // ba = 5
                stk.push(s[i]);
            }
        }
        string temp ="";
        while(stk.size()){
            temp += stk.top();
            stk.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int cnt = 0;
        if(x>y){
            s = removeAB(s,x, cnt);
            s = removeBA(s,y, cnt);
        }
        else{
            s = removeBA(s,y, cnt);
            s = removeAB(s,x, cnt);
        }
        return cnt;
    }
    
};

int main(){

    return 0;
}