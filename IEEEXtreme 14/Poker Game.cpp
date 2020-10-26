#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second

vector<string> vec;
int val[256];
string r = "23456789XJQKA";
string rr = "";
unordered_map<string, bool> cant;
bool srt2(char &a, char &b){
    return val[a] < val[b];
}
void bt(string s, int sz, int ind){
    if(s.size() == sz){
        vec.pb(s);
        return;
    }
    for(int i = ind; i < rr.size(); i++){
        bt(s + rr[i], sz, i);
    }
}
bool srt(pair<int, string> &a, pair<int, string> &b){
    if(a.first != b.first)
            return a.first > b.first;
    bool ok = 0;
    for(int i = 0; i < min(a.second.size(), b.second.size()); i++){
        if(val[a.second[i]] < val[b.second[i]]){
            ok = 1;
            break;
        }
        else if (val[a.second[i]] > val[b.second[i]]){
            ok = 0;
            break;
        }
    }
    return ok;
}
int main(){
    FAST
    int n, k;
    cin >> n >> k;
    string s, w; cin >> s >> w;
    vector<pair<int, string> > ans;
    int done[256];
    mm(done);
    for(int i = 0; i < r.size(); i++){
        if(!done[r[i]])rr += r[i];
    }
    bt("", k, 0);
    for(int i = 0; i < r.size(); i++){
        val[r[i]] = i;
    }
    for(int i = 0; i < vec.size(); i++){
        sort(vec[i].begin(), vec[i].end(), srt2);
        int has[256];
        mm(has);
        int currscore = 0;
        bool ok = 1;
        for(int a = 0; a < k; a++){
            has[vec[i][a]]++;
            if(has[vec[i][a]] > 4)ok = 0;
            if(has[vec[i][a]] == 2)currscore++;
            else if(has[vec[i][a]] == 3)currscore += 19;
            else if (has[vec[i][a]] == 4)currscore += 1740;
        }
        for(int j = 0; j < n; j++){
            has[s[j]]++;
            if(has[s[j]] > 4)ok = 0;
            if((has[s[j]] == 1 && w[j] == 'y'))ok = 0;
            if(has[s[j]] == 2 || has[s[j]] == 3 || has[s[j]] == 4){
                if(w[j] == 'n')ok = 0;
                if(has[s[j]] == 2)currscore++;
                if(has[s[j]] == 3)currscore += 19;
                if(has[s[j]] == 4)currscore += 1740;
            }
        }
        if(ok)ans.pb({currscore, vec[i]});
    }
    if(ans.size() == 0){
        cout << "impossible";
        return 0;
    }
    sort(ans.begin(), ans.end(), srt);
    cout<<ans[0].second<<endl;
    return 0;
}
