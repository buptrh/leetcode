#include<bits/stdc++.h>
using namespace std;
const int N=200090;
int sum[N<<2];
int n,k,m;
int a[N];
struct node
{
int x,y;
bool operator <(const node &t)const
{
return x<t.x||(x==t.x&&y>t.y);
}
}b[N];
void pushup(int rt)
{
    sum[rt]=min(sum[rt<<1],sum[rt<<1|1]);
}
void build(int l,int r ,int rt)
{
    if(l==r)
    {
        sum[rt]=a[l];
        return ;
    }
    int mid=(r+l)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt); 
}
int query(int l,int r,int ll,int rr,int rt )
{
    if(ll<=l&&rr>=r)
    {
        return sum[rt];
    }
    int mid=(r+l)>>1;
    int mi=100;
    if(ll<=mid)
        mi=min(mi,query(l,mid,ll,rr,rt<<1));
    if(rr>mid)
        mi=min(mi,query(mid+1,r,ll,rr,rt<<1|1));
    return mi;
}
int  main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&b[i].x,&b[i].y);
    }
    sort(b+1,b+1+m);
    build(1,n,1);
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            int len=query(1,n,b[i].x,b[j].x,1);
           // cout<<len<<endl;
            if(len>=min(b[i].y,b[j].y))
            {
                if(b[j].x-b[i].x+max(b[i].y,b[j].y)-min(b[i].y,b[j].y)<=k)
                    ans++;
            }
            else
            {
                if(b[i].y+b[j].y-2*len+b[j].x-b[i].x<=k)
                ans++;
            }
        }
    }
    printf("%d\n",ans);
}