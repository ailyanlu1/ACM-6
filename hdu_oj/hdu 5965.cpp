#include<bits/stdc++.h>
using namespace std;
const long long Mod=100000007;
const long long maxn=10000+10;
long long ans,num[maxn],dp[maxn];//��i�е����֣���i�е�����
char temp[maxn];
int n,t;
bool check(void)
{
    if(n==1)
    {
        return(dp[1]==num[1]);
    }
    else
    {
        return(num[n]==dp[n]+dp[n-1]);
    }
}
int main(void)
{
    long long ans_temp;
    cin>>t;
    while(t--)
    {
        ans=0;//��ʼ��Ϊ0
        scanf("%s",temp);
        n=strlen(temp);
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            num[i+1]=temp[i]-'0';
        for(int ii=0;ii<=2;ii++)//ö�ٵ�һ�е�����
        {
            if(ii>num[1])
                break;
            dp[1]=ii;
            dp[0]=0;//�ڱ�
            int i;
            for(i=2;i<=n;i++)
            {
                dp[i]=num[i-1]-dp[i-2]-dp[i-1];
                if((dp[i]<0)||(dp[i]>2))
                    break;
            }
            if(i<=n)
                continue;
            if(check())//˵������ö�٣���һ�е���������һ�����еķ���
            {
                ans_temp=1;//һ��ʼ����һ�ַ���
                for(int i=1;i<=n;i++)
                {
                    if(dp[i]==1)
                    {
                        ans_temp*=2;
                        ans_temp%=Mod;
                    }
                }
                ans+=ans_temp;
                ans%=Mod;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
