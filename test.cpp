#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define bit(x, i) (x & (1 << i)) 
#define max(a, b) (a < b ? b : a)
#define PB push_back
#define UM unordered_map
#define sf1(a) scanf("%lld", &a) 
#define sf2(a,b) scanf("%lld", &a, &b)
#define pf1(a) printf("%lld", a)
#define pf2(a,b) printf("%lld %lld", a, b)
 
ll mod_factor = pow(10,9) + 7;
 
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
 
bool is_set(unsigned int number, int x) {
    return (number >> x) & 1;
}
 
bool isPerfectSquare(ll x)
{
    if (x >=0 ) {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
 
int compare(int a , int b){  
    int result = a^b;
    int count = 0;
    
    for(int i = 0; i < 32; i++){
        count += (result >> i) & 1;
    }
    return count;
}
 
int count1s(int a){
    int count =0;
    for(int i =0; i < 32; i++){
        count += (a>>i)&1;
    }
    return count;
}
 
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
void getPrimeFactors(ll n, unordered_map<ll,ll>&m) 
{ 
    while (n % 2 == 0) 
    { 
        m[2] += 1;
        n = n/2; 
    } 
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while (n % i == 0) 
        { 
            m[i] += 1; 
            n = n/i; 
        } 
    } 
    if (n > 2) 
        m[n] += 1; 
} 
 
 
vector<ll> makePrefix(vector<ll> v){
        vector<ll> prefix(v.size());
        prefix[0] = v[0];
 
        FOR(i,1,v.size()){
            prefix[i] = prefix[i-1] + v[i];
        }
        return prefix;
}
 
template <typename T>
void vecprint(const vector<T>& v) {
    for (const auto& i : v) {
        cout << i << " ";
    }
    cout << endl;
}
 
 
// **************************




void solve(){   
    
}
 
 
 
 
int main()
{
    ios::sync_with_stdio(0);    
    cin.tie(0);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
 

    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
 
    ll t ;
    // t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    


    inputFile.close();
    outputFile.close();
}
