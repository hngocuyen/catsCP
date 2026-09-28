//traidepluyenthuattoan - hngocuyen - [97]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;typedef unsigned long long U;const U Q=1000000007;
struct M{U a,b,c,d;};
map<int,int> B;vector<array<int,3>> op;
void ins(int s,int e){B[s]=e;op.push_back({1,s,e});}
void del(int s){B.erase(s);op.push_back({0,s,0});}
void ad(int a){
    if(a<0)return;if(a==0)a=1;
    auto it=B.upper_bound(a);
    auto nx=it;
    if(it!=B.begin()){
        --it;int s=it->first,e=it->second;
        if(a<=e){
            if((a-s)%2==0){del(s);if(s+1<=a-1)ins(s+1,a-1);ad(e+1);ad(s-2);return;}
            del(s);if(s<=a-3)ins(s,a-3);ins(a+1,e);ad(a+1);return;
        }
        if(e==a-1){del(s);if(s<=e-2)ins(s,e-2);ad(a+1);return;}
    }
    if(nx!=B.end()&&nx->first==a+1){int e=nx->second;del(a+1);ad(e+1);return;}
    int ns=a,ne=a;
    if(nx!=B.end()&&nx->first==a+2){ne=nx->second;del(a+2);}
    auto p=B.upper_bound(a);
    if(p!=B.begin()){--p;if(p->second==a-2){ns=p->first;del(ns);}}
    ins(ns,ne);
}
int K;vector<M> P;vector<int> S,E;
inline void cb(int o){
    int l=2*o,r=l+1;
    if(!S[l]){P[o]=P[r];S[o]=S[r];E[o]=E[r];return;}
    if(!S[r]){P[o]=P[l];S[o]=S[l];E[o]=E[l];return;}
    U d=S[r]-E[l],x=(d-1)/2,y=d/2;
    const M&p=P[l],&q=P[r];
    U a=p.a+p.b,b=(p.a*x+p.b*y)%Q,c=p.c+p.d,dd=(p.c*x+p.d*y)%Q;
    P[o]={(a*q.a+b*q.c)%Q,(a*q.b+b*q.d)%Q,(c*q.a+dd*q.c)%Q,(c*q.b+dd*q.d)%Q};
    S[o]=S[l];E[o]=E[r];
}
static char ib[1<<23];int ip;
int rd(){while(ib[ip]<48)ip++;int x=0;while(ib[ip]>=48)x=x*10+ib[ip++]-48;return x;}
int main(){
    fread(ib,1,sizeof(ib)-1,stdin);int n=rd();
    op.reserve(8*n);
    for(int i=0;i<n;i++){ad(rd());op.push_back({2,0,0});}
    vector<int> k;
    for(auto&z:op)if(z[0]==1)k.push_back(z[1]);
    sort(k.begin(),k.end());k.erase(unique(k.begin(),k.end()),k.end());
    K=1;while(K<(int)k.size())K*=2;
    P.assign(2*K,{1,0,0,1});S.assign(2*K,0);E.assign(2*K,0);
    string o;o.reserve(n*11);char bf[16];
    for(auto&z:op){
        if(z[0]==2){
            const M&m=P[1];U x=(U)((S[1]-1)/2)%Q;
            U r=(m.a+m.b+x*((m.c+m.d)%Q))%Q;
            int l=sprintf(bf,"%llu\n",r);o.append(bf,l);continue;
        }
        int i=lower_bound(k.begin(),k.end(),z[1])-k.begin()+K;
        if(z[0]==1){int e=z[2];P[i]={1,0,(U)((e-z[1])/2),1};S[i]=z[1];E[i]=e;}
        else{P[i]={1,0,0,1};S[i]=0;E[i]=0;}
        for(i>>=1;i;i>>=1)cb(i);
    }
    fputs(o.c_str(),stdout);
}
