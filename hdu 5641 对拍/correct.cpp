/*
hdu 5641 BestCoder Round #75

����3*3��
1 2 3
4 5 6
7 8 9
�����ֻ���������������s1s2s3....sn�ʸ��������Ƿ����
1.������4λ         2.��;������û�߹���   3.�߹�֮�����ߵڶ���
4.����0��s[i]<INT_MAX,����Ҫ�ж�s[i]�Ƿ���1~9

��1->3��Ҫ���ж��м��2�߹�û��1->5 or 1->���ǺϷ���
����ÿ�ζ�����������һ���жϼ���

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;
#define lson (i<<1)
#define rson ((i<<1)|1)
const int maxn = 20;
int vis[maxn];
int a[maxn];

bool judge(int a,int b)
{
    if(a > b) swap(a,b);
    if(a == 1 && b == 9)
        return vis[5];
    else if(a == 1 && b == 3)
        return vis[2];
    else if(a == 1 && b == 7)
        return vis[4];
    else if(a == 3 && b == 9)
        return vis[6];
    else if(a == 2 && b == 8)
        return vis[5];
    else if(a == 3 && b == 7)
        return vis[5];
    else if(a == 4 && b == 6)
        return vis[5];
    else if(a == 7 && b == 9)
        return vis[8];
    else
        return 1;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out_correct.txt","w",stdout);
    int T,m,n;
    scanf("%d",&T);
    while(T--)
    {
        int flag = 0;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i] > 9 || a[i] < 1)
                flag = 1;
        }

        if(flag || n < 4)
        {
            printf("invalid\n");
            continue;
        }
        vis[a[1]] = 1;
        for(int i = 2;i <= n;i++)
        {
            if(!judge(a[i],a[i-1]) || vis[a[i]])
                flag =1;
            vis[a[i]] = 1;
        }
        if(flag)
            printf("invalid\n");
        else
            printf("valid\n");
    }
    return 0;
}
