// BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define eps 1e-9
#define inf 100000000
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};

inline bool EQ(double a, double b) { return fabs(a-b) < eps; }
//
//debug
#ifdef asif
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
            return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
            os << "{";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << *it;
                                            }
                    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
            os << "[";
                for(auto it = v.begin(); it != v.end(); ++it) {
                                if( it != v.begin() ) os << ", ";
                                        os << it -> first << " = " << it -> second ;
                                            }
                    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

void faltu () {
            cerr << endl;
}

template <typename T>
void faltu( T a[], int n ) {
            for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
                cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {
            cerr << arg << ' ';
                faltu(rest...);
}
#else
#define dbg(args...)
#endif // asif
#define ll long long int
#define f first
#define s second
#define S(a) scanf("%i", &a)
#define SS(a) scanf("%lli", &a)
#define P(a) printf("%i", a)
#define PP(a) printf("%lli", a)
#define hum printf("\n")


ll dp[221][221], a[221][221], n;

ll call(int i, int j)
{
    if(i == 2*n) return 0;
    if(j == 0) return 0;
    ll &ret = dp[i][j];
    if(ret != -1) return ret;
    ll p = 0;
    if(i < n )
    p = a[i][j] + max(call(i+1, j),  call(i+1, j+1));
    if(i >= n )
    {
        p = a[i][j] + max(call(i+1, j-1), call(i+1, j));
    }
    return ret = p;
}

int main()
{
    int t;
    S(t);
    int cases = 0;
    while(t--)
    {
        SS(n);
        for(int i = 0; i <= 2 * n + 10; i++)
            for(int j = 0; j <= 2 * n+10; j++) a[i][j] = -1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++) SS(a[i][j]);
        for(int i = n + 1; i <= 2*n-1; i++)
        for(int j = 1; j <= 2*n - i; j++) {SS(a[i][j]);}
        mem(dp, -1);
        ll ans = call(1, 1);
        printf("Case %i: %lli\n", ++cases, ans);
    }
}
