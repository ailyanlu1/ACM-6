#include<stdio.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
int a[1010][1010],m,n,father[1010];
struct Edge{
int from;
int to;
int cost;};
Edge b[20000+10];//�߼�����洢
#define zuida 100000000//��֪���ܲ��ܹ������ݿ϶���ը
bool cmp(Edge a,Edge b)
{
    return(a.cost>b.cost);
}
int find_ancestor(int x)
{
    int r=x;
    while(father[r]!=r)
    {
        r=father[r];
    }
    int i=x,j;
    while(i!=r)
    {
        j=father[i];
        father[i]=r;
        i=j;
    }
    return r;//·��ѹ���������е�x�ĸ��ڵ�ĸ��ڵ㶼����Ϊ����

}
void add_bian(int x,int y)
{
   int fx=find_ancestor(x),fy=find_ancestor(y);
   if(fx!=fy)
       father[min(fx,fy)]=max(fx,fy);
}
int main(void)
{
    int temp_a,temp_b,temp_c,liantong=1,cnt,total,max_cost,max_i,max_j;
    int cntt=0,num=0;//num��ʾĿǰ�洢�˶�������
    Edge temp;//������ʱ�洢��
    cnt=total=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        a[i][j]=-1;//��Ϊ�����������������Kruskal�㷨�ҵ�����ߣ�����ֵΪ-1
        a[i][i]=0;
        father[i]=i;
    }
    while(m--)//ע���Ժ����õ�m�ˣ���������ܿӵ�
    {
        scanf("%d%d%d",&temp_a,&temp_b,&temp_c);
        if(temp_c>a[temp_a][temp_b])
        {
            temp.from=temp_a;
            temp.to=temp_b;
            temp.cost=temp_c;
            b[num++]=temp;//�����num����ڱߵ�����������ֻ��0��num-1���б�
        //�����Ŀ���ظ����־ͻ���bugҪע��
        //����a�����Ŀ�����޳��ظ��ߣ�ȡ���ֵ��
        }
        a[temp_a][temp_b]=max(a[temp_a][temp_b],temp_c);//����������������
        a[temp_b][temp_a]=a[temp_a][temp_b];
        add_bian(temp_a,temp_b);
        //Ϊ�˼��ͼ����ͨ�ԣ����Ƚ����б�ȫ�����벢�鼯
    }
    int temp_father=find_ancestor(1);//��һ��Ԫ�ص�father
    for(int i=1;i<=n;i++)
        if(find_ancestor(i)!=temp_father)
            liantong=0;
    if(liantong==0)
        printf("-1");
    else
    {
        for(int i=1;i<=n;i++)
            father[i]=i;//��һ�γ�ʼ��father����֮��Kruskal�㷨
        sort(b,b+num,cmp);//�ѱ߼���������
        while(cnt<n-1)
        {
            max_i=b[cntt].from;
            max_j=b[cntt].to;
            cntt++;//���������һ��Ҫ����ʹ��
            if(find_ancestor(max_i)!=find_ancestor(max_j))
            {
                add_bian(max_i,max_j);
                cnt++;
                total+=a[max_i][max_j];
                //printf("%d to %d\n",max_i,max_j);
            }
        }
        printf("%d",total);
    }
    return 0;
}
