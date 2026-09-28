//traidepluyenthuattoan - hngocuyen - [143]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;
static char bf[1<<25];int bp,bn;
L rd(){while(bp<bn&&bf[bp]!='-'&&(bf[bp]<'0'||bf[bp]>'9'))bp++;bool g=bf[bp]=='-';if(g)bp++;L x=0;while(bp<bn&&bf[bp]>='0'&&bf[bp]<='9')x=x*10+bf[bp++]-'0';return g?-x:x;}
int main(){
    if(fopen("ROADSIGNS.inp","r")){freopen("ROADSIGNS.inp","r",stdin);freopen("ROADSIGNS.out","w",stdout);}
    bn=fread(bf,1,sizeof(bf),stdin);int n=rd();
    vector<L> A(n+2),B(n+2);
    for(int i=1;i<=n;i++){L x=rd(),a=rd(),b=rd();A[i]=x-a;B[i]=x+b;}
    vector<int> ra(n+2),rb(n+2),ea(n+2),eb(n+2);
    ra[n]=rb[n]=n+1;
    for(int i=n-1;i>=1;i--){ra[i]=A[i+1]==A[i]?ra[i+1]:i+1;rb[i]=B[i+1]==B[i]?rb[i+1]:i+1;}
    for(int t=n;t>=2;t--){
        int s=rb[t];
        ea[t]=s>n?n:(A[s]==A[t-1]?eb[s]:s-1);
        s=ra[t];
        eb[t]=s>n?n:(B[s]==B[t-1]?ea[s]:s-1);
    }
    vector<int> p(n+1),q(n+1);
    int M=0;
    for(int u=1;u<=n;u++){
        p[u]=ra[u]>n?n:ea[ra[u]];
        q[u]=rb[u]>n?n:eb[rb[u]];
        M=max(M,max(p[u],q[u])-u+1);
    }
    L c=0;bool f=false;
    for(int u=1;u+M-1<=n;u++){
        int v=u+M-1;
        if(ra[u]>v||rb[u]>v){f=true;break;}
        bool x=p[u]>=v,y=q[u]>=v;
        if(x&&y)c+=(A[u]==A[rb[u]]&&B[ra[u]]==B[u])?1:2;
        else c+=x+y;
    }
    if(f)printf("%d -1\n",M);else printf("%d %lld\n",M,c);
}
