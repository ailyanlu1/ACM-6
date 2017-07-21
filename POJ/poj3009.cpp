#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#include<math.h>
using namespace std;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int m,n,start_x,start_y,end_x,end_y,xx,yy,minn,xxx,yyy;
int a[25][25];

bool panduan(int aa,int bb)
{
    if((aa>=1)&&(aa<=n)&&(bb>=1)&&(bb<=m))
        return true;
    else
        return false;
}
bool panduan2(int i,int x,int y)//�ж��ܲ����߲������ߵ�����,i�Ƿ���xy����ʼλ������
{
    xx=x+dx[i];
    yy=y+dy[i];
    if(panduan(xx,yy)&&(a[xx][yy]==3))//�����һ�����ǽ����㣬ֱ��return
        return true;
    if((!panduan(xx,yy))||(a[xx][yy]==1))//�����һ��Խ�������һ�����ϰ�������
        return false;
    while(panduan(xx,yy)&&(a[xx][yy]!=1))//�ߵ����˵����һ���Ȳ����յ㣬�������ߣ��ҳ����ĵ�ֹͣ��
    {
        xx=xx+dx[i];
        yy=yy+dy[i];
        if((a[xx][yy]==3))
            return true;
    }
    if(a[xx][yy]!=1)//����xx��yy��ʱԽ�磬������һ����������1���Ǿ��군�ˡ�����aҪ����ֵ-1
        return false;
    xxx=xx;//������ʱ���ϰ����λ��xxx,yyy
    yyy=yy;
    xx-=dx[i];
    yy-=dy[i];
    return true;
}
void dfs(int step,int x,int y)
{
    int temp_xxx,temp_yyy;
    //printf("(%d,%d),step=%d\n",x,y,step);
    int temp_x,temp_y;
    if((step>=10)||((x==end_x)&&(y==end_y)))
        return ;
    for(int i=0;i<4;i++)
    {
        if(panduan2(i,x,y))
        {
            temp_x=xx;
            temp_y=yy;
            if((xx==end_x)&&(yy==end_y))
            {
                minn=min(step+1,minn);
                //printf("++\n");
            }

            a[xxx][yyy]=0;//����״̬
            temp_xxx=xxx;
            temp_yyy=yyy;//�����dfs��Ӧ��blockλ�ñ��������ݹ��У���ֹ���ƻ�
            dfs(step+1,xx,yy);
            a[temp_xxx][temp_yyy]=1;//����
        }
    }
}
void duru(void)
{
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        scanf("%d",&a[i][j]);
        if(a[i][j]==2)
        {
            start_x=i;
            start_y=j;
            a[i][j]=0;
        }
        if(a[i][j]==3)
        {
            end_x=i;
            end_y=j;

        }
    }
}
int main(void)
{
    while(1)
    {
        scanf("%d%d",&m,&n);
        memset(a,-1,sizeof(a));
        if(m*n==0)
            goto myk;
        duru();
        minn=INT_MAX;
        dfs(0,start_x,start_y);
        if(minn==INT_MAX)//�߲��������
            minn=-1;
        printf("%d\n",minn);
    }
    myk:return 0;
}
