//traidepluyenthuattoan - hngocuyen - [123]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=100005,Z=6000000;
int n,q,Lc[Z],Rc[Z],w,up[17][M],dp[M],tin[M],tout[M],sz[M],eu[M],T[M],E[M];ll S[Z];vector<int> g[M];
int ins(int p,int l,int r,int k,ll v){int t=++w;Lc[t]=Lc[p];Rc[t]=Rc[p];S[t]=S[p]+v;if(l<r){int m=(l+r)/2;if(k<=m)Lc[t]=ins(Lc[p],l,m,k,v);else Rc[t]=ins(Rc[p],m+1,r,k,v);}return t;}
int lca(int a,int b){if(dp[a]<dp[b])swap(a,b);for(int k=16;k>=0;k--)if(dp[a]-(1<<k)>=dp[b])a=up[k][a];if(a==b)return a;for(int k=16;k>=0;k--)if(up[k][a]!=up[k][b])a=up[k][a],b=up[k][b];return up[0][a];}
int jmp(int a,int d){for(int k=16;k>=0;k--)if(d>>k&1)a=up[k][a];return a;}
bool anc(int a,int b){return tin[a]<=tin[b]&&tout[b]<=tout[a];}
vector<pair<int,int>> R;int pp;ll pv;
ll pre(int y){pair<int,int> cc[8];int cn=R.size();for(int i=0;i<cn;i++)cc[i]=R[i];span<pair<int,int>> c(cc,cn);ll s=0;int l=1,r=n;if(y<1)return 0;while(1){if(r<=y){for(auto&[t,f]:c)s+=f*S[t];if(pp>=l&&pp<=r)s+=pv;return s;}int m=(l+r)/2;if(y<=m){for(auto&[t,f]:c)t=Lc[t];r=m;}else{for(auto&[t,f]:c)s+=f*S[Lc[t]],t=Rc[t];if(pp>=l&&pp<=m)s+=pv;l=m+1;}}}
int kth(ll k,ll&b){pair<int,int> cc[8];int cn=R.size();for(int i=0;i<cn;i++)cc[i]=R[i];span<pair<int,int>> c(cc,cn);int l=1,r=n;b=0;while(l<r){int m=(l+r)/2;ll s=0;for(auto&[t,f]:c)s+=f*S[Lc[t]];if(pp>=l&&pp<=m)s+=pv;if(k<=s){for(auto&[t,f]:c)t=Lc[t];r=m;}else{k-=s;b+=s;for(auto&[t,f]:c)t=Rc[t];l=m+1;}}return l;}
void iv(int a,int b){if(a<=b)R.push_back({E[b+1],1}),R.push_back({E[a],-1});}
void grp(int x,int r,int L,int p){R.clear();pp=0;pv=0;if(p==L){int c1=x!=L?jmp(x,dp[x]-dp[L]-1):0,c2=r!=L?jmp(r,dp[r]-dp[L]-1):0;vector<pair<int,int>> v;if(c1)v.push_back({tin[c1],tout[c1]});if(c2)v.push_back({tin[c2],tout[c2]});sort(v.begin(),v.end());int s=0;for(auto[a,b]:v){iv(s,a-1);s=b+1;}iv(s,n-1);return;}
int o=anc(p,x)?x:r;if(o==p){iv(tin[p],tout[p]);return;}int c=jmp(o,dp[o]-dp[p]-1);iv(tin[p],tin[c]-1);iv(tout[c]+1,tout[p]);}
int main(){scanf("%d %d",&n,&q);for(int i=1;i<n;i++){int u,v;scanf("%d %d",&u,&v);g[u].push_back(v);g[v].push_back(u);}
vector<int> o;o.push_back(1);up[0][1]=1;vector<int> it(n+1,0);int tm=0;tin[1]=tm++;eu[0]=1;vector<int> st={1};
while(st.size()){int x=st.back();if(it[x]<(int)g[x].size()){int y=g[x][it[x]++];if(y==up[0][x]&&x!=1)continue;if(y==up[0][x])continue;up[0][y]=x;dp[y]=dp[x]+1;tin[y]=tm;eu[tm++]=y;o.push_back(y);st.push_back(y);}else{tout[x]=tm-1;st.pop_back();}}
for(int k=1;k<17;k++)for(int i=1;i<=n;i++)up[k][i]=up[k-1][up[k-1][i]];
for(int i=1;i<=n;i++)sz[i]=tout[i]-tin[i]+1;
for(int i=0;i<n;i++)E[i+1]=ins(E[i],1,n,eu[i],1);
T[0]=0;for(int x:o){int p=x==1?0:up[0][x];int t=ins(p?T[p]:0,1,n,x,sz[x]);if(p)t=ins(t,1,n,p,-sz[x]);T[x]=t;}
while(q--){int t;scanf("%d",&t);if(t==1){int r,x,y;scanf("%d %d %d",&r,&x,&y);int L=lca(x,r);int a=lca(x,y),b=lca(y,r),p=L;if(dp[a]>dp[p])p=a;if(dp[b]>dp[p])p=b;
R={{T[x],1},{T[r],1},{T[L],-2}};pp=L;pv=n;ll s=pre(p-1);grp(x,r,L,p);s+=pre(y-1);printf("%lld\n",(ll)(x-1)*n+s+1);}
else{int r;ll k;scanf("%d %lld",&r,&k);int x=(k-1)/n+1;ll m=k-(ll)(x-1)*n;int L=lca(x,r);R={{T[x],1},{T[r],1},{T[L],-2}};pp=L;pv=n;ll b;int p=kth(m,b);m-=b;grp(x,r,L,p);int y=kth(m,b);printf("%d %d\n",x,y);}}}
