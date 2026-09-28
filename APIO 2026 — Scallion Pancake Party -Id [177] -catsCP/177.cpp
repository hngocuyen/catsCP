//traidepluyenthuattoan - hngocuyen - [177]>> solutions
#include "party.h"
#include <bits/stdc++.h>
using namespace std;
namespace{
int n,g,c,d,e;
vector<int> o;
}
void init(int N,int K,int p,int r){n=N;g=(p+1)%N;c=0;d=0;o.assign(N,0);}
int strategy(int b,int f,int s){
    int j=o[f]++;
    if(f!=g){if(!j&&!d&&!s)c++;return 0;}
    if(!j){d=1;return s;}
    return (c>>(j-1)&1)?s:0;
}
vector<int> guess(int N,int K,vector<int> F,vector<int> S){
    vector<vector<int>> w(N);vector<int> a;
    for(int i=0;i<N*N;i++){if(w[F[i]].empty())a.push_back(F[i]);w[F[i]].push_back(i);}
    vector<int> l;
    for(int f:a){
        int v=0;
        for(int j=1;j<N;j++)if(!S[w[f][j]])v|=1<<(j-1);
        l.insert(l.begin()+v,f);
    }
    vector<int> P(N);
    for(int i=0;i<N;i++)P[i]=(l[i]+N-1)%N;
    return P;
}
