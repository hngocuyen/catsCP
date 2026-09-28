//traidepluyenthuattoan - hngocuyen - [127]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long Q;const Q P=1e9+7;
Q pw(Q b,Q e){Q r=1;b%=P;while(e){if(e&1)r=r*b%P;b=b*b%P;e>>=1;}return r;}
const int Z=200010;Q f[Z],fi[Z];
Q C(int n,int k){return k<0||k>n||n<0?0:f[n]*fi[k]%P*fi[n-k]%P;}
Q A(int n,int k){return k<0||k>n?0:f[n]*fi[n-k]%P;}
int main(){f[0]=1;for(int i=1;i<Z;i++)f[i]=f[i-1]*i%P;fi[Z-1]=pw(f[Z-1],P-2);for(int i=Z-1;i;i--)fi[i-1]=fi[i]*i%P;
int t;scanf("%d",&t);while(t--){int n,m;scanf("%d %d",&n,&m);
vector<int> ty(2*n+2,0);vector<char> us(2*n+2,0);bool ok=1;int w0=0,k=0,tp=0,ts=0;
for(int i=0;i<m;i++){int p,a,b,r;scanf("%d %d %d %d",&p,&a,&b,&r);if(!r)w0++;
if(a){if(us[a])ok=0;us[a]=1;}if(b){if(us[b])ok=0;us[b]=1;}
if(a&&b){if(a==b)ok=0;else if((a>b)!=(r==0))ok=0;}
else if(a){if(r==0){ty[a]=1;tp++;}else{ty[a]=2;ts++;}}
else if(b){if(r==0){ty[b]=2;ts++;}else{ty[b]=1;tp++;}}
else k++;}
if(!ok){puts("0 0 0");continue;}
int fr=0;for(int v=1;v<=2*n;v++)if(!us[v])fr++;
vector<Q> d(ts+1,0);d[0]=1;int op=0,pd=0,fb=0,g=0;
auto blk=[&](int g){if(!g)return;vector<Q> e(ts+1,0);for(int u=0;u<=ts;u++)if(d[u])for(int y=0;u+y<=op&&y<=g;y++)e[u+y]=(e[u+y]+d[u]*C(op-u,y)%P*A(g,y))%P;d=e;};
for(int v=1;v<=2*n;v++){if(!us[v]){g++;continue;}
blk(g);fb+=g;g=0;
if(ty[v]==1){for(int u=0;u<=ts;u++){Q c=fb-pd-u;d[u]=c>0?d[u]*(c%P)%P:0;}pd++;}
else if(ty[v]==2)op++;}
blk(g);
Q s=d[ts];int rm=fr-tp-ts;
if(rm<2*k){puts("0 0 0");continue;}
s=s*A(rm,2*k)%P*pw(pw(2,k),P-2)%P;int R=rm-2*k,fm=n-m;
s=s*f[R]%P*pw(pw(2,fm),P-2)%P;
Q ra=0,rb=0,rd=0;for(int w=0;w<=fm;w++){Q c=s*C(fm,w)%P;int a=w0+w,b=n-a;if(a>b)ra=(ra+c)%P;else if(b>a)rb=(rb+c)%P;else rd=(rd+c)%P;}
printf("%lld %lld %lld\n",ra,rb,rd);}}
