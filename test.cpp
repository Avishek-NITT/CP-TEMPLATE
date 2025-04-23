#include <bits/stdc++.h>
using namespace std;


// PBDS
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <class T>
// using Tree =
//     tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;









#define ll long long
#define int long long
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define PB push_back
#define enl "\n"
#define all(v) v.begin(),v.end()
#define yes cout << "YES" << enl;
#define no cout << "NO" << enl;
#define INF 1e18
ll mod_factor = (ll)1e9 + 7;
// ll mod_factor = 998244353;






void input(vector<int>& v){
    for(int i = 0 ; i < v.size(); i++){
        cin >> v[i];
    }
}
 
bool isprime(ll n)
{
    ll b = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            b++;
            break;
        }
    }
    if (b)
        return false;
    else
        return true;
}
 
bool is_palindrome(string v)
{
    FOR(i, 0, v.size() / 2)
    {
        if (v[i] != v[v.size() - 1 - i])
            return 0;
    }
    return 1;
}
 
bool isSubstring(string &a, string &b)
{
    return a.find(b) != string::npos;
}
 
 
 
bool isPerfectSquare(ll x)
{
    if (x >=0 ) {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
 
 
vector<ll> makePrefix(vector<ll>& v){    
        vector<ll> prefix(v.size()+1,0);
        prefix[1] = v[0];
 
        FOR(i,1,v.size()){
            prefix[i+1] = prefix[i] + v[i];
        }
        return prefix;
}
vector<ll> makeSuffix(vector<ll>& v){    
    int n = v.size();
    vector<ll> suff(n+1,0);
    suff[n-1] = v[n-1];

    for(int i = n-2; i >= 0; i--){
        suff[i] = suff[i+1] + v[i];
    }
    return suff;
}
 
 
template <typename T>
void vecprint(const vector<T>& v) {
    for (const auto& i : v) {
        cout << i << " ";
    }
    cout << endl;
}
 
 
int bexpo(int a , int b,int p){
    if(a == 0 && b == 0) return 1;
    if(b == 0) return 1;
    if(b == 1) return a%p;
    int x = bexpo(a, b/2,p)%p;
    if(b%2 == 0) return (x*x)%p;
    return (((x*x)%p)*a)%p;
}
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
    return res * res * a;
    else
    return res * res;
}


void precompute(){  
}
// *****************************
class SegmentTree {
    private:
        vector<int> tree;
        int size;
    
        void build(const vector<int>& arr, int node, int l, int r) {
            if (l == r) {
                tree[node] = arr[l];
            } else {
                int mid = (l + r) / 2;
                build(arr, 2 * node, l, mid);
                build(arr, 2 * node + 1, mid + 1, r);
                tree[node] = tree[2 * node] + tree[2 * node + 1];
            }
        }
    
        int rangeQuery(int node, int l, int r, int ql, int qr) {
            if (qr < l || ql > r) return 0; // no overlap
            if (ql <= l && r <= qr) return tree[node]; // complete overlap
            int mid = (l + r) / 2;
            return rangeQuery(2 * node, l, mid, ql, qr) + rangeQuery(2 * node + 1, mid + 1, r, ql, qr);
        }
    
        void pointUpdate(int node, int l, int r, int idx, int val) {
            if (l == r) {
                tree[node] += val;
            } else {
                int mid = (l + r) / 2;
                if (idx <= mid)
                    pointUpdate(2 * node, l, mid, idx, val);
                else
                    pointUpdate(2 * node + 1, mid + 1, r, idx, val);
                tree[node] = tree[2 * node] + tree[2 * node + 1];
            }
        }
    
        void rangeUpdate(int node, int l, int r, int ql, int qr, int val) {
            if (qr < l || ql > r) return; // no overlap
            if (l == r) {
                tree[node] += val;
                return;
            }
            int mid = (l + r) / 2;
            rangeUpdate(2 * node, l, mid, ql, qr, val);
            rangeUpdate(2 * node + 1, mid + 1, r, ql, qr, val);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    
    public:
        SegmentTree(const vector<int>& arr) {
            size = arr.size();
            tree.resize(4 * size);
            build(arr, 1, 0, size - 1);
        }
    
        int query(int left, int right) {
            return rangeQuery(1, 0, size - 1, left, right);
        }
    
        void update(int index, int value) { //update idx to value
            pointUpdate(1, 0, size - 1, index, value);
        }
    
        void updateRange(int left, int right, int value) {
            rangeUpdate(1, 0, size - 1, left, right, value);
        }
    };



void solve() {
    vector<int> v = {1,2,3,4,5,6,7};

    SegmentTree st(v);

    // cout << st.query(0,0);
    st.update(0,4);
    st.updateRange(0,0,4);
    cout << st.query(0,0);
}   

signed main()
{
 
    // ios_base::sync_with_stdio(0);
	// cin.tie(0);
        
    //USACO
    // freopen("haybales.in", "r", stdin);
    // freopen("haybales.out", "w" , stdout);

    int t ;
    t = 1;
    
    // cin >> t;
    precompute();
    while(t--){
        solve();
    }
}