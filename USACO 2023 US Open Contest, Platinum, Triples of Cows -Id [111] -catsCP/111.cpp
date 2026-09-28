//traidepluyenthuattoan - hngocuyen - [111]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;
int n;vector<int> d,pe,W;vector<L> s,T,A,B;vector<vector<int>> g,ch;
int fd(int x){while(d[x]!=x){d[x]=d[d[x]];x=d[x];}return x;}
L f(int k){return s[k]*(s[k]-1)*(s[k]-2)+2*(s[k]-1)*T[k];}
L h(int w){return A[w]*A[w]-B[w];}
int main(){
    scanf("%d",&n);int m=2*n;
    g.assign(n+1,{});ch.assign(n+1,{});d.resize(m);iota(d.begin(),d.end(),0);pe.assign(n+1,0);W.assign(m,0);s.assign(m,0);T.assign(m,0);A.assign(n+1,0);B.assign(n+1,0);
    for(int i=0;i<n-1;i++){int u,v;scanf("%d %d",&u,&v);g[u].push_back(v);g[v].push_back(u);}
    vector<int> q={1},p(n+1,0);p[1]=-1;int c=n;
    for(int i=0;i<(int)q.size();i++){int u=q[i];for(int v:g[u])if(v!=p[u]){p[v]=u;int e=++c;pe[v]=e;W[e]=u;ch[u].push_back(e);s[e]=2;q.push_back(v);}}
    for(int u=1;u<=n;u++){A[u]=B[u]=ch[u].size();}
    L r=0;
    for(int v=2;v<=n;v++){T[pe[v]]=A[v];}
    for(int e=n+1;e<=c;e++)r+=f(e);
    for(int u=1;u<=n;u++)r+=h(u);
    string o;char bf[24];
    for(int i=1;i<=n;i++){
        int l=sprintf(bf,"%lld\n",r);o.append(bf,l);
        int kp=i!=1?fd(pe[i]):-1,w=0,kw=-1;
        r-=h(i);
        L ns=0,nt=0,os=0;
        for(int e:ch[i]){int k=fd(e);r-=f(k);ns+=s[k]-1;nt+=T[k];}
        if(kp>=0){
            r-=f(kp);w=W[kp];os=s[kp];ns+=s[kp]-1;nt+=T[kp]-A[i];
            if(w){r-=h(w);if(w!=1){kw=fd(pe[w]);r-=f(kw);}}
        }
        int rt=kp>=0?kp:i;
        for(int e:ch[i])d[fd(e)]=rt;
        d[i]=rt;
        s[rt]=ns;T[rt]=nt;W[rt]=kp>=0?w:0;
        if(w){
            L x=ns-1,y=os-1;A[w]+=x-y;B[w]+=x*x-y*y;
            r+=h(w);if(kw>=0){T[kw]+=x-y;r+=f(kw);}
        }
        r+=f(rt);
    }
    fputs(o.c_str(),stdout);
}
