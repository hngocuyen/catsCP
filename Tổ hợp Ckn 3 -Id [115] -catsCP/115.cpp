//traidepluyenthuattoan - hngocuyen - [115]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long U;typedef vector<U> V;
#ifndef T
#define T 1000000
#endif
U P;
U mm(U a,U b){return (unsigned __int128)a*b%P;}
U pw(U a,U e,U m){U r=1;a%=m;while(e){if(e&1)r=(unsigned __int128)r*a%m;a=(unsigned __int128)a*a%m;e>>=1;}return r;}
const U M[4]={998244353,167772161,469762049,754974721},G[4]={3,3,3,11};
void nt(V&a,int n,U m,U g,bool iv){for(int i=1,j=0;i<n;i++){int b=n>>1;for(;j&b;b>>=1)j^=b;j^=b;if(i<j)swap(a[i],a[j]);}for(int l=2;l<=n;l<<=1){U w=pw(g,(m-1)/l,m);if(iv)w=pw(w,m-2,m);int h=l/2;V ws(h);ws[0]=1;for(int i=1;i<h;i++)ws[i]=ws[i-1]*w%m;for(int i=0;i<n;i+=l)for(int j=0;j<h;j++){U u=a[i+j],x=a[i+j+h]*ws[j]%m;a[i+j]=u+x>=m?u+x-m:u+x;a[i+j+h]=u>=x?u-x:u+m-x;}}if(iv){U z=pw(n,m-2,m);for(int i=0;i<n;i++)a[i]=a[i]*z%m;}}
V cv(const V&a,const V&b){int s=a.size()+b.size()-1,n=1;while(n<s)n<<=1;V r[4];for(int t=0;t<4;t++){V x(n,0),y(n,0);for(size_t i=0;i<a.size();i++)x[i]=a[i]%M[t];for(size_t i=0;i<b.size();i++)y[i]=b[i]%M[t];nt(x,n,M[t],G[t],0);nt(y,n,M[t],G[t],0);for(int i=0;i<n;i++)x[i]=x[i]*y[i]%M[t];nt(x,n,M[t],G[t],1);x.resize(s);r[t]=x;}
U i01=pw(M[0],M[1]-2,M[1]),i2=pw(M[0]*M[1]%M[2],M[2]-2,M[2]),i3=pw(M[0]*M[1]%M[3]*M[2]%M[3],M[3]-2,M[3]);U q1=M[0]%P,q2=mm(q1,M[1]%P),q3=mm(q2,M[2]%P);V o(s);
for(int i=0;i<s;i++){U t0=r[0][i];U t1=(r[1][i]+M[1]-t0%M[1])%M[1]*i01%M[1];U z=(t0+t1*M[0])%M[2];U t2=(r[2][i]+M[2]-z)%M[2]*i2%M[2];U y=((t0+t1*M[0])%M[3]+M[0]*M[1]%M[3]*t2)%M[3];U t3=(r[3][i]+M[3]-y)%M[3]*i3%M[3];o[i]=(t0%P+mm(t1,q1)+mm(t2,q2)+mm(t3,q3))%P;}return o;}
V fc,fi;
V sh(const V&h,U a,int m){int d=h.size()-1;V c(d+1);for(int i=0;i<=d;i++){c[i]=mm(mm(h[i],fi[i]),fi[d-i]);if((d-i)&1)c[i]=(P-c[i])%P;}int L=d+m;V e(L),p(L+1),q(L+1);U b=(a+P-(U)d%P)%P;p[0]=1;for(int s=0;s<L;s++){e[s]=(b+s)%P;p[s+1]=mm(p[s],e[s]);}q[L]=pw(p[L],P-2,P);for(int s=L;s>0;s--)q[s-1]=mm(q[s],e[s-1]);V g(L);for(int s=0;s<L;s++)g[s]=mm(p[s],q[s+1]);V r=cv(c,g);V o(m);for(int k=0;k<m;k++)o[k]=mm(r[k+d],mm(p[k+d+1],q[k]));return o;}
U v;V pr;
U fb(U m){U q=m/v,r=pr[q];for(U i=q*v+1;i<=m;i++)r=mm(r,i);return r;}
U fa(U m){if(m>(P-1)/2){U w=fb(P-1-m);U z=pw(w,P-2,P);return (P-1-m)&1?z:(P-z)%P;}return fb(m);}
int main(){int t;scanf("%d",&t);while(t--){U n,k,p;scanf("%llu %llu %llu",&n,&k,&p);P=p;
if(p<T){V f(n+1);f[0]=1;for(U i=1;i<=n;i++)f[i]=f[i-1]*i%p;printf("%llu\n",f[n]*pw(f[k]*f[n-k]%p,p-2,p)%p);continue;}
v=(U)(sqrtl((long double)p)/2);while(4*v*v>p)v--;while(4*(v+1)*(v+1)<=p)v++;
fc.assign(v+2,1);fi.assign(v+2,1);for(U i=1;i<=v+1;i++)fc[i]=mm(fc[i-1],i);fi[v+1]=pw(fc[v+1],P-2,P);for(U i=v+1;i>0;i--)fi[i-1]=mm(fi[i],i);
V f={1,(v+1)%P};U d=1;int hb=63-__builtin_clzll(v);U iv=pw(v,P-2,P);
for(int b=hb-1;b>=0;b--){V A=sh(f,d+1,d+1);U a=mm(d,iv);V B=sh(f,a,d+1),C=sh(f,(a+d+1)%P,d+1);V F=f;F.insert(F.end(),A.begin(),A.end());B.insert(B.end(),C.begin(),C.end());V N(2*d+1);for(U i=0;i<=2*d;i++)N[i]=mm(F[i],B[i]);d*=2;f=N;
if(v>>b&1){for(U i=0;i<=d;i++)f[i]=mm(f[i],(v*i+d+1)%P);U x=1;for(U i=1;i<=d+1;i++)x=mm(x,(v*(d+1)+i)%P);f.push_back(x);d++;}}
U K=(p/2)/v+1;V bs=f;while(f.size()<K+1){V A=sh(bs,f.size(),v+1);f.insert(f.end(),A.begin(),A.end());}
pr.assign(f.size()+1,1);for(size_t i=0;i<f.size();i++)pr[i+1]=mm(pr[i],f[i]);
U r=mm(fa(n),pw(mm(fa(k),fa(n-k)),P-2,P));printf("%llu\n",r);}}
