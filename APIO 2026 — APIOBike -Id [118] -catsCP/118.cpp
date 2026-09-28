//traidepluyenthuattoan - hngocuyen - [118]>> solutions
#include "bike.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<vector<int>,vector<ll>> find_rebalancing_strategy(int n,vector<int> A,vector<int> B,vector<int> U,vector<int> V){
vector<vector<int>> g(n);for(int i=0;i<n-1;i++)g[U[i]].push_back(V[i]),g[V[i]].push_back(U[i]);vector<ll> d(n);int tz=0;for(int i=0;i<n;i++)d[i]=(ll)A[i]-B[i],tz+=d[i]!=0;
vector<int> p(n,-1),o,z(n);vector<ll> s(n);auto bf=[&](int r){o.clear();p.assign(n,-1);o.push_back(r);p[r]=r;for(size_t i=0;i<o.size();i++){int x=o[i];for(int y:g[x])if(p[y]<0)p[y]=x,o.push_back(y);}p[r]=-1;for(int x:o)s[x]=d[x],z[x]=d[x]!=0;for(int i=n-1;i>0;i--){int x=o[i];s[p[x]]+=s[x];z[p[x]]+=z[x];}};
bf(0);auto in=[&](int c){return z[c]>0&&tz-z[c]>0;};
vector<int> di(n),dq(n),sv(n),ev(n);int bs=-1,bt=-1,bb=0;
for(int i=n-1;i>=0;i--){int x=o[i];int a1=0,a2=0,c1=-1,c2=-1,e1=x,e2=x,b1=0,b2=0,f1=-1,f2=-1,h1=x,h2=x;
for(int c:g[x])if(c!=p[x]&&in(c)){int w=di[c]+(s[c]>=0?1:-1);if(w>a1)a2=a1,c2=c1,e2=e1,a1=w,c1=c,e1=sv[c];else if(w>a2)a2=w,c2=c,e2=sv[c];w=dq[c]+(s[c]<=0?1:-1);if(w>b1)b2=b1,f2=f1,h2=h1,b1=w,f1=c,h1=ev[c];else if(w>b2)b2=w,f2=c,h2=ev[c];}
di[x]=a1;sv[x]=e1;dq[x]=b1;ev[x]=h1;int v,q,r;if(c1!=f1||c1<0)v=a1+b1,q=e1,r=h1;else if(a1+b2>=a2+b1)v=a1+b2,q=e1,r=h2;else v=a2+b1,q=e2,r=h1;if(v>bb)bb=v,bs=q,bt=r;}
if(bs<0){for(int i=0;i<n;i++)if(d[i]){bs=bt=i;break;}}
bf(bs);vector<int> P;for(int x=bt;x>=0;x=p[x])P.push_back(x);reverse(P.begin(),P.end());vector<char> on(n,0);for(int x:P)on[x]=1;
vector<vector<int>> ch(n);for(int x=0;x<n;x++){for(int c:g[x])if(c!=p[x]&&!on[c]&&z[c]>0)ch[x].push_back(c);stable_partition(ch[x].begin(),ch[x].end(),[&](int c){return s[c]>=0;});}
vector<int> X;vector<ll> Y;auto E=[&](int v,ll y){X.push_back(v);Y.push_back(y);};
vector<pair<int,int>> st;auto D=[&](int c){st.push_back({c,0});E(c,-max(0LL,d[c]));while(st.size()){auto&[x,k]=st.back();if(k<(int)ch[x].size()){int y=ch[x][k++];st.push_back({y,0});E(y,-max(0LL,d[y]));}else{if(d[x]<0)Y.back()+=-d[x];int w=x;st.pop_back();if(st.size())E(st.back().first,0);(void)w;}}};
auto PO=[&](int v){Y.back()+=-max(0LL,d[v]);for(int c:ch[v])if(s[c]>=0){D(c);E(v,0);}};
auto NE=[&](int v){for(int c:ch[v])if(s[c]<0){D(c);E(v,0);}if(d[v]<0)Y.back()+=-d[v];};
int m=P.size()-1;vector<ll> h(m+1);for(int i=0;i<=m;i++){ll t=d[P[i]];for(int c:ch[P[i]])t+=s[c];h[i]=t+(i?h[i-1]:0);}
E(P[0],0);int i=0;while(i<=m){if(i==m||h[i]>=0){PO(P[i]);NE(P[i]);if(i<m)E(P[i+1],0);i++;}else{int a=i,b=i;while(h[b]<0)b++;for(int j=a;j<b;j++){PO(P[j]);E(P[j+1],0);}PO(P[b]);NE(P[b]);for(int j=b-1;j>=a;j--){E(P[j],0);NE(P[j]);}for(int j=a+1;j<=b;j++)E(P[j],0);if(b<m)E(P[b+1],0);i=b+1;}}
return {X,Y};}
