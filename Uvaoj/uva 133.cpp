#include<bits/stdc++.h>
using namespace std;
int tt=0,n,k,m,ans1,ans2,leftt;//left����Ŀǰ���м���Ԫ�أ�1-left��
int a[25];
int go(int start,int d,int step)//��start��step��������Ϊd,��ʱ��Ϊ����˳ʱ��Ϊ��
{
    int xx=start-d;
    while(step)
    {
        //printf("xx=%d  step=%d\n",xx,step);
        xx=xx+d;
        if(xx==n+1)
            xx=1;
        if(xx==0)
            xx=n;
        if(a[xx]==0)
            continue;
        else
            step--;

    }
    return a[xx];
}
int main(void)
{
    while(scanf("%d%d%d",&n,&k,&m))
    {
        if((n==0)&&(k==0)&&(m==0))
            break;
        for(int i=1;i<=n;i++)
            a[i]=i;
        leftt=n;
        //printf("Stop 1\n");
        tt=0;
        ans1=1;
        ans2=n;
        while(leftt)
        {
            if(tt==0)
                tt++;
            else
                printf(",");
            ans1=go(ans1,1,k);
            ans2=go(ans2,-1,m);
            a[ans1]=a[ans2]=0;
            if(ans1==ans2)
            {
                leftt-=1;
                printf("%3d",ans1);
            }
            else
            {
                leftt-=2;
                printf("%3d%3d",ans1,ans2);
            }
        }
        printf("\n");
    }
    return 0;
}
