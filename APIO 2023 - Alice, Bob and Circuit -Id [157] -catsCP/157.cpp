//traidepluyenthuattoan - hngocuyen - [157]>> solutions
#include "abc.h"
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> V;
typedef array<int,16> W;
typedef array<int,21> Q;
static int pw(int n){int t=1;while(t<n)t<<=1;return t;}
static int C(int n){int t=pw(n),c=0;for(int k=2;k<=t;k<<=1)for(int j=k/2;j;j>>=1)c+=t/2;return c;}
static int E(const char*s){int r=0,z=0;for(int k=0;k<4;k++){if(!s[k])z=1;r=r*32+(z?0:s[k]-96);}return r;}
static void S(int t,V k,bool*o,int&p){for(int K=2;K<=t;K<<=1)for(int j=K/2;j;j>>=1)for(int i=0;i<t;i++){int l=i^j;if(l>i){bool s=(i&K)?k[i]<k[l]:k[i]>k[l];if(s)swap(k[i],k[l]);o[p++]=s;}}}
int alice(const int n,const char nm[][5],const unsigned short a[],bool o[]){
V d(n);iota(d.begin(),d.end(),0);stable_sort(d.begin(),d.end(),[&](int x,int y){return E(nm[x])<E(nm[y]);});
int p=0;for(int j=0;j<n;j++){int c=E(nm[d[j]]);for(int b=0;b<20;b++)o[p++]=c>>b&1;for(int b=0;b<16;b++)o[p++]=a[d[j]]>>b&1;}
int t=pw(n);V k(t);for(int j=0;j<t;j++)k[j]=j<n?d[j]:j;S(t,k,o,p);return p;}
int bob(const int m,const char s[][5],const char r[][5],bool o[]){
V x(m),y(m);iota(x.begin(),x.end(),0);iota(y.begin(),y.end(),0);
stable_sort(x.begin(),x.end(),[&](int a,int b){return E(s[a])<E(s[b]);});
stable_sort(y.begin(),y.end(),[&](int a,int b){return E(r[a])<E(r[b]);});
int p=0;for(int i=0;i<m;i++){int c=E(s[x[i]]);for(int b=0;b<20;b++)o[p++]=c>>b&1;}
for(int i=0;i<m;i++){int c=E(r[y[i]]);for(int b=0;b<20;b++)o[p++]=c>>b&1;}
V q(m);for(int i=0;i<m;i++)q[y[i]]=i;int t=pw(m);V k(t);for(int i=0;i<t;i++)k[i]=i<m?q[x[i]]:i;S(t,k,o,p);return p;}
static int *O,(*P)[2],G;
static int F(int p,int x,int y){return p>>(x+2*y)&1;}
static int U(int q,int x){if(x<0)return q>>(-1-x)&1?-2:-1;if(q==0)return -1;if(q==3)return -2;if(q==2)return x;O[G]=5;P[G][0]=x;P[G][1]=x;return G++;}
static int g(int p,int x,int y){
if(x<0&&y<0)return F(p,-1-x,-1-y)?-2:-1;
if(x<0)return U(F(p,-1-x,0)|F(p,-1-x,1)<<1,y);
if(y<0)return U(F(p,0,-1-y)|F(p,1,-1-y)<<1,x);
if(x==y)return U(F(p,0,0)|F(p,1,1)<<1,x);
O[G]=p;P[G][0]=x;P[G][1]=y;return G++;}
static int X(int a,int b){return g(6,a,b);}
static int A(int a,int b){return g(8,a,b);}
static int R(int a,int b){return g(14,a,b);}
static void Sw(int s,int&a,int&b){int d=A(X(a,b),s);a=X(a,d);b=X(b,d);}
static void Sw(int s,W&a,W&b){for(int i=0;i<16;i++)Sw(s,a[i],b[i]);}
static void M(int t,vector<Q>&k,vector<W>&w,V&z){for(int j=t/2;j;j>>=1)for(int i=0;i<t;i++)if(!(i&j)){int l=i+j,r=-1;for(int b=0;b<21;b++){int e=X(k[i][b],k[l][b]);r=X(r,A(e,X(k[i][b],r)));}for(int b=0;b<21;b++)Sw(r,k[i][b],k[l][b]);Sw(r,w[i],w[l]);z.push_back(r);}}
static void B(int t,vector<W>&w,V&z){int p=z.size();for(int j=1;j<t;j<<=1)for(int i=t-1;i>=0;i--)if(!(i&j))Sw(z[--p],w[i],w[i+j]);}
static void N(int t,vector<W>&w,int p){for(int K=2;K<=t;K<<=1)for(int j=K/2;j;j>>=1)for(int i=0;i<t;i++){int l=i^j;if(l>i)Sw(p++,w[i],w[l]);}}
int circuit(const int la,const int lb,int op[],int od[][2],int oc[][16]){
O=op;P=od;G=la+lb;int n=0,m=0;while(36*n+C(n)!=la)n++;while(40*m+C(m)!=lb)m++;
if(!n)return G;
int t=pw(n+m);Q h;h.fill(-2);W e;e.fill(-1);
vector<Q> k(t,h);vector<W> w(t,e);V z;
for(int j=0;j<n;j++){k[j][0]=-1;for(int b=0;b<20;b++)k[j][b+1]=36*j+b;for(int b=0;b<16;b++)w[j][b]=36*j+20+b;}
for(int p=0;p<m;p++){for(int b=0;b<20;b++)k[t-1-p][b+1]=la+20*p+b;}
M(t,k,w,z);
for(int i=1;i<t;i++)for(int b=0;b<16;b++)w[i][b]=R(w[i][b],A(k[i][0],w[i-1][b]));
B(t,w,z);
int u=pw(m);vector<W> y(u,e);for(int p=0;p<m;p++)y[p]=w[t-1-p];
N(u,y,la+40*m);
k.assign(t,h);w.assign(t,e);z.clear();
for(int q=0;q<m;q++){k[q][0]=-1;for(int b=0;b<20;b++)k[q][b+1]=la+20*m+20*q+b;w[q]=y[q];}
for(int j=0;j<n;j++){for(int b=0;b<20;b++)k[t-1-j][b+1]=36*j+b;}
M(t,k,w,z);
for(int i=1;i<t;i++){int c=-1;for(int b=0;b<16;b++){int a=g(2,w[i-1][b],k[i-1][0]),x=X(a,w[i][b]),d=w[i][b];w[i][b]=X(x,c);if(b<15)c=R(A(a,d),A(x,c));}}
B(t,w,z);
int v=pw(n);vector<W> r(v,e);for(int j=0;j<n;j++)r[j]=w[t-1-j];
N(v,r,36*n);
int c0=-1,c1=-1;
for(int i=0;i<n;i++)for(int b=0;b<16;b++){int x=r[i][b];if(x==-1){if(c0<0){O[G]=0;P[G][0]=0;P[G][1]=0;c0=G++;}x=c0;}else if(x==-2){if(c1<0){O[G]=15;P[G][0]=0;P[G][1]=0;c1=G++;}x=c1;}oc[i][b]=x;}
return G;}
