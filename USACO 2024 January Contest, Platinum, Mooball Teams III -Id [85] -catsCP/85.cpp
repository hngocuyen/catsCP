//traidepluyenthuattoan - hngocuyen - [85]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;const ll P=1e9+7;int n;vector<ll>W,I,s1,s2,m1,m2;vector<int>B;
void ap(int x,ll a,ll b){s1[x]=s1[x]*a%P;s2[x]=s2[x]*b%P;m1[x]=m1[x]*a%P;m2[x]=m2[x]*b%P;}
void pd(int x){if(m1[x]!=1||m2[x]!=1){ap(2*x,m1[x],m2[x]);ap(2*x+1,m1[x],m2[x]);m1[x]=m2[x]=1;}}
void st(int x,int l,int r,int p,ll a,ll b){if(l==r){s1[x]=a;s2[x]=b;return;}pd(x);int m=(l+r)/2;if(p<=m)st(2*x,l,m,p,a,b);else st(2*x+1,m+1,r,p,a,b);s1[x]=(s1[2*x]+s1[2*x+1])%P;s2[x]=(s2[2*x]+s2[2*x+1])%P;}
void mu(int x,int l,int r,int a,int b){if(b<l||r<a)return;if(a<=l&&r<=b){ap(x,2,4);return;}pd(x);int m=(l+r)/2;mu(2*x,l,m,a,b);mu(2*x+1,m+1,r,a,b);s1[x]=(s1[2*x]+s1[2*x+1])%P;s2[x]=(s2[2*x]+s2[2*x+1])%P;}
pair<ll,ll> qs(int x,int l,int r,int a,int b){if(b<l||r<a)return{0,0};if(a<=l&&r<=b)return{s1[x],s2[x]};pd(x);int m=(l+r)/2;auto u=qs(2*x,l,m,a,b),v=qs(2*x+1,m+1,r,a,b);return{(u.first+v.first)%P,(u.second+v.second)%P};}
int bq(int i){int s=0;for(;i>0;i-=i&-i)s+=B[i];return s;}void ba(int i){for(;i<=n;i+=i&-i)B[i]++;}
ll f(vector<int>&y){B.assign(n+1,0);s1.assign(4*n,0);s2.assign(4*n,0);m1.assign(4*n,1);m2.assign(4*n,1);ll r=0;
 for(int X=1;X<=n;X++){int p=y[X];int c=bq(p-1);r=(r+W[c]*((W[n-X-p+1+c]-1+P)%P))%P;if(p<n){auto q=qs(1,1,n,p+1,n);r=(r+q.second*W[n-X+2]%P-q.first+P)%P;}st(1,1,n,p,W[c],W[2*c]*I[p]%P);if(p<n)mu(1,1,n,p+1,n);ba(p);}
 return r;}
int main(){scanf("%d",&n);vector<int>x(n),yy(n);for(int i=0;i<n;i++)scanf("%d %d",&x[i],&yy[i]);vector<int>o(n);iota(o.begin(),o.end(),0);vector<int>rx(n),ry(n);sort(o.begin(),o.end(),[&](int a,int b){return x[a]<x[b];});for(int i=0;i<n;i++)rx[o[i]]=i+1;sort(o.begin(),o.end(),[&](int a,int b){return yy[a]<yy[b];});for(int i=0;i<n;i++)ry[o[i]]=i+1;
 W.assign(2*n+5,1);I.assign(2*n+5,1);ll h=(P+1)/2;for(int i=1;i<2*n+5;i++){W[i]=W[i-1]*2%P;I[i]=I[i-1]*h%P;}
 vector<int>y(n+1),z(n+1);for(int i=0;i<n;i++){y[rx[i]]=ry[i];z[rx[i]]=n+1-ry[i];}
 ll s=0;for(int k=1;k<=n;k++)s=(s+W[k-1]*(W[n-k]-1))%P;
 ll a=(4*s-2*(f(y)+f(z)))%P;a=(a%P+P)%P;printf("%lld\n",a);}
