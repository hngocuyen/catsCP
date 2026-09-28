//traidepluyenthuattoan - hngocuyen - [104]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;
const L B=4e9,F=1e9;
int S;
vector<L> T,P;
void up(int i,L v){i+=S;T[i]=v;for(i>>=1;i;i>>=1)T[i]=min(T[2*i],T[2*i+1]);}
int Z;
L rm(int l){L z=B;if(l>=Z)return B;int r=S+S;for(l+=S;l<r;l>>=1,r>>=1){if(l&1)z=min(z,T[l++]);if(r&1)z=min(z,T[--r]);}return z;}
L Q;
bool pr(int j,L g){L p=j?P[j-1]:-B;return p>=2*Q-g;}
int fd(int v,int lo,int hi,L s){
    if(lo==hi)return pr(lo,min(T[v],s))?lo:lo+1;
    int m=(lo+hi)/2;
    L g=min(T[2*v+1],s);
    if(pr(m+1,g))return fd(2*v,lo,m,g);
    return fd(2*v+1,m+1,hi,s);
}
char bf[1<<16];int bl,bp;
int gc(){if(bp==bl){bl=fread(bf,1,1<<16,stdin);bp=0;if(bl<=0)return -1;}return bf[bp++];}
L rd(){int c=gc();while(c<'0'||c>'9')c=gc();L r=0;while(c>='0'&&c<='9')r=r*10+c-'0',c=gc();return r;}
int main(){
    int n=rd(),k=rd(),q=rd();
    vector<L> x(n),a(n),b(n);vector<int> t(n);
    for(int i=0;i<n;i++)x[i]=rd(),t[i]=rd()-1,a[i]=rd(),b[i]=rd();
    vector<int> o(n);iota(o.begin(),o.end(),0);
    sort(o.begin(),o.end(),[&](int i,int j){return x[i]!=x[j]?x[i]<x[j]:i<j;});
    Z=n+k;S=1;while(S<Z)S<<=1;
    T.assign(2*S,B);P.assign(S,F);
    vector<int> id(n);
    for(int i=0;i<n;i++)id[o[i]]=i,P[i]=x[o[i]];
    vector<set<int>> st(k);
    for(int c=0;c<k;c++){st[c].insert(n+c);up(n+c,-B);}
    vector<int> cn(k,0);int w=0;
    vector<array<L,3>> e;
    for(int i=0;i<n;i++)e.push_back({a[i],1,i}),e.push_back({b[i]+1,0,i});
    vector<L> l(q),y(q),r(q);
    for(int i=0;i<q;i++)l[i]=rd(),y[i]=rd(),e.push_back({y[i],2,i});
    sort(e.begin(),e.end());
    for(auto&v:e){
        int i=v[2];
        if(v[1]==2){
            if(w<k){r[i]=-1;continue;}
            Q=l[i];
            int j=fd(1,0,S-1,B);
            L best=B;
            for(int u=j;u>=max(0,j-1);u--){
                L g=rm(u),p=u?P[u-1]:-B;
                best=min(best,max({p,2*Q-g,Q}));
            }
            r[i]=best-Q;
            continue;
        }
        int c=t[i],d=id[i];
        auto&s=st[c];
        if(v[1]==1){
            auto it=s.insert(d).first;
            auto nx=next(it);
            L pv=it==s.begin()?-B:P[*prev(it)];
            up(d,pv);up(*nx,P[d]);
            if(cn[c]++==0)w++;
        }else{
            auto it=s.find(d);
            auto nx=next(it);
            L pv=it==s.begin()?-B:P[*prev(it)];
            up(*nx,pv);up(d,B);
            s.erase(it);
            if(--cn[c]==0)w--;
        }
    }
    string out;
    for(int i=0;i<q;i++)out+=to_string(r[i])+"\n";
    fputs(out.c_str(),stdout);
}
