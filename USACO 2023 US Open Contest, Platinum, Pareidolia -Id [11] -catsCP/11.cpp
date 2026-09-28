//traidepluyenthuattoan - hngocuyen - [11]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long L;
struct D{L s[6];L a;int c[6];unsigned char x[6];};
static D T[1<<19];
static char S[200010];
static int M,N;
static const char*W="bessie";
static void f(int i,int p,char h){
    D*d=&T[i];
    for(int j=0;j<6;j++){
        d->c[j]=0;
        if(h==W[j]){
            if(j==5){d->x[j]=0;d->s[j]=N-p;}
            else{d->x[j]=j+1;d->s[j]=0;}
        }else{d->x[j]=j;d->s[j]=0;}
    }
    d->a=d->s[0];
    d->c[d->x[0]]=1;
}
static void g(int i){
    D*d=&T[i],*l=&T[2*i],*r=&T[2*i+1];
    L a=l->a+r->a;
    for(int j=0;j<6;j++){
        int k=l->x[j];
        d->x[j]=r->x[k];
        d->s[j]=l->s[j]+r->s[k];
        d->c[j]=r->c[j];
        a+=(L)l->c[j]*r->s[j];
    }
    for(int j=0;j<6;j++)d->c[r->x[j]]+=l->c[j];
    d->a=a;
}
int main(){
    scanf("%s",S);
    N=strlen(S);
    M=1;while(M<N)M<<=1;
    for(int i=0;i<M;i++){
        if(i<N)f(M+i,i,S[i]);
        else{D*d=&T[M+i];for(int j=0;j<6;j++){d->x[j]=j;d->s[j]=0;d->c[j]=0;}d->a=0;}
    }
    for(int i=M-1;i>=1;i--)g(i);
    printf("%lld\n",T[1].a);
    int u;scanf("%d",&u);
    char b[8];
    for(int q=0;q<u;q++){
        int p;scanf("%d %s",&p,b);p--;
        f(M+p,p,b[0]);
        for(int i=(M+p)>>1;i>=1;i>>=1)g(i);
        printf("%lld\n",T[1].a);
    }
}
