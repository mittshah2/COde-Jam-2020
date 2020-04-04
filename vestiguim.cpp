#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define ull unsigned long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod 1000000007


bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;

    return true;
}


ll max(ll a,ll b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

ll min(ll a,ll b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll lcm(ll a, ll b)
{
    return (a*b)/gcd(a, b);
}


ll fact(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}

ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

ll fastpow(ll base,ll exp)
{
    base%=mod;
    ll ans=1;
    while(exp)
    {
        if(exp&1) {ans*=base; ans%=mod;}
        exp/=2;
        base*=base;
        base%=mod;
    }
    return ans;
}

class DSU {
public:
    int n;
    vector<int> parent,size;

    DSU(int a) {
        n = a;
        parent.assign(n,0);
        size.assign(n,0);
        for(int i=0 ; i<n ; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    void makeSets(int k) {
        for(int i=0 ; i<n ; i++) {
            if(find(i) != i) {
                size[i] = 0;
            }
        }
    }

    int find(int a) {
        int root = a;
        while(root != parent[root]) {
            root = parent[root];
        }
        while(root != a) {
            int temp = parent[a];
            parent[a] = root;
            a = temp;
        }
        return root;
    }

    void unionSet(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if(root_a == root_b) return;
        if(size[a] < size[b]) {
            parent[root_a] = root_b;
            size[root_b] += size[root_a];
        }
        else {
            parent[root_b] = root_a;
            size[root_a] += size[root_b];
        }
    }
};




int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    for(int r=1;r<=t;r++)
    {
        int n;
        cin>>n;
        int a[n][n];
        ll s=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
                if(i==j)
                {
                    s+=a[i][j];
                }
            }
        }
        int row=0,col=0;
        for(int i=0;i<n;i++)
        {
            unordered_set<int> set,set1;
            set.insert(a[i][0]);

            for(int j=1;j<n;j++)
            {
                   if(set.find(a[i][j])!=set.end())
                   {
                       row++;
                       break;
                   } else{
                       set.insert(a[i][j]);
                   }

            }
        }


        for(int i=0;i<n;i++)
        {
            unordered_set<int> set1;
            set1.insert(a[0][i]);
            for(int j=1;j<n;j++)
            {
                if(set1.find(a[j][i])!=set1.end())
                {
                    col++;
                    break;
                } else{
                    set1.insert(a[j][i]);
                }
            }
        }

        cout<<"Case #"<<r<<": "<<s<<" "<<row<<" "<<col<<endl;


    }

    return 0;
}