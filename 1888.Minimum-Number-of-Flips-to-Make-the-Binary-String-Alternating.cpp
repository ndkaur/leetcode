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


class Solution0 { //O(n^2) // tle 
public:
    int check(string& curr){
        int n = curr.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(i%2!=curr[i]-'0'){
                cnt++;
            }
        }
        return min(cnt, n-cnt);
    }
    int minFlips(string s) {
        int n = s.size();
        string temp = s+s; // for handling the type 1 
        int mn = INT_MAX;
        for(int i=0; i<=temp.size()-n; i++){
            string curr = temp.substr(i,n);
            int cnt = check(curr);
            mn= min(mn, cnt);
        }
        return mn;
    }
};



class Solution1 {  //O(n)
public:
    int minFlips(string s) {
        int n = s.size();
        s+=s; // for handling the type 1 
        // genrate the two possible alternaing strings already 
        // s1 = 0101010
        // s2 = 10101010

        string s1,s2;

        for(int i=0; i<2*n; i++){
            s1+= (i%2==0) ? '0':'1';
            s2+= (i%2==0) ? '1':'0';
        }
        // sliding window 
        int mn = INT_MAX;

        int flip1 =0;
        int flip2=0;
        int i =0;
        int j =0;

        while(j<2*n){
            // s1 check for flip1
            if(s[j]!=s1[j]){
                flip1++;
            }

            if(s[j]!=s2[j]){
                flip2++;
            }

            if(j-i+1>n){// window size change 
                if(s[i]!=s1[i]){
                    flip1--;
                }
                if(s[i]!=s2[i]){ 
                    flip2--;
                }
                i++;
            }

            if(j-i+1==n){
                mn= min({mn, flip1, flip2});
            }
            j++;
        }
        return mn;
    }
};

// bette apporch insted of increasing s size can rotate the pointer back to in a circular manner
class Solution {  //O(n)
public:
    int minFlips(string s) {
        int n = s.size();
    
        // genrate the two possible alternaing strings already 
        // s1 = 0101010
        // s2 = 10101010

        string s1,s2;

        for(int i=0; i<2*n; i++){
            s1+= (i%2==0) ? '0':'1';
            s2+= (i%2==0) ? '1':'0';
        }
        // sliding window 
        int mn = INT_MAX;

        int flip1 =0;
        int flip2=0;
        int i =0;
        int j =0;

        while(j<2*n){
            // s1 check for flip1
            if(s[j%n]!=s1[j]){
                flip1++;
            }

            if(s[j%n]!=s2[j]){
                flip2++;
            }

            if(j-i+1>n){// window size change 
                if(s[i%n]!=s1[i]){
                    flip1--;
                }
                if(s[i%n]!=s2[i]){ 
                    flip2--;
                }
                i++;
            }

            if(j-i+1==n){
                mn= min({mn, flip1, flip2});
            }
            j++;
        }
        return mn;
    }
};



int main(){

    return 0;
}