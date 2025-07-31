#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) (x).begin(), (x).end()
#define vi vector<ll>
#define vpi vector<pair<ll,ll>>
#define vout(a) for(auto x:a)cout<<x<<" ";cout<<endl;
#define vvout(a) for(auto x:a){for(auto y:x)cout<<y<<" ";cout<<endl;}
#define pb push_back
#define pans(x) cout<<((x)? "YES " : "NO ")<<endl;
//https://www.codechef.com/CRK32020/problems/KEVIN?tab=statement
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tt = 1;
    cin >> tt;
    while(tt--) {
        ll n;cin>>n;
        vi a(n);
        for(auto &x:a)cin>>x;

        auto check=[&]( ll k) -> bool {
            ll cnt=0;
            ll cnt2=0;
            ll l=a[0],r=a[0];
            for(int i=1;i<n;i++){
                if(abs(a[i]-l)<=k || abs(a[i]-r)<=k){
                    l=a[i]-k;
                    r=a[i]+k;
                }
                else{
                    cnt++;
                    l-=k;
                    r-=k;
                }
            }
            l=a[n-1],r=a[n-1];
            for(int i=n-2;i>=0;i--){
                if(abs(a[i]-l)<=k || abs(a[i]-r)<=k){
                    l=a[i]-k;
                    r=a[i]+k;
                }
                else{
                    cnt2++;
                    l-=k;
                    r-=k;
                }
            }
            return cnt<=k || cnt2<=k;
         };
         ll l=-1,r=4e9+9;
         while(l+1<r){
            ll mid=(l+r)/2;
            if(check(mid))r=mid;
            else l=mid;
         }
         cout<<r<<endl;
        


    }
}

//Nightmare05
#include<bits/stdc++.h>

using namespace std;

#define sp << " " <<
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define int long long
#define double long double
#define INF (1e18+13)
#define PI 3.1415926535898

int power(int p,int j)
{
    int res=1;
    p=p%mod;
    while(j>0)
    {
        if(j&1)
            res=(res*p)%mod;
        j=j>>1;
        p=(p*p)%mod;
    }
    return res;
}


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dice(int d,int p)
{
    uniform_int_distribution<int> uid(d,p);//specify l and s.
    return uid(rng) ;
}
/*
int read()
{
       int cc = getc(stdin);
       for (;cc < '0' || cc > '9';)  cc = getc(stdin);
       int ans = 0;
       for (;cc >= '0' && cc <= '9';)
       {
          ans = ans * 10 + cc - '0';
          cc = getc(stdin);
       }
      return ans;
}

inline void print(int n)
{
  if (n == 0)
  {
    putchar('0');
    putchar('\n');
  }
  else if (n == -1)
  {
    putchar('-');
    putchar('1');
    putchar('\n');
  }
  else
  {
    char buf[20];
    buf[19] = '\n';
    int i = 18;
    while (n)
    {
      buf[i--] = n % 10 + '0';
      n /= 10;
    }
    while (buf[i] != '\n')
      putchar(buf[++i]);
  }
}

int n;

vector<vector<int>> mat_mul(vector<vector<int>> a,vector<vector<int>> b)
{
    int n=5;
    vector<vector<int>> ans2(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int ans2=0;ans2<n;ans2++)
            {
                ans2[i][j]+=((a[i][ans2]*b[ans2][j])%mod);
                ans2[i][j]%=mod;
            }
        }
    }
    return ans2;
}

vector<vector<int>> pow_mat(vector<vector<int>> mat_a,int p)
{
    if(p==1)
        return mat_a;
    vector<vector<int>> temp=pow_mat(mat_a,p/2);
    vector<vector<int>> res=mat_mul(temp,temp);
    if(p&1)
        res=mat_mul(res,mat_a);
    return res;
}
*/

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("elimination_validation_input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,k;
    cin >> n >> k;
    int a[n],dp[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    if(k>n-2)
    {
        cout << 0;
        return 0;
    }
    int lo=0,hi=2000000013;
    while(hi>lo)
    {
        int mid=(lo+hi)/2;
        dp[0]=0;
        for(int i=1;i<n;i++)
            dp[i]=k+1;
        for(int i=1;i<n;i++)
        {
            dp[i]=min(dp[i],i);
            for(int j=i-1;j>=0;j--)
            {
                if(abs(a[i]-a[j])<=(i-j)*mid)
                {
                    dp[i]=min(dp[i],dp[j]+(i-j-1));
                }
            }
            if(dp[i]+n-1-i<=k)
            {
                dp[n-1]=k;
                break;
            }
        }
        if(dp[n-1]<=k)
            hi=mid;
        else
            lo=mid+1;
    }
    cout << lo;
    return 0;
}