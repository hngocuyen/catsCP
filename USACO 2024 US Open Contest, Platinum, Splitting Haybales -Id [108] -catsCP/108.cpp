//traidepluyenthuattoan - hngocuyen - [108]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=400005;
int L[M],R[M],P[M],W[M],D[M],c,rt;ll K[M],Z[M];mt19937 G(7);
void pd(int t){if(Z[t]){for(int u:{L[t],R[t]})if(u)K[u]+=Z[t],Z[u]+=Z[t];Z[t]=0;}}
void up(int t){if(L[t])P[L[t]]=t;if(R[t])P[R[t]]=t;}
int mg(int a,int b){if(!a||!b)return a|b;if(W[a]>W[b]){pd(a);R[a]=mg(R[a],b);up(a);return a;}pd(b);L[b]=mg(a,L[b]);up(b);return b;}
void sp(int t,ll v,int&a,int&b){if(!t){a=b=0;return;}pd(t);if(K[t]<=v){sp(R[t],v,R[t],b);a=t;up(a);}else{sp(L[t],v,a,L[t]);b=t;up(b);}}
int f(int x){while(D[x]!=x)x=D[x]=D[D[x]];return x;}
void ad(int t,ll v){if(t)K[t]+=v,Z[t]+=v;}
int ins(int u,ll v){int t=rt;while(t){pd(t);if(K[t]==v){D[u]=t;return t;}t=v<K[t]?L[t]:R[t];}K[u]=v;L[u]=R[u]=Z[u]=0;int a,b;sp(rt,v,a,b);rt=mg(mg(a,u),b);P[rt]=0;return u;}
vector<int> V;
void cl(int t){if(!t)return;pd(t);cl(L[t]);cl(R[t]);V.push_back(t);}
ll rd(){int c=getchar();while(c!=45&&(c<48||c>57))c=getchar();int g=0;if(c==45)g=1,c=getchar();ll x=0;while(c>=48&&c<=57)x=x*10+c-48,c=getchar();return g?-x:x;}
ll gv(int t){ll s=K[t];t=P[t];while(t)s+=Z[t],t=P[t];return s;}
int main(){int n=rd(),q;vector<ll>a(n+1);for(int i=1;i<=n;i++)a[i]=rd();q=rd();vector<vector<int>>S(n+2),E(n+2);vector<ll>X(q),O(q);vector<int>I(q);for(int i=0;i<q;i++){int l=rd(),r=rd();X[i]=rd();S[l].push_back(i);E[r].push_back(i);}
for(int i=1;i<=n;i++){for(int j:S[i]){int u=++c;D[u]=u;W[u]=G();I[j]=ins(u,X[j]);}ll v=a[i];int A1,A2,B,C,D2,D1,t;sp(rt,-2*v,A1,t);sp(t,-v,A2,t);sp(t,0,B,t);sp(t,v,C,t);sp(t,2*v,D2,D1);ad(A1,v);ad(C,-v);ad(B,v);ad(D1,-v);rt=mg(mg(A1,C),mg(B,D1));P[rt]=0;V.clear();ad(A2,v);ad(D2,-v);cl(A2);cl(D2);for(int u:V){L[u]=R[u]=0;ins(u,K[u]);}
for(int j:E[i])O[j]=gv(f(I[j]));}
for(int i=0;i<q;i++)printf("%lld\n",O[i]);}
