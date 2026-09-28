//traidepluyenthuattoan - hngocuyen - [43]>> solutions
#include <bits/stdc++.h>
using namespace std;
using l=long long;
const l I=(1LL<<62);
struct A{l a[5][5];};
A e(){A x;for(int i=0;i<5;i++)for(int j=0;j<5;j++)x.a[i][j]=i==j?0:I;return x;}
A o(A x,A y){A z;for(int i=0;i<5;i++)for(int j=0;j<5;j++)z.a[i][j]=I;for(int i=0;i<5;i++)for(int k=0;k<5;k++)if(x.a[i][k]<I/2)for(int j=0;j<5;j++)if(y.a[k][j]<I/2)z.a[i][j]=min(z.a[i][j],x.a[i][k]+y.a[k][j]);return z;}
A t(int p,l d){A x;for(int i=0;i<5;i++)for(int j=0;j<5;j++)x.a[i][j]=I;if(p==0){x.a[0][0]=d;x.a[4][0]=d;x.a[1][1]=2*d;x.a[4][1]=2*d;x.a[2][2]=d;x.a[3][3]=2*d;x.a[2][4]=0;x.a[3][4]=0;}else if(p==1){x.a[1][2]=d;x.a[3][2]=d;x.a[4][2]=d;x.a[0][3]=2*d;x.a[2][3]=2*d;x.a[4][3]=2*d;for(int i=0;i<5;i++)x.a[i][4]=0;}else{for(int i=0;i<5;i++){x.a[i][2]=d;x.a[i][3]=2*d;x.a[i][4]=0;}}return x;}
struct S{bool z; l p,s; int q; A a;};
S m(S x,S y){if(x.z&&y.z)return {true,0,x.s+y.s,0,e()};if(x.z){y.p+=x.s;return y;}if(y.z){x.s+=y.s;return x;}return {false,x.p,y.s,y.q,o(o(x.a,t(x.q,x.s+y.p)),y.a)};}
S w(S x,l n){S r={true,0,0,0,e()};while(n){if(n&1)r=m(r,x);n>>=1;if(n)x=m(x,x);}return r;}
struct E{l b,r;int c,g;};
vector<l> v;
vector<int> c,g;
vector<S> h;
S f(int i){l d=v[i+1]-v[i];if(c[i])return {false,0,d,c[i]>1?2:1,e()};if(g[i])return {false,0,d,0,e()};return {true,0,d,0,e()};}
void u(int p,int l,int r,int x){if(l==r){h[p]=f(l);return;}int d=(l+r)/2;if(x<=d)u(p*2,l,d,x);else u(p*2+1,d+1,r,x);h[p]=m(h[p*2],h[p*2+1]);}
void b(int p,int l,int r){if(l==r){h[p]=f(l);return;}int d=(l+r)/2;b(p*2,l,d);b(p*2+1,d+1,r);h[p]=m(h[p*2],h[p*2+1]);}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);l M;int n,p;if(!(cin>>M>>n>>p))return 0;vector<E>x;v={0,M};for(int k=0;k<n+p;k++){l L,R;cin>>L>>R;int C=k<n,G=k>=n;l q=L/M,r=L%M,z=R/M;x.push_back({q,r,C,G});x.push_back({z+1,r,-C,-G});v.push_back(r);}sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());int z=v.size()-1;c.assign(z,0);g.assign(z,0);h.resize(4*z+4);b(1,0,z-1);sort(x.begin(),x.end(),[](E a,E b){return a.b<b.b;});S a={true,0,0,0,e()};l y=x[0].b;int i=0;while(i<(int)x.size()){l q=x[i].b;if(q>y)a=m(a,w(h[1],q-y));while(i<(int)x.size()&&x[i].b==q){int j=lower_bound(v.begin(),v.end(),x[i].r)-v.begin();c[j]+=x[i].c;g[j]+=x[i].g;u(1,0,z-1,j);i++;}y=q;}if(a.z){cout<<0<<'\n';return 0;}l r=I;if(a.q==0)r=min(a.a.a[4][2],a.a.a[4][3]);else for(int j=0;j<5;j++)r=min(r,a.a.a[4][j]);cout<<r<<'\n';}
