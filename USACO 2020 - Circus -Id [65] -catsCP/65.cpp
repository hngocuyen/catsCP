//traidepluyenthuattoan - hngocuyen - [65]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;const L P=1e9+7;
int n,p[100005];vector<int>g[100005];L F[100005],I[100005],c[100005],o[100005],b[100005],s[100005];
int f(int x){while(p[x]!=x)x=p[x]=p[p[x]];return x;}
L pw(L a,L e){L r=1;while(e){if(e&1)r=r*a%P;a=a*a%P;e>>=1;}return r;}
int main(){if(fopen("circus.in","r")){freopen("circus.in","r",stdin);freopen("circus.out","w",stdout);}scanf("%d",&n);for(int i=1;i<n;i++){int a,b;scanf("%d %d",&a,&b);g[a].push_back(b);g[b].push_back(a);}
F[0]=1;for(int i=1;i<=n;i++)F[i]=F[i-1]*i%P;I[n]=pw(F[n],P-2);for(int i=n;i>0;i--)I[i-1]=I[i]*i%P;
vector<vector<pair<int,int>>>M(n+2),G(n+2);vector<int>R;
for(int v=1;v<=n;v++)if(g[v].size()>2){p[v]=v;c[v]=1;R.push_back(v);for(int w:g[v]){int u=v,x=w,l=1;while(g[x].size()==2){int y=g[x][0]==u?g[x][1]:g[x][0];u=x;x=y;l++;}if(g[x].size()>2){o[v]++;if(v<x&&l<=n)M[l].push_back({v,x});}else{b[v]++;if(l<=n)G[l].push_back({v,0});}}}
vector<L>A(n+1);for(int k=n;k>=1;k--){int e=n-k;L r=F[k];if(e>=2&&R.size()){int l=e-2;for(auto[u,v]:M[l]){int a=f(u),z=f(v);p[z]=a;c[a]+=c[z]+l-1;o[a]+=o[z]-2;b[a]+=b[z];s[a]+=s[z];}for(auto[u,t]:G[l]){int a=f(u);b[a]--;s[a]+=l;}
if(M[l].size()){vector<int>T;for(int x:R)if(p[x]==x)T.push_back(x);R=T;}
for(int x:R){L q=c[x]+s[x]+(b[x]+o[x])*(e-1)-e;if(q>1)r=r*I[q]%P;}}
A[k]=r;}for(int k=1;k<=n;k++)printf("%lld\n",A[k]);
}
