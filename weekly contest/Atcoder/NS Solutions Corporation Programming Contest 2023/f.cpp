#include<bits/stdc++.h>
#define pb push_back
#define ll __int128
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long h;
	cin>>n>>h;
	ll hh=h;
	vector<long long> d(n),t(n);
	vector<pair<long long,long long>> tm(n);
	multiset<long long> mee;
	for(int i=0;i<n;i++) cin>>t[i]>>d[i],tm[i]={t[i],i},mee.insert(t[i]*d[i]);
	sort(all(tm));
	reverse(all(tm));
	vector<long long> mex(n);
	for(int i=0;i<n;i++){
        mex[i]=*mee.rbegin();
        mee.erase(mee.find(t[tm[i].second]*d[tm[i].second]));
	}

	auto good=[&](ll tea)->bool{
        ll maxd=0;
        ll dmg=0;
        ll one=1;
        for(int i=0;i<n;i++){
            ll maxs=mex[i];
            ll delta=tea-one*tm[i].first;
            if(delta>0){
                if(maxd==0) dmg+=one*maxs*delta;
                else{
                    ll limit=tea-maxs/maxd;
                    if(limit<=delta && limit>0){
                        dmg+=one*maxd*tea*limit-one*limit*(limit-1)*maxd/2;
                        dmg+=one*maxs*(delta-limit);
                    }else{
                        if(limit>delta) dmg+=one*maxd*tea*delta-one*delta*(delta-1)*maxd/2;//sus
                        else dmg+=one*maxs*delta;
                    }
                }
            }
            if(dmg>=hh) return true;
            tea=min(tea,one*tm[i].first);
            maxd=max(maxd,one*d[tm[i].second]);
        }
        ll delta=tea;
        if(delta>0){
            dmg+=one*maxd*tea*delta-one*delta*(delta-1)*maxd/2;
        }
        return dmg>=hh;

	};
	long long l=1,r=h;
	while(l<r){
        //cout<<l<<" "<<r<<"\n";
        long long m=(l+r)/2;
        if(good(m)) r=m;
        else l=m+1;
	}
	cout<<l<<"\n";
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
