//����ΪFloyd�㷨

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int a[210][210],n,m,aa,bb,x,s,t;

int main(void)
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<200;i++)
        for(int j=0;j<200;j++)
        {
            a[i][j]=100000000;
            a[i][i]=0;//��Ҫ���������浼��WA��Σ�
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&aa,&bb,&x);
            if(x<a[aa][bb])
                a[aa][bb]=a[bb][aa]=x;//��ֹһ��·�������Σ�����
        }
        scanf("%d%d",&s,&t);
        for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)//ע��ѭ��˳�򣡣���
            a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
        if(a[s][t]==100000000)
            printf("-1\n");
        else
            printf("%d\n",a[s][t]);

    }
    return 0;
}
