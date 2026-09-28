//traidepluyenthuattoan - hngocuyen - [8]>> solutions
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char S[8005];
int P[8005],C[16010];
int main(){
    scanf("%s",S);
    int n=strlen(S),k=0;
    P[0]=-1;
    for(int i=0;i<n;i++)if(S[i]=='G')P[++k]=i;
    P[k+1]=n;
    ll z=0;
    for(int m=1;m<=k;m++)for(int e=0;e<2;e++){
        int a=m,b=m+e;
        if(b>k)break;
        int t=0,o=(e==0),w=2*P[m],p=w,c=0;
        ll u=0,v=0;
        while(a>=1&&b<=k){
            if(a!=b){int s=P[a]+P[b];C[s]++;t++;u+=s;if(s<=p){c++;v+=s;}}
            int x1=P[a-1]+1,x2=P[a],y1=P[b],y2=P[b+1]-1,A=x1+y1,B=x2+y2;
            while(p>A-1){c-=C[p];v-=(ll)p*C[p];p--;}
            while(p<A-1){p++;c+=C[p];v+=(ll)p*C[p];}
            for(int x=A;x<=B;x++){
                c+=C[x];v+=(ll)x*C[x];
                ll q=min(x2,x-y1)-max(x1,x-y2)+1;
                if(o&&(x&1)){z-=q;continue;}
                ll f=(ll)x*c-v+(u-v)-(ll)x*(t-c);
                if(o)f+=abs(w-x)/2;
                z+=q*f;
            }
            p=B;a--;b++;
        }
        a++;b--;
        while(a<m){C[P[a]+P[b]]--;a++;b--;}
        if(a!=b)C[P[a]+P[b]]--;
    }
    printf("%lld\n",z);
}
