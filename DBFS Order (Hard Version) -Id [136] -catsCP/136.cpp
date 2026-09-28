//traidepluyenthuattoan - hngocuyen - [136]>> solutions
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=1e9+7;
vector<int> g[3000];
string s;
int D[4][3000][3001],E[4][3000][3001],h[3000],w[3000],k[3000];
ll X[4][3002],Y[4][3002];
void mg(int u,int v,int a,int b,int c){for(int i=0;i<=h[u];i++){ll x=D[a][u][i],y=E[a][u][i];if(!x&&!y)continue;for(int j=0;j<=h[v];j++){int m=max(i,j);X[c][m]=(X[c][m]+x*D[b][v][j])%P;if(i<=j)Y[c][j]=(Y[c][j]+x*E[b][v][j])%P;else Y[c][i]=(Y[c][i]+y*D[b][v][j])%P;}}}
void ad(int v,int a,int c){for(int i=0;i<=h[v];i++){X[c][i]=(X[c][i]+D[a][v][i])%P;Y[c][i]=(Y[c][i]+E[a][v][i])%P;}}
void df(int t){int r=0;for(int p=0;p<4;p++)D[p][t][0]=E[p][t][0]=0;D[0][t][0]=1;h[t]=0;w[t]=0;k[t]=0;
for(int v:g[t])if(s[v]=='0')r++;
for(int v:g[t]){df(v);if(s[v]=='0')r--;
mg(t,v,0,0,0);if(s[v]=='1'){mg(t,v,3,1,2);mg(t,v,3,1,3);}else{mg(t,v,2,1,2);mg(t,v,3,1,3);}
if(!w[t]&&!r&&k[v]){if(!k[t]){k[t]=1;ad(v,2,2);ad(v,3,3);}else{ad(v,2,2);ad(v,2,3);if(s[v]=='1'){ad(v,1,2);ad(v,1,3);}}}
w[t]|=w[v];h[t]=max(h[t],h[v]);
for(int p=0;p<4;p++)for(int i=0;i<=h[t];i++){D[p][t][i]=X[p][i];E[p][t][i]=Y[p][i];X[p][i]=Y[p][i]=0;}}
for(int p=0;p<4;p++)D[p][t][h[t]+1]=E[p][t][h[t]+1]=0;
if(s[t]=='0'){h[t]++;return;}
for(int i=0;i<=h[t];i++){X[0][i+1]=(X[0][i+1]+D[0][t][i])%P;Y[0][i+1]=(Y[0][i+1]+E[0][t][i])%P;}
ll z=0;for(int i=0;i<=h[t];i++)z=(z+D[2][t][i]+P-E[2][t][i])%P;
Y[0][1]=(Y[0][1]+z)%P;h[t]++;k[t]=1;
for(int i=0;i<=h[t];i++){if(s[t]=='1'){D[0][t][i]=D[1][t][i]=X[0][i];E[0][t][i]=E[1][t][i]=Y[0][i];D[2][t][i]=E[2][t][i]=D[3][t][i]=E[3][t][i]=0;}
else{D[0][t][i]=(D[0][t][i]+X[0][i])%P;E[0][t][i]=(E[0][t][i]+Y[0][i])%P;D[1][t][i]=X[0][i];E[1][t][i]=Y[0][i];D[3][t][i]=D[2][t][i];E[3][t][i]=E[2][t][i];D[2][t][i]=(D[2][t][i]+X[0][i])%P;E[2][t][i]=(E[2][t][i]+Y[0][i])%P;}}
if(s[t]=='1')w[t]=1;
for(int i=0;i<=h[t];i++)X[0][i]=Y[0][i]=0;}
int main(){ios::sync_with_stdio(0);cin.tie(0);int T,n;
for(cin>>T;T--;){cin>>n>>s;s='1'+s;for(int i=0;i<n;i++){int c,p;cin>>c;while(c--){cin>>p;g[i].push_back(p-1);}}
df(0);ll a=0;for(int i=0;i<=h[0];i++)a=(a+D[0][0][i]+P-E[0][0][i])%P;
cout<<a<<'\n';for(int i=0;i<n;i++)g[i].clear();}}
