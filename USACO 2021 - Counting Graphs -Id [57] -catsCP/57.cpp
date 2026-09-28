//traidepluyenthuattoan - hngocuyen - [57]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;const ll P=1e9+7;
ll Q(ll b,ll e){b%=P;if(b<0)b+=P;ll r=1;while(e){if(e&1)r=r*b%P;b=b*b%P;e>>=1;}return r;}
ll C[205][205],T[20005];
int main(){for(int i=0;i<205;i++){C[i][0]=1;for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;}T[0]=1;for(int i=1;i<20005;i++)T[i]=T[i-1]*2%P;
int t;scanf("%d",&t);while(t--){int n,m;scanf("%d %d",&n,&m);vector<vector<int>>g(n);for(int i=0;i<m;i++){int x,y;scanf("%d %d",&x,&y);x--;y--;g[x].push_back(y);if(x!=y)g[y].push_back(x);}
vector<int>d(2*n,-1);deque<int>q;d[0]=0;q.push_back(0);while(q.size()){int s=q.front();q.pop_front();int v=s>>1,p=s&1;for(int u:g[v]){int z=u*2+(p^1);if(d[z]<0){d[z]=d[s]+1;q.push_back(z);}}}
bool b=true;for(int v=0;v<n;v++)if(d[2*v]<0||d[2*v+1]<0)b=false;
if(!b){vector<ll>c(2*n+2,0);for(int v=0;v<n;v++)c[max(d[2*v],d[2*v+1])]++;ll r=1;for(int i=1;i<2*n+2;i++)r=r*Q(T[c[i-1]]-1,c[i])%P;printf("%lld\n",r);continue;}
map<pair<int,int>,int>k;int w=0;for(int v=0;v<n;v++){int a=min(d[2*v],d[2*v+1]),e=max(d[2*v],d[2*v+1]);k[{a,e}]++;w=max(w,a+e);}
auto N=[&](int a,int e){if(a<0)return 0;auto I=k.find({a,e});return I==k.end()?0:I->second;};
ll r=1;for(int S=1;S<=w;S+=2){int h=(S-1)/2;vector<ll>f(2,0);int x=N(0,S);if(x)f[1]=1;else f[0]=1;
for(int a=1;a<=h;a++){int y=N(a,S-a),z=N(a-1,S-a-1);ll u=(T[z]-1+P)%P;vector<ll>o(y+1,0);
for(int j=0;j<=x;j++)if(f[j])for(int K=0;K<=y;K++){ll s=0;for(int i=0;i<=j;i++){ll v=C[j][i]*Q(T[x-i]-1,K)%P*T[(x-i)*(y-K)]%P;s=(i&1)?s-v:s+v;}s%=P;if(s<0)s+=P;o[K]=(o[K]+f[j]*C[y][K]%P*Q(u,y-K)%P*s)%P;}
f=o;x=y;}
ll s=0;for(int j=0;j<=x;j++){ll z=0;for(int i=0;i<=j;i++){ll v=C[j][i]*T[(x-i)*(x-i+1)/2]%P;z=(i&1)?z-v:z+v;}z%=P;if(z<0)z+=P;s=(s+f[j]*z)%P;}
r=r*s%P;}
printf("%lld\n",r);}}
