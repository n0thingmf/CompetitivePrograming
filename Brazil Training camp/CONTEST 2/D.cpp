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
#define cd complex<double>

using namespace std;
const int maxn=2e5+1;
const double pi=acos(-1);
void fft(vector<cd> &a,bool invert){
    int n=a.size();
    if(n==1) return;

    vector<cd> a0(n/2),a1(n/2);
    for(int i=0;i<n;i++){
        if(i&1){
            a1[(i-1)/2]=a[i];
        }else{
            a0[i/2]=a[i];
        }
    }
    fft(a0,invert);
    fft(a1,invert);
    double ang=(2*pi/n)*(invert?-1:1);
    cd w(1),wn(cos(ang),sin(ang));
    for(int i=0;2*i<n;i++){
        a[i]=a0[i]+w*a1[i];
        a[n/2+i]=a0[i]-w*a1[i];
        if(invert){
            a[i]/=2;
            a[n/2+i]/=2;
        }
        w*=wn;
    }
}
vector<int> multiply(vector<int> &a,vector<int> &b){
    vector<cd> fa(all(a)),fb(all(b));
    int n=1;
    while(n<a.size()+b.size()) n<<=1;
    fa.resize(n);
    fb.resize(n);
    fft(fa,false);
    fft(fb,false);
    for(int i=0;i<n;i++) fa[i]*=fb[i];
    fft(fa,true);
    vector<int> ans(n);
    for(int i=0;i<n;i++) ans[i]=round(fa[i].real());
    return ans;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	int n,m;
	while(cin>>n){
        vector<int> a;
        vector<int> k(n);
        int maxsz=0;
        for(int i=0;i<n;i++){
            cin>>k[i];
            maxsz=max(maxsz,k[i]);
        }
        a.resize(maxsz+1,0);
        for(int i=0;i<n;i++) a[k[i]]++;

        vector<int> b=multiply(a,a);
        cin>>m;
        int ans=0;
        for(int i=0;i<m;i++){
            int val;
            cin>>val;
            if((val<a.size() && a[val]>0) || (val<b.size() && b[val]>0)) ans++;
        }
        cout<<ans<<"\n";
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
