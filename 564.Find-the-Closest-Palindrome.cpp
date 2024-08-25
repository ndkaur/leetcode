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
    string nearestPalindromic(string n) {
        int sz = n.size();
        // single digit num 
        if(sz==1){ // 9 ->8
            return to_string(stoi(n)-1);
        }

        vector<long> temp; // 5 possible palindromes will be added to this vector
        // eg = 99 => 9, 101 
        // case1-> the ans is one digit extra than num 99 ->101
        temp.push_back(pow(10,sz)+1);

        // case2-> the ans is one digit less length than num 99 -> 9
        temp.push_back(pow(10, sz-1)-1);

        // case3 -> when length remains same 
        // eg = 1234 = 1221, 1331, 1111 
        int mid = (sz+1)/2;
        long prefix = stol(n.substr(0,mid));

        // case 3.1 -> mid digit remains same , and do mirror copy 
        // case 3.2 -> mid digit increase by 1, and do mirror copy
        // case 3.3 -> mid digit decrease by 1, and do mirror copy
        vector<long> arr = {prefix, prefix+1, prefix-1};

        for(long a:arr){
            string postfix = to_string(a);
            if(sz%2!=0){ // not even , 123 -> 121 
                postfix.pop_back();
            }
            // 1234 -> prefix = 12, postfix = 21
            reverse(postfix.begin(), postfix.end()); 
            // newval = prefix+postfix
            string newVal = to_string(a)+postfix; // 12+21 = 1221
            temp.push_back(stol(newVal));
        }

        // till here the temp vector will be filled with all the possible palindromic num
        long mnDiff = LONG_MAX;
        long ans;
        long num = stol(n);
        for(int i=0; i<5; i++){
            // finding the min diff val
            if(temp[i]!=num && abs(temp[i]-num)<mnDiff){
                mnDiff = abs(temp[i]-num);
                ans = temp[i];
            }
            //we got two same min diff values, compare them and take the smaller one
            else if(abs(temp[i]-num)==mnDiff){
                ans = min(ans, temp[i]);
            }
        }

        return to_string(ans);
    }
};


int main(){

    return 0;
}