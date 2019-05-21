/// Recursion + Thinking.......

#include<bits/stdc++.h>
using namespace std;
#define LOL ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define llu long long unsigned int
#define pf printf
#define sf scanf
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define pii pair<int ,int>
//const int sz=
ll cholo()
{
    string str;
    ll sum=1;
    while(cin>>str)
    {
        if(str[0]=='S') continue;
        else if(str=="IF") sum*=(cholo()+cholo());
        else if(str[0]=='E') return max(1ll,sum);
    }
}
int main()
{
    LOL
    int a,b,c,i,j,k,q,p,x,y,sum,ct,ct1,m,l,r,x1,y1,mn,n,mx,ans,h,sum1,len,in,z,mid;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int cs=1,t;
    cin>>n;
    while(n--){


        ll sum=cholo();
        cout<<sum<<endl;
    }

}


