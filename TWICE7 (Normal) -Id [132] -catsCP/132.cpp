//traidepluyenthuattoan - hngocuyen - [132]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;const L D=1000000007;
struct M{L a,b,c,d;};M I={1,0,0,1};
M ml(const M&x,const M&y){return {(x.a*y.a+x.b*y.c)%D,(x.a*y.b+x.b*y.d)%D,(x.c*y.a+x.d*y.c)%D,(x.c*y.b+x.d*y.d)%D};}
map<L,L> B;vector<L> tc,ks;int g,sz;vector<M> t;
bool in(L x){auto i=B.upper_bound(x);if(i==B.begin())return 0;--i;return i->second>=x&&(x-i->first)%2==0;}
map<L,L>::iterator fd(L x){auto i=B.upper_bound(x);--i;return i;}
void er(L s){B.erase(s);tc.push_back(s);}
void st(L s,L e){B[s]=e;tc.push_back(s);}
void pu(L s,L e){if(in(s-2)){auto i=fd(s-2);L z=i->first;er(z);s=z;}auto j=B.find(e+2);if(j!=B.end()){L z=j->second;er(e+2);e=z;}st(s,e);}
void ad(L k){if(k<=-1)return;if(k==0)k=1;
if(in(k+1)){auto i=fd(k+1);L s=i->first,b=i->second;if(s==k+1)er(s);else st(s,k-1);pu(b+1,b+1);return;}
if(in(k-1)){auto i=fd(k-1);L s=i->first;if(s==k-1)er(s);else st(s,k-3);ad(k+1);return;}
if(in(k)){auto i=fd(k);L a=i->first,b=i->second;er(a);if(k<b){if(k>a)st(a+1,k-1);pu(b+1,b+1);}else pu(a+1,k+1);ad(a-2);return;}
pu(k,k);}
void rf(L x){if(!g){ks.push_back(x);return;}int p=lower_bound(ks.begin(),ks.end(),x)-ks.begin();M m=I;auto i=B.find(x);if(i!=B.end()){L pe=0;if(i!=B.begin()){auto j=prev(i);pe=j->second;}L d=x-pe;M a={1,1,(d-1)/2%D,d/2%D};M c={1,(i->second-x)/2%D,0,1};m=ml(c,a);}
p+=sz;t[p]=m;for(p>>=1;p;p>>=1)t[p]=ml(t[2*p+1],t[2*p]);}
int n;vector<L> A;
void run(){B.clear();for(int i=0;i<n;i++){tc.clear();ad(A[i]);for(L x:tc){rf(x);auto j=B.upper_bound(x);if(j!=B.end())rf(j->first);}if(g)printf("%lld\n",(t[1].a+t[1].c)%D);}}
int main(){scanf("%d",&n);A.resize(n);for(auto&x:A)scanf("%lld",&x);g=0;run();sort(ks.begin(),ks.end());ks.erase(unique(ks.begin(),ks.end()),ks.end());sz=1;while(sz<(int)ks.size())sz<<=1;t.assign(2*sz,I);g=1;run();}
