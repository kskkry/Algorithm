const int MOD = 1e9+7;
typedef  long long ll;

struct mint {
        ll x; 
        mint(ll x=0): x((x % MOD + MOD) % MOD){}
        mint operator-() const {return mint(-x);}
        mint& operator+=(const mint a){
                if ((x += a.x) >= MOD) x -= MOD;
                return *this;
        }
};