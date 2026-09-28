//traidepluyenthuattoan - hngocuyen - [129]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;const L NI=-1000000000000000000LL;
int n,k,r;vector<int> g[1005];L w[1005];int cc[1005],cp[1005],cn[1005],C[1005];
void gr(int u,int p){
    int a=1000000,b=0,m=0;
    for(int c:g[u])if(c!=p){gr(c,u);m+=cn[c];a=min(a,cc[c]+1);if(cp[c]>=0)b=max(b,cp[c]+1);}
    if(b>=0&&a+b<=r)b=-1;
    if(b==r){m++;a=0;b=-1;}
    cn[u]=m;cc[u]=a;cp[u]=b;C[u]=m+(b>=0)+1;
}
struct D{int s,h;vector<L> v;L*at(int j){return &v[(size_t)j*(2*h+3)];}};
D go(int u,int p){
    D x;x.s=min(k,1);x.h=0;x.v.assign(2*3,NI);
    L*a=x.at(0);a[2]=0;a[1]=w[u];
    if(k>=1){L*b=x.at(1);b[0]=w[u];}
    for(int c:g[u])if(c!=p){
        D y=go(c,u);
        int yh=min(r,y.h+1),H=max(x.h,yh),W=2*H+3;
        int ys=y.s;
        vector<L> t((size_t)(ys+1)*(2*yh+3),NI);
        for(int j=0;j<=ys;j++){
            L*o=y.at(j),*q=&t[(size_t)j*(2*yh+3)];
            q[2*yh+2]=o[2*y.h+2];
            for(int e=0;e<=y.h;e++){
                if(e+1<=r)q[e+1]=o[e];else q[2*yh+2]=max(q[2*yh+2],o[e]);
                if(e+1<=r)q[yh+1+e+1]=o[y.h+1+e];
            }
        }
        int xs=x.s,zs=min(min(k,C[u]),xs+ys);
        vector<L> z((size_t)(zs+1)*W,NI);
        auto pre=[&](L*o,int h,int mh,vector<L>&SA,vector<L>&PP){
            SA.assign(H+2,NI);PP.assign(H+1,NI);
            for(int e=H;e>=0;e--)SA[e]=max(SA[e+1],e<=h?o[e]:NI);
            for(int e=0;e<=H;e++)PP[e]=max(e?PP[e-1]:NI,e<=h?o[h+1+e]:NI);
        };
        vector<vector<L>> XA(xs+1),XP(xs+1),YA(ys+1),YP(ys+1);
        for(int j=0;j<=xs;j++)pre(x.at(j),x.h,H,XA[j],XP[j]);
        for(int j=0;j<=ys;j++)pre(&t[(size_t)j*(2*yh+3)],yh,H,YA[j],YP[j]);
        for(int i=0;i<=xs;i++){
            L*xo=x.at(i);L xn=xo[2*x.h+2];
            vector<L>&xa=XA[i],&xp=XP[i];
            for(int j=0;j<=ys&&i+j<=zs;j++){
                L*yo=&t[(size_t)j*(2*yh+3)];L yn=yo[2*yh+2];
                vector<L>&ya=YA[j],&yp=YP[j];
                L*zo=&z[(size_t)(i+j)*W];
                zo[2*H+2]=max(zo[2*H+2],xn+yn);
                for(int a=0;a<=H;a++){
                    int m=r-a;if(m>H)m=H;
                    L bx=a<=x.h?xo[a]:NI,by=a<=yh?yo[a]:NI,v=zo[a];
                    if(bx>NI){L c=max(yn,ya[a]);if(m>=0)c=max(c,yp[m]);if(c>NI)v=max(v,bx+c);}
                    if(by>NI){L c=max(xn,xa[a+1]);if(m>=0)c=max(c,xp[m]);if(c>NI)v=max(v,by+c);}
                    zo[a]=v;
                    L px=a<=x.h?xo[x.h+1+a]:NI,py=a<=yh?yo[yh+1+a]:NI;v=zo[H+1+a];
                    int s=r-a+1;if(s<0)s=0;
                    if(px>NI){L c=max(yn,yp[a]);if(s<=H)c=max(c,ya[s]);if(c>NI)v=max(v,px+c);}
                    if(py>NI){L c=max(xn,xp[a]);if(s<=H)c=max(c,xa[s]);if(c>NI)v=max(v,py+c);}
                    zo[H+1+a]=v;
                }
            }
        }
        x.s=zs;x.h=H;x.v.swap(z);
    }
    return x;
}
int main(){
    scanf("%d %d %d",&n,&k,&r);
    for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
    for(int i=0;i<n-1;i++){int u,v;scanf("%d %d",&u,&v);g[u].push_back(v);g[v].push_back(u);}
    gr(1,0);D x=go(1,0);L b=0;
    for(int j=0;j<=x.s;j++){L*o=x.at(j);b=max(b,o[2*x.h+2]);for(int e=0;e<=x.h;e++)b=max(b,o[e]);}
    printf("%lld\n",b);
}
