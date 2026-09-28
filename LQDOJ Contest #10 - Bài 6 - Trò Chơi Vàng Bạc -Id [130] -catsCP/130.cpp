//traidepluyenthuattoan - hngocuyen - [130]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long U;
int M[1502][3002];U B[1502][48];
int main(){int c,q;scanf("%d %d",&c,&q);vector<long long> A(q),C(q);int m=0;vector<vector<array<int,3>>> W(3001);
for(int k=0;k<q;k++){int n;scanf("%d",&n);for(int j=0;j<n;j++){int f;long long g;scanf("%d %lld",&f,&g);if(c==0||g>=(long long)c*f){A[k]^=f;C[k]^=g-(long long)c*f;}else{W[f].push_back({(int)(g/c),k,(int)(g%c)});m=max(m,f);}}}
memset(M,-1,sizeof M);vector<vector<pair<int,int>>> K(6005);vector<pair<int,int>> r;r.reserve(3001);
for(int t=1;t<=m;t++){for(auto&e:K[t])if(M[e.first][e.second]==t-1)B[e.first][e.second>>6]|=1ULL<<(e.second&63);
for(int a=0;2*a<=t-1;a++){int n=t-1-2*a;if(M[a][n]<t)B[a][n>>6]|=1ULL<<(n&63);}
r.clear();
for(int a=0;2*a<t;a++){int L=t-2*a;for(int w=0;w*64<L;w++){U x=B[a][w];while(x){int b=__builtin_ctzll(x);x&=x-1;r.push_back({a,w*64+b});}}}
for(auto&z:W[t]){auto p=r[z[0]];A[z[1]]^=p.first;C[z[1]]^=(long long)p.second*c+z[2];}
for(int i=0;i<(int)r.size();i++){int a=r[i].first,n=r[i].second,v=t+i;B[a][n>>6]&=~(1ULL<<(n&63));if(v>M[a][n]){M[a][n]=v;K[v+1].push_back({a,n});}}}
for(int k=0;k<q;k++)puts((A[k]||C[k])?"Yes":"No");}
