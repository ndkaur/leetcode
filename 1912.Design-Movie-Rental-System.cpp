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

// entries => {shop , movie, price}
// required functions -> 

// SEARCH :-  find 5 CHEAP shops that have UN-RENTED movie
// search(movie) -> return = { 5 shop names}

// RENT :- rent(shop, movie) -> unrented become rented  

// DROP :- drop(shop, movie) -> rented become unrented 

// REPORT :-  5 CHEAP RENTED movie 
// report() -> {{shop, movie}}

// now required map/ set 
// to store all info of entries 
// map< int, map<int,int>> entries -> [shop]: [movie]:[price]

// to store unrented movies in cheap order 
// since we are passed with movie id in the search function that has to be the key
// map<int, set<pair<int,int>> unrent  -> [movie] : {price, shop}

// to store rented movies in cheap order
// since no id is passed so we are free to store any way in sorted order acc to price
// set<vector<int>(3)>> rented -> {{price, shop movie}}




class MovieRentingSystem {
public:
    unordered_map<int, unordered_map<int,int>> store; // shop -> movie -> price
    unordered_map<int, set<pair<int,int>>> unrent; // movie -> {price, shop}
    set<array<int,3>> rented; // {price, shop, movie}

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        // any movie is by default unrented 
        for(auto& entry:entries){
            store[entry[0]][entry[1]] = entry[2];
            unrent[entry[1]].insert({entry[2], entry[0]});
        }
    }
    
    vector<int> search(int movie) {
        // { 5 shops that have cheapest price for that movie}
        vector<int> ans;
        for(auto& [price, shop]:unrent[movie]){
            ans.push_back(shop);
            if(ans.size()==5)
                break;
        }
        return ans;
    }
    
    void rent(int shop, int movie) { // rent the unrented movie
        // remove from unrented -> movie { price, shop}
        // add in rented { price, shop, movie}
        // we are given shop movie -> price ? = store 
        int price  = store[shop][movie];
        rented.insert({price, shop, movie});
        unrent[movie].erase(unrent[movie].find({price,shop}));
    }
    
    void drop(int shop, int movie) { // unrent the rented movie 
        // remove from rented {price, shop, movie}
        // add in unrent -> movie { price, shop}
        int price = store[shop][movie];
        rented.erase(rented.find({price, shop, movie}));
        unrent[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        // 5 cheapest rented movie -> { shop, movie}
        vector<vector<int>> ans;
        for(auto& [price, shop, movie]: rented){
            ans.push_back({shop, movie});
            if(ans.size()==5)
                break;
        }
        return ans;
    }
};



int main(){

    return 0;
}