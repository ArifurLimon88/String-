/// Here I implemented Trie+AhoCorasick using two dimentional array......Static+Dynamic Implementation can be found in my code library....
/// Porblem for: https://onlinejudge.org/external/106/10679.pdf


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Khela ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define llu long long unsigned int
#define pf printf
#define sf scanf
#define f first
#define s second
#define pb push_backs
#define mk make_pair
#define pii pair<int ,int>

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
const int MAX=1e18+100;
const int sz=1e3+300;
int node[sz][55];
bool yes[sz];
int getid(char ch) { return ((isupper(ch) ? (ch-'A')+26: ch-'a'));}
int last;
int fail[sz];
int Insert(string str)
{
    int len=str.length();
    int p=0;
    for(int i=0; i<len; i++)
    {
        int id=getid(str[i]);
        if(node[p][id]==-1)
            node[p][id]=++last;
        p=node[p][id];
    }
    return p;
}

void Make_failure()
{
    queue<int> q;
    fail[0]=0;
    int p,i,j,x,temp;
    for(i=0; i<55; i++)
    {
        if(node[0][i] != -1)
            q.push(node[0][i]),fail[node[0][i]]=0;
    }
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0; i<55; i++)
        {
            if(node[p][i] != -1)
            {
                x=node[p][i];
                q.push(x);
                temp=fail[p];
                while(temp && node[temp][i]==-1)
                    temp=fail[temp];
                if(temp==0)
                    fail[x]=(node[0][i]==-1) ? 0 : node[0][i];
                else
                    fail[x]=node[temp][i];
            }
        }
    }
}
void Search(string str)
{
    int i,j,p,x,temp;
    int len=str.length();
    int lal=0;
    for(int i=0; i<len; i++)
    {
        int id=getid(str[i]);
        while(lal && node[lal][id]==-1)
            lal=fail[lal];
        if(node[lal][id]==-1)
            continue;
        lal=node[lal][id];
        temp=lal;
        while(temp)
        {
            yes[temp]=true;
            temp=fail[temp];
        }
    }
}
void init()
{
    last=0;
    for(int i=0; i<sz; i++)
    {
        for(int j=0; j<55; j++)
        {
            node[i][j]=-1;
        }
        yes[i]=false;
        fail[i]=0;
    }
}
int main()
{
    Khela
    int a,b,c,i,j,k,q,p,x,y,ct,ct1,m,l,r,x1,y1,mn,h,sum1,in,z,mid,n,mx,w;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int t,cs=1;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        getline(cin,str);
        int ara[1010];
        cin>>p;
        q=p;
        cin.ignore();
        init();
        for(i=0; i<q; i++)
        {
            getline(cin,str1);
            p=Insert(str1);
            ara[i]=p;
        }
        Make_failure();
        Search(str);
        for(i=0; i<q; i++)
        {
            if(yes[ara[i]])
                cout<<"y"<<endl;
            else
                cout<<"n"<<endl;
        }
    }

}

