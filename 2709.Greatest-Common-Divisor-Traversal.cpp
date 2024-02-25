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



// brute force -> i, j for loop then gcd find -> complecity ->O(N^2) + O log(min(i,j))
// fill adjacency list -> then check 

// optimal :-  use dsu , the one which is in seperated component so not all visited so false 
//  all connnected together -> true 
// go at each num -> find its factor , check for that prime factor if any index already exists 
// already exist then do dsu 
//  prime factor -> 4-> 2*2 so factor 2 we will consider only ones 
// if factor doesnt already exist then its a factor of itself


class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    int total;

    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        total = n;

        for(int i=0; i<n; i++){
            parent[i]=i;
            rank[i] = 1;
        }
    }
    
    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x]= find(parent[x]);
    }

    void unionn(int x, int y){
        x = find(x);
        y = find(y);
        if(x==y)
            return;
        
        if(rank[x]>rank[y]){
            parent[y] = x;
            rank[x]+=rank[y];
        }
        else if(rank[x]<rank[y]){
            parent[x] =  y;
            rank[y] += rank[x];
        }
        else{
            parent[x]=y;
            rank[y] += rank[x];
        }

        total -=1; // after union reduce the total component count
    }

    int mxSize(){
        return total;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        DSU dsu(n);

        int mx = *max_element(nums.begin(), nums.end());
        //  factor array stores {fatcor-> index}
        //  factor =2 -> idd
        // factor =3 -> idx
        vector<int> factor(mx+1, -1);

        for(int i=0; i<n; i++){ //O(n)
        // finding the prime factors of each num 
            for(int prime=2; prime*prime<=nums[i]; prime++){
                // cant divide not a factor
                if(nums[i]%prime!=0)
                    continue;
                // already the factor has a num stored agaist it so same do union 
                // we doing union of indexes 
                
                if(factor[prime]!=-1){ // this curr factor has already an index stored with it 
                    dsu.unionn(factor[prime],i); // so do union of the already stored index and curr index
                }
                else  // no already num stored against factor then store it 
                    factor[prime] = i;
                // now suppose the prime no reaches 4 -> 4= 2*2 and we used 2 already 
                // so its better to reduce the number to its lowest factor 
                while(nums[i]%prime==0){ // eg-> 16->16/2 = 8/2 = 4/2 = 2/2 = 1
                    nums[i] = nums[i]/prime;
                }
            }
            // aftwer all this even if the curr num has a different factor then do for it 
            if(nums[i]>1){  // it can be a prime factor , that means factor of itself , so make a seperate component of itself 
                // eg= 7 , so check if any index stored against it then union if not then make it a seperate component 
                if(factor[nums[i]]!=-1){ 
                    dsu.unionn(factor[nums[i]],i);
                }
                else 
                    factor[nums[i]] = i;
            }
        }
        // all joinded as one component 
        return dsu.mxSize() == 1;
    }
};



int main(){

    return 0;
}