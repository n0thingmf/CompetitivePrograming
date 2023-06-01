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

using cd = complex<double>;
const double PI = acos(-1);


void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    vector<cd> root(2*n);
    root[1]=cd(1,0);
    for(int k = 2; k < n; k <<= 1){
        double alpha = 2 * PI / (k<<1) * (invert ? -1 : 1);
        cd w(cos(alpha), sin(alpha));
        for(int i=(k>>1); i<k; i++){
            root[2*i] = root[i];
            root[2*i+1] = root[i]*w;
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        //  cd wlen(cos(ang), sin(ang));

        for (int i = 0; i < n; i += len) {
            //cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * root[j+len/2]; // w = cd(cos(ans*j),sin(ans*j)
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                //w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

void multiply(vector<ll> const& a, vector<ll> const& b,vector<ll> &result) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    result.resize(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
}

void convolute(vector<ll> &a,vector<ll> &b,vector<ll> &mul){
    int n=a.size();
    multiply(a,b,mul);
    mul.resize(n);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<ll> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	sort(all(a));
	sort(all(b));
	vector<ll> up,down;
	vector<ll> minp,maxp;
	// for the minimun
	int l,r;
	ll pref;
	for(l=0;l<n;l++){
        if(a[l]<0 && b[n-1-l]>=0){
            minp.pb(a[l]*b[n-1-l]);
        }else break;
	}
	for(r=n-1;r>=0;r--){
        if(a[r]>=0 && b[n-1-r]<0){
            minp.pb(a[r]*b[n-1-r]);
        }else break;
	}
    sort(all(minp),less<ll>());
    for(int i=1;i<minp.size();i++){
        minp[i]+=minp[i-1];
    }
	if(l<=r){
        for(int i=l;i<=r;i++){
            up.pb(abs(a[i]));
            down.pb(abs(b[n-1-i]));
        }
        if(up.size()>1 && up[0]>up.back()) reverse(all(up));
        if(down.size()>1 && down[0]>down.back()) reverse(all(down));
	}
	vector<ll> minpos;
	convolute(up,down,minpos);
	if(minp.size()>0) pref=minp.back();
	else pref=0;
	for(ll x:minpos) minp.pb(pref+x);
	//for the maximun
	up.clear();
	down.clear();
	for(l=0;l<n;l++){
        if(a[l]<0 && b[l]<0){
            maxp.pb(a[l]*b[l]);
        }else break;
	}
	for(r=n-1;r>=0;r--){
        if(a[r]>=0 && b[r]>=0){
            maxp.pb(a[r]*b[r]);
        }else break;
	}
	sort(all(maxp),greater<ll>());
	for(int i=1;i<maxp.size();i++){
        maxp[i]+=maxp[i-1];
	}
	if(l<=r){
        for(int i=l;i<=r;i++){
            up.pb(abs(a[i]));
            down.pb(abs(b[i]));
        }
        if(up.size()>1 && up[0]>up.back()) reverse(all(up));
        if(down.size()>1 && down[0]>down.back()) reverse(all(down));
	}
	vector<ll> maxneg;
	convolute(up,down,maxneg);
	if(maxp.size()>0) pref=maxp.back();
	else pref=0;
	for(ll x:maxneg) maxp.pb(pref-x);
	for(int i=0;i<n;i++){
        cout<<minp[i]<<" "<<maxp[i]<<"\n";
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
