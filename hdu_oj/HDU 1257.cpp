#include<stdio.h>
#include<math.h>
int a[100000],b[100000];//a[i]�浱ǰֵ��b[i]����Сֵ
int main()
{
    int n,i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        b[0]=0;k=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            for(j=0;j<=k;j++)
            {
                if(a[i]<b[j])//��Сֵ����
                {
                    b[j]=a[i];
                    break;
                }
                else if(j==k)
                {
                    k++;
                    b[k]=a[i];
                    break;
                }
            }
        }
        printf("%d\n",k);
    }
    return 0;
}
