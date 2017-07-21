#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define zuida 100000
using namespace std;
int visit[zuida+10],n,m,fre=0,head[zuida+10],b[zuida+10];//b��ÿ������Ƿ���è
int status[zuida+10]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};//�ж��Ƿ���Ҷ�ӽ�㣬��Ҷ����Ϊ1
int cat_lianxu[zuida+10];//��ĿǰΪֹ������è�ĸ���

int father[zuida+10];
struct myk{
int node;
int next;};
myk yuansu[zuida*2+10];

void add_tree(int x,int y)//��������洢
{
    yuansu[fre].node=y;
    yuansu[fre].next=head[x];
    head[x]=fre;
    fre++;
}
void dfs(int x)
{
    visit[x]=1;

    for(int i=head[x];i!=-1;i=yuansu[i].next)
    {

        int y=yuansu[i].node;
        if(!visit[y])
        {
            status[x]=0;
            father[y]=x;
            if(b[y]==0)
                cat_lianxu[y]=0;
            else
                cat_lianxu[y]=1+cat_lianxu[x];
            if(cat_lianxu[y]<=m)
                dfs(y);
        }

    }
}

int main(void)
{
    int temp_x,temp_y,num=0;
    memset(head,-1,sizeof(head));
    memset(visit,0,sizeof(0));



    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        status[i]=1;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&temp_x,&temp_y);
        add_tree(temp_x,temp_y);
        add_tree(temp_y,temp_x);
    }

    cat_lianxu[1]=b[1];
    dfs(1);

    for(int i=1;i<=n;i++)
    {
        if((status[i])&&(visit[i]))
            num++;
    }
    printf("%d",num);
    return 0;

}
