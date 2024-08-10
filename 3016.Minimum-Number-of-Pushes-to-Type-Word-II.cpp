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
    int minimumPushes(string word) {
        int n = word.size();
        map<char, int> mp;
        for(auto ch:word){
            mp[ch]++;
        }
        priority_queue<int> pq;
        for(auto itr:mp){
            pq.push(itr.second);
        }

        
        int ans = 0;
        int cnt = 0;
        
        while(pq.size()){
            int val = pq.top();
            pq.pop();
            // when its 1-8 then we have available space for val 1 
            // after that val 2 will 
            ans += (cnt/8 + 1)* val;
            cnt++;
        }
        return ans;
    }
};

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
      
        map<char, int> mp;
        for(int i=0; i<n; i++){
            mp[word[i]]++;
        }

        vector<int> v;
        // the char that has more frequency use it first , keep it on the one click this will help us in reaching the minimum clicks 
        for(auto itr:mp){
            v.push_back(itr.second);
        }

        sort(v.begin(), v.end(), greater<int>()); // descending order

        int ans = 0;

        for(int i=1; i<=v.size(); i++){
           
            if(i<=8){
                ans = ans + v[i-1]; // 1 click 
            } 
            if(i>8 && i<=16){
                ans = ans + v[i-1]*2;
            }
            if(i>16 && i<=24){
                ans = ans + v[i-1]*3;
            }
            if(i>24){
                ans = ans +v[i-1]*4;
            }
        }
        return ans;
    }
};

//total 8 places can be used
// if the length is less than or queal to 8 we can place each char at the start of each of the 8 keys 
// if it exceeds ie less than 16 , we need to double click to reach at that position of char 
// if the index exceeds 24 then we need to triple click to reach at that position of the char 
// but still we can see that some keys have 4 chars so needs to click 4 times  

// since the length constraints is too much  and the chars can be repeating themselves 
// so use map to store the frequency of each char 


// word = "aabbccddeeffgghhiiiiii"

//  v= {2,2,2,2,2,2,2,2,6}
//  sort = {6,2,2,2,2,2,2,2,2}
// i=1 , 6*1 = 6 ,,, ans =
// i=2 , ans=  6+2 = 8
// i=3, ans= 8+2 = 10
// i=4, ans= 10+2 =12
// i=5 , ans=12+2=14
// i=6, ans= 14+2 = 16
// i=7 , ans=16+2=18 
//i=8 ,ans=18+2 = 20 
// i=9, ans= 20 + 2*4 = 20+4 = 24  




int main(){

    return 0;
}