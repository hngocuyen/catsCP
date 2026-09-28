//traidepluyenthuattoan - hngocuyen - [32]>> solutions
#include <bits/stdc++.h>
using namespace std;
int n,q;
vector<vector<int>> G;
vector<int> K,D,U,Z,R,A[20],E[20],S,T,P,H,Y,M,B;
int L[100005];
char s[100005];
int c(int v){vector<int> o={v};K[v]=0;for(int i=0;i<(int)o.size();i++){int x=o[i];Z[x]=1;for(int y:G[x])if(y!=K[x]&&!R[y]){K[y]=x;o.push_back(y);}}for(int i=o.size()-1;i>0;i--)Z[K[o[i]]]+=Z[o[i]];return o.size();}
void d(int v,int l){
    int t=c(v);
    while(1){int o=0;for(int x:G[v])if(x!=K[v]&&!R[x]&&Z[x]*2>t){o=x;break;}if(!o)break;v=o;}
    R[v]=1;L[v]=l;
    S[v]=T.size();
    vector<int> Q={v},W={0},F={-1};
    for(int i=0;i<(int)Q.size();i++){int x=Q[i];A[l][x]=v;E[l][x]=W[i];T.push_back(x);P.push_back(W[i]);for(int y:G[x])if(y!=F[i]&&!R[y]){Q.push_back(y);W.push_back(W[i]+1);F.push_back(x);}}
    H[v]=T.size();
    for(int x:G[v])if(!R[x])d(x,l+1);
}
int main(){
    scanf("%d %s",&n,s+1);
    G.resize(n+1);
    for(int i=1;i<n;i++){int a,b;scanf("%d %d",&a,&b);G[a].push_back(b);G[b].push_back(a);}
    D.assign(n+1,-1);U.assign(n+1,-1);Z.assign(n+1,0);K.assign(n+1,0);R.assign(n+1,0);S.assign(n+1,0);H.assign(n+1,0);
    for(int l=0;l<20;l++)A[l].assign(n+1,0),E[l].assign(n+1,0);
    vector<int> o={1};D[1]=0;
    for(int i=0;i<(int)o.size();i++)for(int y:G[o[i]])if(D[y]<0){D[y]=D[o[i]]+1;o.push_back(y);}
    vector<int> w;
    for(int i=1;i<=n;i++)if(s[i]=='0'){U[i]=0;w.push_back(i);}
    for(int i=0;i<(int)w.size();i++)for(int y:G[w[i]])if(U[y]<0){U[y]=U[w[i]]+1;w.push_back(y);}
    for(int i=1;i<=n;i++)if(U[i]<0)U[i]=INT_MAX;
    d(1,0);
    vector<int> V;
    for(int i=n-1;i>=0;i--)if(s[o[i]]=='1')V.push_back(o[i]);
    M.assign(T.size(),0);B.assign(n+1,0);
    scanf("%d",&q);
    while(q--){
        int k;scanf("%d",&k);
        for(int v=1;v<=n;v++){
            int b=INT_MAX;
            for(int i=S[v];i<H[v];i++){int x=T[i];if(U[x]>k&&(b==INT_MAX||D[x]<D[b]))b=x;M[i]=b;}
            B[v]=INT_MAX/2;
        }
        int r=0;
        for(int v:V){
            bool f=0;
            for(int l=0;l<=L[v];l++){int C=A[l][v];if(E[l][v]+B[C]<=k){f=1;break;}}
            if(f)continue;
            int b=INT_MAX;
            for(int l=0;l<=L[v];l++){
                int C=A[l][v],e=k-E[l][v];
                if(e<0)continue;
                int x=upper_bound(P.begin()+S[C],P.begin()+H[C],e)-P.begin()-1;
                int y=M[x];
                if(y!=INT_MAX&&(b==INT_MAX||D[y]<D[b]))b=y;
            }
            if(b==INT_MAX){r=-1;break;}
            r++;
            for(int l=0;l<=L[b];l++){int C=A[l][b];B[C]=min(B[C],E[l][b]);}
        }
        printf("%d\n",r);
    }
}
