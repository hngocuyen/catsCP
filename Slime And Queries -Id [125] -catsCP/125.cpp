//traidepluyenthuattoan - hngocuyen - [125]>> solutions
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100000];
int D[100000],S[100000],F[100000],W[100000],P[100000],H[100000],c;
map<int,int> M,G;
void bd(int n){vector<int> o;o.push_back(0);F[0]=-1;H[0]=0;for(int j=0;j<(int)o.size();j++){int t=o[j];for(int y:g[t])if(y!=F[t]){F[y]=t;H[y]=H[t]+1;o.push_back(y);}}
for(int j=n-1;j>=0;j--){int t=o[j];S[t]=1;W[t]=-1;int x=-1;for(int y:g[t])if(y!=F[t]){S[t]+=S[y];if(S[y]>x){x=S[y];W[t]=y;}}}
vector<int> k;k.push_back(0);P[0]=0;c=0;while(k.size()){int t=k.back();k.pop_back();for(int u=t;u!=-1;u=W[u]){D[u]=c++;if(u!=t)P[u]=P[t];for(int y:g[u])if(y!=F[u]&&y!=W[u]){P[y]=y;k.push_back(y);}}}}
void ac(int p){auto i=G.upper_bound(p);i--;int x=i->second;G[p]=x;}
int ck(int k,int v){while(1){auto i=M.upper_bound(v);if(i==M.begin())break;i--;int d=min(i->second,k);k-=d;i->second-=d;if(!i->second)M.erase(i);if(!k)break;}return k;}
int up(int l,int r,int p){int a=0,s,v;ac(l);ac(r);s=l;v=G[l];while(1){auto i=G.upper_bound(l);a+=ck(i->first-s,v);s=i->first;v=i->second;if(i->first==r)break;G.erase(i);}G[l]=p;M[p]+=r-l-a;return a;}
int main(){ios::sync_with_stdio(0);cin.tie(0);int T,n,m,q,i,u,v,p;long long a;
for(cin>>T;T>0;T--){cin>>n>>m>>q;for(i=0;i<n-1;i++){cin>>u>>v;g[u-1].push_back(v-1);g[v-1].push_back(u-1);}
bd(n);G[0]=-1;G[n]=-1;
for(i=0;i<m;i++){cin>>p;p--;ac(D[p]+1);G[D[p]]=0;}
M[0]=m;a=0;
for(i=1;i<=q;i++){u=p;cin>>p;p--;p=(p+a)%n;v=p;
while(1){if(P[u]==P[v]){if(H[v]>H[u])swap(u,v);a+=up(D[v],D[u]+1,i);break;}if(H[P[v]]>H[P[u]])swap(u,v);a+=up(D[P[u]],D[u]+1,i);u=F[P[u]];}
cout<<a<<' ';}
cout<<'\n';for(i=0;i<n;i++)g[i].clear();M.clear();G.clear();}}
