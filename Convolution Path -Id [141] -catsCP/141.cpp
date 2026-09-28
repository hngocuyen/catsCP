//traidepluyenthuattoan - hngocuyen - [141]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef unsigned int U;typedef unsigned long long L;
const U P=998244353;int D;
struct V{U a[16];};
V one(){V r;for(int i=0;i<16;i++)r.a[i]=1;return r;}
inline void mul(V&x,const V&y){for(int i=0;i<D;i++)x.a[i]=(L)x.a[i]*y.a[i]%P;}
V add(V x,const V&y){for(int i=0;i<D;i++){x.a[i]+=y.a[i];if(x.a[i]>=P)x.a[i]-=P;}return x;}
void wht(V&x){for(int l=1;l<D;l<<=1)for(int i=0;i<D;i+=2*l)for(int j=i;j<i+l;j++){U u=x.a[j],v=x.a[j+l];x.a[j]=u+v>=P?u+v-P:u+v;x.a[j+l]=u>=v?u-v:u+P-v;}}
static char B[1<<25];int bp,bl;inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}inline U rd(){int c=gc();while(c<48)c=gc();U x=0;while(c>=48){x=x*10+c-48;c=gc();}return x;}
int n,m,K,q,T;vector<V> sg,cy,val;vector<int> par,hv,hd,ps,idx,co,cl,sz;
V qs(int l,int r){V s=one();for(l+=T,r+=T+1;l<r;l>>=1,r>>=1){if(l&1)mul(s,sg[l++]);if(r&1)mul(s,sg[--r]);}return s;}
void us(int p,const V&v){p+=T;sg[p]=v;for(p>>=1;p;p>>=1){sg[p]=sg[2*p];mul(sg[p],sg[2*p+1]);}}
V qc(int s,int l,int r){V x=one();if(l>r)return x;int o=co[s],c=cl[s];for(l+=c,r+=c+1;l<r;l>>=1,r>>=1){if(l&1)mul(x,cy[o+l++]);if(r&1)mul(x,cy[o+--r]);}return x;}
void uc(int s,int p,const V&v){int o=co[s],c=cl[s];p+=c;cy[o+p]=v;for(p>>=1;p;p>>=1){cy[o+p]=cy[o+2*p];mul(cy[o+p],cy[o+2*p+1]);}}
V arcT(int s,int c){int i=idx[c];return add(qc(s,0,i-1),qc(s,i+1,cl[s]-1));}
V arcB(int s,int a,int b){int i=idx[a],j=idx[b];if(i>j)swap(i,j);V x=qc(s,j+1,cl[s]-1);mul(x,val[par[s]]);mul(x,qc(s,0,i-1));return add(qc(s,i+1,j-1),x);}
void fs(int s){us(ps[s],arcT(s,hv[s]));}
int lca(int u,int v){while(hd[u]!=hd[v]){if(ps[hd[u]]<ps[hd[v]])swap(u,v);u=par[hd[u]];}return ps[u]<ps[v]?u:v;}
int climb(int x,int l,V&r){if(x==l)return -1;while(1){if(hd[x]==hd[l]){mul(r,qs(ps[l]+1,ps[x]));return hv[l];}int h=hd[x];mul(r,qs(ps[h],ps[x]));int c=h;x=par[h];if(x==l)return c;if(x>n){mul(r,arcT(x,c));c=x;x=par[x];if(x==l)return c;}}}
int main(){n=rd();m=rd();K=rd();q=rd();D=1<<K;vector<vector<pair<int,int>>> g(n+1);vector<int> ea(m),eb(m);
for(int i=0;i<m;i++){ea[i]=rd();eb[i]=rd();g[ea[i]].push_back({eb[i],i});g[eb[i]].push_back({ea[i],i});}
vector<int> dp(n+1,-1),dq(n+1,0),pe(n+1,-1),it(n+1,0),st;dp[1]=0;st.push_back(1);
while(st.size()){int x=st.back();if(it[x]<(int)g[x].size()){auto [y,e]=g[x][it[x]++];if(dp[y]<0){dp[y]=dp[x]+1;dq[y]=x;pe[y]=e;st.push_back(y);}}else st.pop_back();}
int N=n+m+1;par.assign(N,0);idx.assign(N,0);co.assign(N,0);cl.assign(N,0);vector<char> ic(n+1,0);int S=n;int tot=0;
for(int e=0;e<m;e++){int a=ea[e],b=eb[e];if(pe[a]==e||pe[b]==e||a==b)continue;if(dp[a]>dp[b])swap(a,b);vector<int> w;for(int x=b;x!=a;x=dq[x])w.push_back(x);reverse(w.begin(),w.end());int s=++S;par[s]=a;cl[s]=w.size();co[s]=tot;tot+=2*w.size();for(int i=0;i<(int)w.size();i++){par[w[i]]=s;idx[w[i]]=i;ic[w[i]]=1;}}
for(int x=2;x<=n;x++)if(!ic[x])par[x]=dq[x];
T=S;vector<vector<int>> ch(T+1);for(int x=2;x<=T;x++)ch[par[x]].push_back(x);
vector<int> od;od.push_back(1);for(int i=0;i<(int)od.size();i++)for(int y:ch[od[i]])od.push_back(y);
sz.assign(T+1,1);hv.assign(T+1,0);for(int i=T-1;i>0;i--){int x=od[i];sz[par[x]]+=sz[x];}
for(int x=1;x<=T;x++){int b=0;for(int y:ch[x])if(!b||sz[y]>sz[b])b=y;hv[x]=b;}
hd.assign(T+1,0);ps.assign(T+1,0);int cn=0;st.clear();st.push_back(1);hd[1]=1;
while(st.size()){int x=st.back();st.pop_back();ps[x]=cn++;for(int y:ch[x])if(y!=hv[x]){hd[y]=y;st.push_back(y);}if(hv[x]){hd[hv[x]]=hd[x];st.push_back(hv[x]);}}
val.assign(n+1,one());for(int x=1;x<=n;x++){V v;for(int j=0;j<D;j++)v.a[j]=rd();wht(v);val[x]=v;}
sg.assign(2*T,one());cy.assign(tot+1,one());
for(int x=1;x<=n;x++){sg[T+ps[x]]=val[x];if(par[x]>n)cy[co[par[x]]+cl[par[x]]+idx[x]]=val[x];}
for(int s=n+1;s<=S;s++){int o=co[s],c=cl[s];for(int p=c-1;p>0;p--){cy[o+p]=cy[o+2*p];mul(cy[o+p],cy[o+2*p+1]);}}
for(int s=n+1;s<=S;s++)sg[T+ps[s]]=arcT(s,hv[s]);
for(int p=T-1;p>0;p--){sg[p]=sg[2*p];mul(sg[p],sg[2*p+1]);}
U iv=1;{L b=D,e=P-2,r=1;while(e){if(e&1)r=r*b%P;b=b*b%P;e>>=1;}iv=r;}
string out;char bf[16];
while(q--){int t=rd();if(t==1){int u=rd();V v;for(int j=0;j<D;j++)v.a[j]=rd();wht(v);val[u]=v;us(ps[u],v);if(par[u]>n){int s=par[u];uc(s,idx[u],v);fs(s);}}
else{int u=rd(),v=rd(),k=rd();int l=lca(u,v);V r=one();int a=climb(u,l,r),b=climb(v,l,r);if(l<=n)mul(r,val[l]);else mul(r,arcB(l,a,b));
L z=0;for(int j=0;j<D;j++)z+=__builtin_popcount(j&k)&1?P-r.a[j]:r.a[j];z=z%P*iv%P;snprintf(bf,16,"%llu\n",z);out+=bf;}}
fputs(out.c_str(),stdout);}
