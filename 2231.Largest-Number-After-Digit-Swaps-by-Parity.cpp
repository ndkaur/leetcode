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

class Solution {  // O(nlogn )
public:
    int largestInteger(int num) {
        string s= to_string(num);
        priority_queue<int> even;
        priority_queue<int> odd;
        for(char &c:s){ // creating pq ->O(nlogn)
            int temp= c-'0'; // cant directly take a char so converted char to int 
            if(temp%2==0)
                even.push(temp);
            else    
                odd.push(temp);
        }
        //  swaping int the original string at respective even odd positions 
        for(char &c:s){
            int temp= c-'0'; // converting char to int 
            if(temp%2==0){
                c= even.top()+'0'; // converting int to char
                even.pop(); // O(logn)
            }
            else{
                c= odd.top()+'0'; //O(1)
                odd.pop();
            }
        }
        return stoi(s);
    }
};

int main(){
    Solution sol;
    int num=1234;
    int ans = sol.largestInteger(num);
    cout<<ans;
    return 0;
}