//traidepluyenthuattoan - hngocuyen - [90]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;
typedef unsigned long long U;
const U M=1e9+7;
struct X{U a,b,c,d;};
X mul(const X&p,const X&q){return {(p.a*q.a+p.b*q.c)%M,(p.a*q.b+p.b*q.d)%M,(p.c*q.a+p.d*q.c)%M,(p.c*q.b+p.d*q.d)%M};}
map<int,int> S;
vector<int> K;
vector<X> T;
int Z,W;
void st(int i,X x){i+=Z;T[i]=x;for(i>>=1;i;i>>=1)T[i]=mul(T[2*i+1],T[2*i]);}
int ix(int l){return lower_bound(K.begin(),K.end(),l)-K.begin();}
void tset(int l){
    if(!W){K.push_back(l);return;}
    auto it=S.find(l);
    int r=it->second,q=0;
    if(it!=S.begin())q=prev(it)->second;
    U g=l-q,m=(r-l)/2;
    X x={1,1,(g-1)/2%M,g/2%M};
    X p={1,m%M,0,1};
    st(ix(l),mul(p,x));
}
void tdel(int l){if(W)st(ix(l),{1,0,0,1});}
void nxt(int l){auto it=S.upper_bound(l);if(it!=S.end())tset(it->first);}
void put(int l,int r){S[l]=r;tset(l);nxt(l);}
void rem(int l){S.erase(l);tdel(l);nxt(l);}
void add(int x){
    if(x<0)return;
    if(x==0)x=1;
    auto it=S.upper_bound(x);
    if(it!=S.begin()){
        auto p=prev(it);int l=p->first,r=p->second;
        if(x<=r+1){
            if((x-l)%2==0){
                rem(l);
                if(x>l)put(l+1,x-1);
                add(r+1);add(l-2);
            }else if(x-1==r){
                rem(l);if(r-2>=l)put(l,r-2);
                add(r+2);
            }else{
                put(l,x-1);add(r+1);
            }
            return;
        }
    }
    if(it!=S.end()&&it->first==x+1){int r=it->second;rem(x+1);add(r+1);return;}
    int l=x,r=x;
    if(it!=S.begin()){auto p=prev(it);if(p->second==x-2){l=p->first;}}
    if(it!=S.end()&&it->first==x+2){r=it->second;rem(x+2);}
    put(l,r);
}
char B[1<<22],O[1<<22];int bp,op;
int rd(){while(B[bp]<'0')bp++;int r=0;while(B[bp]>='0')r=r*10+B[bp++]-'0';return r;}
int main(){
    fread(B,1,sizeof(B)-1,stdin);
    int n=rd();
    vector<int> A(n);
    for(int i=0;i<n;i++){A[i]=rd();add(A[i]);}
    sort(K.begin(),K.end());K.erase(unique(K.begin(),K.end()),K.end());
    Z=1;while(Z<(int)K.size())Z<<=1;
    T.assign(2*Z,{1,0,0,1});
    S.clear();W=1;
    for(int i=0;i<n;i++){
        add(A[i]);
        X t=T[1];
        U r=(t.a+t.c)%M;char c[12];int k=0;
        do{c[k++]='0'+r%10;r/=10;}while(r);
        while(k)O[op++]=c[--k];O[op++]='\n';
    }
    fwrite(O,1,op,stdout);
}
