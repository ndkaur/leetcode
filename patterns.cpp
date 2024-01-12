#include "bits/stdc++.h"
using namespace std;
// // #include "Tree.h"
// #define deb(x) cout<<x<<endl;
// const int inf = 1e9;
// typedef vector<int> vi;
// typedef vector<vector<int>> vvi;
// typedef vector<string> vs;
// typedef vector<bool> vb;
// typedef pair<int,int> pii;
// //#include "LinkedList.h"

// void print(vi &out){
//     for(auto x: out) cout<<x<<" ";
//     cout<<endl;
// }

// ..............................................................................................................

// * 
// * * 
// * * * 
// * * * * 
// * * * * * 

// void pyramid(int n){
    //  for(int i = 1; i <= rows; ++i) {
    //     for(int j = 1; j <= i; ++j) {
    //         cout << "* ";
    //     }
    //     cout << "\n";
    // }
//     int i=0;
//     int j=0;
//     while(i<n){
//         while(j<=i){
//             cout<<"*";
//             j++;
//         }
//         j=0;
//         i++;
//         cout<<endl;
//     }
// }

// int main(){
//     int n = 5;
//     pyramid(n);
//     return 0;
// }

// ..................................................................................

// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5


// void numPyramid(int n){
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=i; j++){
//             cout<<j<<" ";
//         }
//         cout<<'\n';
//     }
// }

// int main(){
//     int n = 5;
//     numPyramid(n);
//     return 0;
// }

// .....................................................................

// * * * * *
// * * * *
// * * * 
// * *
// *

// int main(){
//     int n;
//     cout<<"enter n:";
//     cin>>n;
//     for(int i=n; i>=0; i--){
//         for(int j=1; j<=i; j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// ...............................................................

// 1 2 3 4 5
// 1 2 3 4 
// 1 2 3
// 1 2
// 1

// int main(){
//     int n =5;
//     for(int i=n; i>=1; i--){
//         for(int j=1; j<=i; j++){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// ..................................................................

// 1
// 2 3
// 4 5 6
// 7 8 9 10

// int main(){
//     int n = 5;
//     int num =1;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<=i; j++){
//             cout<<num<<" ";
//             num++;
//         }
//         cout<<endl;
//     }
//     return 0;
// }

