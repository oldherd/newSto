#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ld double
#define eps 1e-13
using namespace std;
int n,top,st,ed;
ld xl[1001],xr[1001];
ld ans;
bool del[1001];
struct data{ld x,y,r;}t[1001],sk[1001];
struct line{ld l,r;}p[1001];
ld dis(data a,data b)
{return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
bool cmp1(data a,data b){return a.r<b.r;}
bool cmp2(data a,data b){return a.x-a.r<b.x-b.r;}
bool cmp3(line a,line b){return a.l<b.l;}
void ini()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	   {scanf("%lf%lf%lf",&t[i].x,&t[i].y,&t[i].r);}
   sort(t+1,t+n+1,cmp1);
   for(int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++)
         if(dis(t[i],t[j])<=t[j].r-t[i].r)
			   {del[i]=1;break;}
   for(int i=1;i<=n;i++)if(!del[i])sk[++top]=t[i];n=top;
   sort(sk+1,sk+n+1,cmp2);
}
ld getf(ld x)
{
	int sz=0,i,j;ld r,len=0,dis;
	for(i=st;i<=ed;i++)
   {
       if(x<=xl[i]||x>=xr[i])continue;
       dis=sqrt(sk[i].r-(x-sk[i].x)*(x-sk[i].x));
       p[++sz].l=sk[i].y-dis;p[sz].r=sk[i].y+dis;
   }
	sort(p+1,p+sz+1,cmp3);
	for(i=1;i<=sz;i++)
	{
		r=p[i].r;
		for(j=i+1;j<=sz;j++)
		{
			if(p[j].l>r)break;
			if(r<p[j].r)r=p[j].r;
		}
		len+=r-p[i].l;i=j-1;
	}
	return len;
}
ld cal(ld l,ld fl,ld fmid,ld fr)
{return (fl+fmid*4+fr)*l/6;}
ld simpson(ld l,ld mid,ld r,ld fl,ld fmid,ld fr,ld s)
{
	ld m1=(l+mid)/2,m2=(r+mid)/2;
	ld f1=getf(m1),f2=getf(m2);
	ld g1=cal(mid-l,fl,f1,fmid),g2=cal(r-mid,fmid,f2,fr);
	if(fabs(g1+g2-s)<eps)return g1+g2;
   return simpson(l,m1,mid,fl,f1,fmid,g1)+simpson(mid,m2,r,fmid,f2,fr,g2);
}
void work()
{
	int i,j;ld l,r,mid,fl,fr,fmid;
	for(i=1;i<=n;i++){xl[i]=sk[i].x-sk[i].r;xr[i]=sk[i].x+sk[i].r;sk[i].r*=sk[i].r;}
	for(i=1;i<=n;i++)
	{
		l=xl[i];r=xr[i];
		for(j=i+1;j<=n;j++)
		{
			if(xl[j]>r)break;
         if(xr[j]>r)r=xr[j];
		}
		st=i;ed=j-1;i=j-1;
      mid=(l+r)/2;
      fl=getf(l);fr=getf(r);fmid=getf(mid);
      ans+=simpson(l,mid,r,fl,fmid,fr,cal(r-l,fl,fmid,fr));
	}
}
int main()
{
	ini();
	work();
	printf("%.3lf",ans);
	return 0;
}
