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

// simple bfs with  queue
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<string> q;
        string final = "123450";
        string first = "";
        set<string> visited;

        for(auto row:board){
            for(auto col:row){
                first += col+'0';
            }
        }

        q.push(first);
        visited.insert(first);
        int cnt = 0;

        // checking that when 0 will be at a particular index what all will be its adjacent indexes 
        // 0 ->  1,3
        // 1 ->  0,2,4
        // 2 ->  1,5
        // 3 ->  0,4
        // 4 ->  1,3,5
        // 5 ->  4,2

        vector<vector<int>> indexes =  {{1,3}, {0,2,4} , {1,5}, {0,4}, {1,3,5}, {2,4}};

        while(q.size()){
            int n = q.size();
            while(n--){
                auto str = q.front();
                q.pop();

                if(str==final)
                    return cnt;

                int idx = str.find('0');

                for(auto dir: indexes[idx]){ // swaping all the adjacent indexes
                    string t = str;
                    swap(t[dir], t[idx]);
                    if(!visited.count(t)){
                        visited.insert(t);
                        q.push(t);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};

int main(){

    return 0;
}