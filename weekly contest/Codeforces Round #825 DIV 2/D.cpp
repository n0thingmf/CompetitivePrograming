#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

using namespace std;

const int maxn=2e5 + 2;
int ft[2][maxn];

void update(int id,int pos,int val){
    for(++pos;pos<maxn;pos+=pos&-pos){
        ft[id][pos]+=val;
    }
}

ll psum(int id,int pos){
    ll ans=0;
    for(++pos;pos>0;pos&=pos-1){
        ans+=ft[id][pos];
    }
    return ans;
}
ll sum(int id,int l,int r){
    return psum(id,r)-psum(id,l-1);
}

class query{
public:
    int pos,x,id;
    ll delta;
    query(){
        pos=x=id=delta=0;
    }
    query(int _pos,int _x,int _id){
        pos=_pos,x=_x,id=_id;
    }
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) a[i]=i+1-a[i];
	a.pb(INT_MAX);
	int nq;
	cin>>nq;
	vector<vector<int>> queries(n);
	vector<query> q(nq);
	for(int i=0;i<nq;i++){
        int p,x;
        cin>>p>>x;
        q[i]=query(p-1,p-x,i);
        queries[p-1].pb(i);
	}
	ll total=0;
	int eq=0,pass=0;
	vector<int> r(n+1),rr(n+1);
	for(int i=0,j=0,k=0;i<n;i++){

        while(a[j]<=i) j++;
        r[i]=j;
        if(j!=n) k=j+1;
        else k=n;
        while(a[k]<=i) k++;
        rr[i]=k-j;


        update(0,i,r[i]);
        while(r[eq]<i){
            update(1,eq,-rr[eq]);
            eq++;
        }
        while(r[pass]<=i){
            update(1,pass,rr[pass]);
            update(0,pass,-r[pass]);
            pass++;
        }
       // cout<<i<<" check\n";

        for(int ii:queries[i]){
            if(q[ii].x==a[i]) q[ii].delta=0;
            else if(q[ii].x<a[i]){
                if(r[eq]==i) q[ii].delta=sum(1,max(q[ii].x,eq),pass-1);
                else q[ii].delta=0;
            }else{
                if(pass<=min(i,q[ii].x-1)) q[ii].delta=1ll*(min(i,q[ii].x-1)-pass+1)*i-sum(0,pass,min(i,q[ii].x-1));
                else q[ii].delta=0;
            }
        }

      //  cout<<i<<" check22\n";
        total+=j-i;
	}
	for(int i=0;i<nq;i++){
        cout<<total+q[i].delta<<"\n";
	}
	return 0;
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* bitwise and boolean operations
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
