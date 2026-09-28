//traidepluyenthuattoan - hngocuyen - [110]>> solutions
#include <bits/stdc++.h>
using namespace std;
const int Z=1100005;
int pa[Z],lc[Z],rc[Z],sz[Z],ac[Z],pr[Z],lb[Z],nc;mt19937 R(3);
void U(int t){sz[t]=ac[t]+sz[lc[t]]+sz[rc[t]];pa[lc[t]]=t;pa[rc[t]]=t;}
void S(int t,int k,int&a,int&b){if(!t){a=b=0;return;}if(sz[lc[t]]+ac[t]<=k){S(rc[t],k-sz[lc[t]]-ac[t],rc[t],b);a=t;}else{S(lc[t],k,a,lc[t]);b=t;}U(t);}
int M(int a,int b){if(!a||!b)return a|b;if(pr[a]>pr[b]){rc[a]=M(rc[a],b);U(a);return a;}lc[b]=M(a,lc[b]);U(b);return b;}
int N(){nc++;pr[nc]=R();ac[nc]=sz[nc]=1;return nc;}
int n,q,f,T[1<<21],B;
void W(int i,int v){i+=B;T[i]=v;for(i>>=1;i;i>>=1)T[i]=max(T[2*i],T[2*i+1]);}
int X(int l,int r){int s=0;for(l+=B,r+=B+1;l<r;l>>=1,r>>=1){if(l&1)s=max(s,T[l++]);if(r&1)s=max(s,T[--r]);}return s;}
int Lf(int o,int l,int r,int b,int m){if(l>b||T[o]<=m)return 0;if(l==r)return l;int d=(l+r)/2;int x=Lf(2*o+1,d+1,r,b,m);return x?x:Lf(2*o,l,d,b,m);}
int Rt(int o,int l,int r,int a,int m){if(r<a||T[o]<=m)return 0;if(l==r)return l;int d=(l+r)/2;int x=Rt(2*o,l,d,a,m);return x?x:Rt(2*o+1,d+1,r,a,m);}
char Bf[1<<16];int bp,bl;int C(){if(bp==bl){bl=fread(Bf,1,sizeof Bf,stdin);bp=0;if(bl<=0)return -1;}return Bf[bp++];}
int G(){int c=C();while(c<'0'||c>'9')c=C();int r=0;while(c>='0'&&c<='9'){r=r*10+c-'0';c=C();}return r;}
int main(){
if(FILE*h=fopen("vi.inp","r")){fclose(h);freopen("vi.inp","r",stdin);freopen("vi.out","w",stdout);}
G();n=G();q=G();f=G();
vector<int> p(n+1),id(n+1),w(n+1);
for(int i=1;i<=n;i++){p[i]=G();w[p[i]]=i;}
int rt=0;for(int v=1;v<=n;v++){int t=N();id[w[v]]=t;rt=M(rt,t);}pa[rt]=0;vector<int> id0=id;
vector<char> ty(q);vector<int> a(q),c(q),nd(q);
for(int i=0;i<q;i++){int h=C();while(h!='U'&&h!='G')h=C();ty[i]=h;if(h=='U'){a[i]=G();c[i]=G();int x,y;int o=id[a[i]];ac[o]=0;for(int u=o;u;u=pa[u])U(u);pa[0]=0;S(rt,c[i]-1,x,y);int t=N();nd[i]=t;
rt=M(M(x,t),y);pa[rt]=0;id[a[i]]=t;
}else a[i]=G();}
int k=0;vector<int> st;int u=rt;while(u||st.size()){while(u){st.push_back(u);u=lc[u];}u=st.back();st.pop_back();lb[u]=++k;u=rc[u];}
B=1;while(B<n+2)B<<=1;
for(int i=1;i<=n;i++)T[B+i]=lb[id0[i]];for(int i=B-1;i;i--)T[i]=max(T[2*i],T[2*i+1]);
string out;
for(int i=0;i<q;i++){if(ty[i]=='U')W(a[i],lb[nd[i]]);else{int x=a[i],r;
if(x==f)r=1;else if(x>f){int m=X(f+1,x);int j=f>1?Lf(1,0,B-1,f-1,m):0;r=1+(x-f)+(f-1-j);}
else{int m=X(x,f-1);int j=f<n?Rt(1,0,B-1,f+1,m):0;if(!j)j=n+1;r=1+(f-x)+(j-f-1);}
out+=to_string(r);out+=char(10);}}
fputs(out.c_str(),stdout);return 0;}
