#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

ll sgn(ll x){
    if(x>0) return 1;
    else return -1;
}
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<ll> a;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x) a.pb(x);
		}
		n=a.size();
		if(n==0){
			cout<<"0\n";
			continue;
		}
		ll last=a[0];
		vector<ll> b;
		map<ll,set<int>> st;
		for(int i=1;i<n;i++){
			if(sgn(last)*sgn(a[i])<0){
				last=abs(last);
				st[last].insert(b.size());
				b.pb(last);
				last=a[i];
			}else last+=a[i];
		}
		last=abs(last);
		st[last].insert(b.size());
		b.pb(last);
		n=b.size();
		vector<int> l(n),r(n);
		for(int i=0;i<n;i++){
			l[i]=i-1;
			if(i<n-1) r[i]=i+1;
			else r[i]=-1;
		}
		ll ans=0;
		while(n>0 && !st.empty()){
			auto it=st.begin();
			if((it->second).size()==0){
				st.erase(st.begin());
				continue;
			}
			vector<int> id((it->second).begin(),(it->second).end());
			ll value=it->first;
			//cout<<n<<" "<<it->first<<" "<<id.size()<<"\n";
			ans+=value-ans;
			n-=id.size();
			int cnt=1,lef=l[id[0]];
			for(int i=1;i<id.size();i++){
				if(r[id[i-1]]!=id[i]){
					int rig=r[id[i-1]];
					if(cnt&1){//impar se unen lef y rig
						if(lef!=-1){
							//update de valor de suma
							st[b[lef]].erase(lef);
                            st[b[rig]].erase(rig);
							b[lef]+=b[rig]-value;
							st[b[lef]].insert(lef);
							//update de l y r
							// lef {id[0] ... id[i-1]} rig r[rig]
							r[lef]=r[rig];
							if(r[rig]!=-1) l[r[rig]]=lef;
						}else{
							l[rig]=-1;
						}
					}else{
						if(lef!=-1) l[rig]=lef,r[lef]=rig;
						else l[rig]=-1;
					}
					cnt=1;
					lef=l[id[i]];
				}else cnt++;
			}

			int rig=r[id.back()];
			// lef {...} rig
			if(cnt&1){
				if(lef!=-1 && rig!=-1){
					//update de valor de suma
					st[b[lef]].erase(lef);
					st[b[rig]].erase(rig);
					b[lef]+=b[rig]-value;
					st[b[lef]].insert(lef);
					//update de l y r
					r[lef]=r[rig];
					if(r[rig]!=-1) l[r[rig]]=lef;
				}else if(rig==-1 && lef!=-1){
					r[lef]=-1;
				}else if(lef==-1 && rig!=-1){
				 	l[rig]=-1;
				}
			}else{
				if(lef!=-1 && rig!=-1){
                    l[rig]=lef;
                    r[lef]=rig;
				}else if(rig==-1 && lef!=-1){
					r[lef]=-1;
				}else if(lef==-1 && rig!=-1){
					l[rig]=-1;
				}
			}
			st.erase(st.begin());
		}
		//cout<<n<<" xddd\n";
		cout<<ans<<"\n";
	}
	// your code goes here
	return 0;
}
