//traidepluyenthuattoan - hngocuyen - [13]>> solutions
#include <bits/stdc++.h>
using namespace std;
const int M=1000000007;
char s[100010];
int C[1<<17],G[1<<17],U[1<<17],X[1<<17],V[1<<17];
bool ok(int m){
    for(int a=1;a<=9;a++)for(int b=a+1;b<=9;b++)if(((b==a+1&&(a-1)/3==(b-1)/3)||b==a+3)&&m==((1<<a)|(1<<b)))return 1;
    for(int a:{1,2,4,5})if(m==((1<<a)|(1<<(a+1))|(1<<(a+3))|(1<<(a+4))))return 1;
    return 0;
}
int main(){
    int t,k=0;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int n=strlen(s);
        for(int i=0;i<n;i++)s[i]-='0';
        int c=1;
        U[0]=1;V[0]=1;
        for(int i=0;i<n;i++){
            int p=0,q=0,m=0,w=0,e=0;
            for(int l=1;l<=4&&i+l<=n;l++){
                if(m>>s[i+l-1]&1)break;
                m|=1<<s[i+l-1];
                if(l==2&&ok(m))p=1;
                if(l==4&&ok(m))q=1;
            }
            for(int j=max(0,i-3);j<=i+3&&j<n;j++)w|=1<<s[j];
            k++;
            for(int d=1;d<=9;d++){
                if(!(w>>d&1))continue;
                for(int h=0;h<c;h++){
                    int u=U[h],r=0;
                    for(int x=0;x<17;x++){
                        if(!(u>>x&1))continue;
                        if(!x){
                            if(s[i]==d)r|=1;
                            if(p)for(int y=0;y<2;y++)if(s[i+y]==d)r|=1<<(1<<y);
                            if(q)for(int y=0;y<4;y++)if(s[i+y]==d)r|=1<<(2+(1<<y));
                        }else if(x<=2){
                            for(int y=0;y<2;y++)if(!(x>>y&1)&&s[i-1+y]==d)r|=1;
                        }else{
                            int o=x-2,z=__builtin_popcount(o),b=i-z;
                            for(int y=0;y<4;y++)if(!(o>>y&1)&&s[b+y]==d){if(z==3)r|=1;else r|=1<<(2+(o|1<<y));}
                        }
                    }
                    if(!r)continue;
                    if(G[r]!=k){G[r]=k;C[r]=0;X[e++]=r;}
                    C[r]=(C[r]+V[h])%M;
                }
            }
            for(int h=0;h<e;h++){U[h]=X[h];V[h]=C[X[h]];}
            c=e;
        }
        long long a=0;
        for(int h=0;h<c;h++)if(U[h]&1)a+=V[h];
        printf("%lld\n",a%M);
    }
}
