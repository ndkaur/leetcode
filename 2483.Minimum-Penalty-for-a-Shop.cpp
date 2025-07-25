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
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> no, yes;
        no.push_back(0);
        yes.push_back(0);
        int cnt =0;
        for(int i=0; i<n; i++){
            if(customers[i]=='N')
                cnt++;
            no.push_back(cnt);
        }

        cnt=0;
        for(int i=n-1; i>=0; i--){
            if(customers[i]=='Y'){
                cnt++;
            }
            yes.push_back(cnt);
        }
        reverse(yes.begin(), yes.end());
        
        int idx = -1;
        int mn = INT_MAX;
        for(int i=0; i<yes.size(); i++){
            int temp = no[i]+yes[i];
            if(temp<mn){
                mn= temp;
                idx =i;
            }
        }
        return idx;
    }
};


class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int mx = 0;
        int score = 0;
        int idx =-1;
        for(int i=0; i<n; i++){
            if(customers[i]=='Y')
                score++;
            else 
                score--;
            if(score>mx){
                mx = score;
                idx =i;
            }
        }
        return idx+1;
    }
};


int main(){

    return 0;
}