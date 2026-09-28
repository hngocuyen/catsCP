//traidepluyenthuattoan - hngocuyen - [122]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef double D;
const D P2=2*acos(-1.0);
vector<D> X,Y,R;
typedef vector<pair<D,int>> V;
V mg(const V&a,const V&b){
    V o;int i=0,j=0,n=a.size(),m=b.size();
    while(i<n&&j<m){
        D l=max(a[i].first,b[j].first);
        D ra=i+1<n?a[i+1].first:P2,rb=j+1<m?b[j+1].first:P2,r=min(ra,rb);
        int p=a[i].second,q=b[j].second;
        if(r>l){
            D c[4];int k=0;c[k++]=l;
            D A=X[p]-X[q],B=Y[p]-Y[q],C=R[q]-R[p],S=hypot(A,B);
            if(S>0&&fabs(C)<=S){
                D f=atan2(B,A),g=acos(C/S);
                D u[2]={f+g,f-g};
                for(D z:u){z=fmod(z,P2);if(z<0)z+=P2;if(z>l&&z<r)c[k++]=z;}
                if(k==3&&c[1]>c[2])swap(c[1],c[2]);
            }
            c[k]=r;
            for(int e=0;e<k;e++){
                D md=(c[e]+c[e+1])/2;int w=A*cos(md)+B*sin(md)>=C?p:q;
                if(o.empty()||o.back().second!=w)o.push_back({c[e],w});
            }
        }
        if(ra<rb)i++;else if(rb<ra)j++;else{i++;j++;}
    }
    return o;
}
V sv(int l,int r){
    if(r-l==1)return V{{0.0,l}};
    int m=(l+r)/2;return mg(sv(l,m),sv(m,r));
}
char*B;
D rd(){
    while(*B&&*B!='-'&&*B!='.'&&(*B<'0'||*B>'9'))B++;
    int g=0;if(*B=='-'){g=1;B++;}
    long long a=0;while(*B>='0'&&*B<='9')a=a*10+*B++-'0';
    D v=a;if(*B=='.'){B++;long long f=0,d=1;while(*B>='0'&&*B<='9'){if(d<1e17){f=f*10+*B-'0';d*=10;}B++;}v+=(D)f/d;}
    if(*B=='e'||*B=='E'){B++;int t=0,u=0;if(*B=='-'){u=1;B++;}else if(*B=='+')B++;while(*B>='0'&&*B<='9')t=t*10+*B++-'0';v*=pow(10.0,u?-t:t);}
    return g?-v:v;
}
int main(){
    vector<pair<D,D>> Q;
    static char b[1<<25];b[fread(b,1,(1<<25)-1,stdin)]=0;B=b;
    int n=rd(),m=rd();
    for(int i=0;i<n;i++){D x=rd(),y=rd(),r=rd();X.push_back(x);Y.push_back(y);R.push_back(r);}
    for(int i=0;i<m;i++){int p=rd();while(p--){D x=rd(),y=rd();Q.push_back({x,y});}}
    sort(Q.begin(),Q.end());Q.erase(unique(Q.begin(),Q.end()),Q.end());
    int z=Q.size();vector<pair<D,D>> H(2*z+2);int k=0;
    auto cr=[&](pair<D,D>o,pair<D,D>a,pair<D,D>b){return (a.first-o.first)*(b.second-o.second)-(a.second-o.second)*(b.first-o.first);};
    for(int i=0;i<z;i++){while(k>=2&&cr(H[k-2],H[k-1],Q[i])<=0)k--;H[k++]=Q[i];}
    for(int i=z-2,t=k+1;i>=0;i--){while(k>=t&&cr(H[k-2],H[k-1],Q[i])<=0)k--;H[k++]=Q[i];}
    if(z>1)k--;else k=z;
    for(int i=0;i<k;i++){X.push_back(H[i].first);Y.push_back(H[i].second);R.push_back(0);}
    V v=sv(0,X.size());D s=0;
    for(size_t i=0;i<v.size();i++){
        D l=v[i].first,r=i+1<v.size()?v[i+1].first:P2;int k=v[i].second;
        s+=X[k]*(sin(r)-sin(l))-Y[k]*(cos(r)-cos(l))+R[k]*(r-l);
    }
    printf("%.9f\n",s);
}
