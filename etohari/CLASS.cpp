#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=4e5;
const int MAXQ=1e5;
int n, q;
ll X1, X2, A1, B1, C1, M1;
ll Y1, Y2, A2, B2, C2, M2;
ll Z1, Z2, A3, B3, C3, M3;
int L[MAXN+5];
int R[MAXN+5];
int K[MAXN+5];
struct event{
    int x, typ;
    bool operator < (const event & o) const{
        if(x!=o.x) return x>o.x;
        return typ<o.typ;
    }
} eve[2*MAXN+5];
ll s[2*MAXN+5];
int l[2*MAXN+5];
void sub1(){
    ll ans=0;
    for(int j=1; j<=q; j++){
        bool ok=0;
        //cout<<K[j]<<' ';
        int d=1;
        int res=0;
        for(int i=2; i<=2*n; i++){
            if(K[j]<=1LL*(eve[i-1].x-eve[i].x)*d){
                int L=eve[i].x+1, R=eve[i-1].x;
                while(L<=R){
                    int mid=(L+R)>>1;
                    if(1LL*(eve[i-1].x-mid+1)*d>=K[j]){
                        res=mid;
                        L=mid+1;
                    }
                    else{
                        R=mid-1;
                    }
                }
                ok=1;
                break;
            }
            K[j]-=(eve[i-1].x-eve[i].x)*d;
            if(eve[i].typ==1){
                d++;
            }
            else{
                d--;
            }
        }
        ans+=1LL*j*res;
    }
    cout<<ans<<'\n';
}
void sub2(){
    for(int i=1; i<2*n; i++){
        l[i]=l[i-1];
        if(eve[i].typ==1) l[i]++;
        else l[i]--;
        s[i+1]=s[i]+1LL*l[i]*(eve[i].x-eve[i+1].x);
    }
    ll ans=0;
    for(int i=1; i<=q; i++){
        if(K[i]>s[2*n]) continue;
        int u=lower_bound(s+1, s+2*n+1, K[i])-s;
        K[i]-=s[u-1];
        int L=eve[u].x+1, R=eve[u-1].x;
        int res=0;
        while(L<=R){
            int mid=(L+R)>>1;
            if(1LL*(eve[u-1].x-mid+1)*l[u-1]>=K[i]){
                res=mid;
                L=mid+1;
            }
            else{
                R=mid-1;
            }
        }
        ans+=1LL*res*i;
    }
    cout<<ans<<'\n';
}
int main(){
//    freopen("CLASS.INP", "r", stdin);
//    freopen("CLASS.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>q;
        cin>>X1>>X2>>A1>>B1>>C1>>M1;
        cin>>Y1>>Y2>>A2>>B2>>C2>>M2;
        cin>>Z1>>Z2>>A3>>B3>>C3>>M3;
        L[1]=min(X1, Y1)+1; R[1]=max(X1, Y1)+1; K[1]=Z1+1;
        L[2]=min(X2, Y2)+1; R[2]=max(X2, Y2)+1; K[2]=Z2+1;
        for(int i=3; i<=n; i++){
            ll n_X=(A1*X2 + B1*X1 + C1)%M1;
            ll n_Y=(A2*Y2 + B2*Y1 + C2)%M2;
            X1=X2; X2=n_X;
            Y1=Y2; Y2=n_Y;
            L[i]=min(X2, Y2)+1;
            R[i]=max(X2, Y2)+1;
        }
        for(int i=3; i<=q; i++){
            Z1=(A3*Z2 + B3*Z1 + C3)%M3;
            swap(Z1, Z2);
            K[i]=Z2+1;
        }
        for(int i=1; i<=n; i++){
            eve[i*2-1]={L[i]-1, 0};
            eve[i*2]={R[i], 1};
        }
        sort(eve+1, eve+2*n+1);
        //sub1();
        sub2();
    }
    return 0;
}