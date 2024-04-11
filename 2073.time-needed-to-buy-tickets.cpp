/*
 * @lc app=leetcode id=2073 lang=cpp
 *
 * [2073] Time Needed to Buy Tickets
 */
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

// @lc code=start


class Solution0 {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            q.push({tickets[i], i});
        }

        int time = 0;
        while(q.size()){
            auto val = q.front().first;
            auto idx = q.front().second;
            q.pop();

            val = val-1;
            time++;

            if(idx==k && val==0){ 
                break;
            }
            else if(val!=0){
                q.push({val,idx});
            }
        }
        return time;
    }
};


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;

        for(int i=0; i<n; i++){
            if(i<=k){ 
                time += min(tickets[i], tickets[k]); 
            }
            else{
                time += min(tickets[i], tickets[k]-1);
            }
        }
        return time;
    }
};


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n= tickets.size();
        int steps=0;
        while(true){
            for(int i=0;i<n;i++){
                if(tickets[i]==0) 
                    continue;
                tickets[i]--;
                steps++;
                if(tickets[k]==0)
                    return steps;
            }
        }
    }
};

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n= tickets.size();
        queue<int> q;
        for(int i:tickets)
            q.push(i);
        int ans =0;
        int idx=k; // to store the changing value of k 
        while(true){
            ans++; // each time ans increasing cause of push pop operations 
            // if its not 1 then we will reduce the val and pop it and push it at the back 
            if(q.front()>1){
                q.front()--;
                q.push(q.front());
            }
            else if(idx==0)
                break;
            q.pop();
            // when the front element gets poped out then all elemnts move one step ahead so the kth ele will also move 
            idx--;
            if(idx<0){ // if idx was 0 and then became -1 so the element will reach at the last of queue 
                idx= q.size()-1;
            }
        }
        return ans;
    }
};

// @lc code=end


int main(){

    return 0;
}