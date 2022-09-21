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

const ll mod=1e9 +7;

int prec(char op){
    if(op=='+' || op=='-') return 1;
    else return 2;
}
ll ohash(char op){
    if(op=='+') return 1;
    else if(op=='-') return 2;
    else return 3;
}
ll operate(ll a,ll b,ll opp){
    if(opp==1) return (a+b);
    else if(opp==2) return (a-b);
    else return (a*b);
}
ll solve(string s){
    vector<pair<int,ll>> p;
    stack<char> ops;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ') continue;
        else if(isdigit(s[i])){
            ll val=0;
            while(i<s.size() && isdigit(s[i])){
                val=val*10+(s[i]-'0');
                i++;
            }
            p.pb({0,val});
            i--;
        }else if(s[i]=='('){
            ops.push(s[i]);
        }else if(s[i]==')'){
            while(!ops.empty() && ops.top()!='('){
                p.pb({1,ohash(ops.top())});
                ops.pop();
            }
            ops.pop();
        }else{
            if(ops.empty() || ops.top()=='('){
                ops.push(s[i]);
            }else{
                while(!ops.empty() && ops.top()!='(' && prec(s[i])<=prec(ops.top())){
                    p.pb({1,ohash(ops.top())});
                    ops.pop();
                }
                ops.push(s[i]);
            }
        }
    }
    while(!ops.empty()){
        p.pb({1,ohash(ops.top())});
        ops.pop();
    }
    stack<ll> num;
    /*for(int i=0;i<p.size();i++){
        cout<<p[i].first<<" "<<p[i].second<<"\n";
    }*/
    for(int i=0;i<p.size();i++){
        if(p[i].first==0){
            num.push(p[i].second);
        }else{
            ll b=num.top();
            num.pop();
            ll a=num.top();
            num.pop();
            num.push(operate(a,b,p[i].second));
        }
    }
    return num.top();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	getline(cin,s);
	cout<<solve(s)<<"\n";
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
