#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#include<ctype.h>
using namespace std;
#define zuida 1000000
int num,prime[zuida+10],isprime[zuida+10],ismeiprime[zuida+10];//prime�����д������
int sum[zuida+10];
int i,j;//ѭ������
int geweihe(int input)
{
    char temp[10];
    int sum=0;
    sprintf(temp,"%07d",input);

    for(int i=0;i<7;i++)
    {
        sum+=temp[i]-'0';
    }
    return sum;
}

int main(void)
{
    int t,l,r,num_sushu;
    scanf("%d",&t);
    memset(isprime,1,sizeof(isprime));//��ʼ��Ϊ0
    isprime[0]=isprime[1]=0;//0,1����������
    num=0;//num�������Ŀǰ����������
    for(i=2;i<=zuida;i++)
    {
        if(isprime[i])//���i������
            prime[++num]=i;//��i���룬prime�����1��ʼ
        for(j=1;(j<=num)&&(i*prime[j]<=zuida);j++)
        {
            isprime[i*prime[j]]=0;//�����һ����������
            if(i%prime[j]==0)
                break;//˵��i�Ǻ���������ȥ�˸��������Ľ����֮ǰ��������ȥ�˸�������һ���Ѿ��õ����ˣ����Բ�����
        }
    }
    for(int i=1;i<=zuida;i++)
    {
        int temp=geweihe(i);
        if((isprime[i])&&(isprime[temp]))
            ismeiprime[i]=1;
        else
            ismeiprime[i]=0;
    }
    sum[1]=0;
    for(int i=2;i<=zuida;i++)
    {
        if(ismeiprime[i])
            sum[i]=sum[i-1]+1;
        else
            sum[i]=sum[i-1];
    }
    for(int i=1;i<=t;i++)
    {
        num_sushu=0;
        scanf("%d%d",&l,&r);

        printf("Case #%d: %d\n",i,sum[r]-sum[l]+ismeiprime[l]);
    }

    return 0;
}
