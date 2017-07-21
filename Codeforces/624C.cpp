#include<bits/stdc++.h>
using namespace std;
int n,m;
int color[5010];//Ⱦɫ����ɫ��-1Ϊ��ʼֵ��0 1ΪȾɫ����ɫ
int a[5010][5010];//�ڽӾ����ͼ
vector <int> G[5010];//vectorģ���ڽӱ��洢��ͼ
bool is_ac[5010];//�ж�������Ƿ�ΪB
bool colored[5010];//����������Ƿ���չ���ˣ��Ƿ����������ǰ���������ڵ��ˣ�
bool ans=true;//��ʼ�����Գɹ�
void paint(int i,int x)//���ڵ�iȾ��x��ɫ
{
    if((color[i]!=-1)&&(color[i]!=x))//���i�Ѿ�������ɫ�����Ҳ���x
    {
        ans=false;//�϶�ʧ��
    }
    color[i]=x;
    if(colored[i]==true)
        return ;//����Ѿ���չ�������ظ���չ
    colored[i]=true;//�����Ѿ���չ��tag
    for(auto j:G[i])
        paint(j,1-x);//dfs


}
int main(void)
{

    int u,v;
    cin>>n>>m;
    memset(color,-1,sizeof(color));//��ɫȫ����ʼ��
    memset(a,-1,sizeof(a));
    memset(is_ac,0,sizeof(is_ac));//����ʼ��Ϊ��B
    memset(colored,0,sizeof(colored));
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        a[u][v]=a[v][u]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            if(a[i][j]==-1)//��ͼ
            {
                G[i].push_back(j);
                is_ac[i]=is_ac[j]=true;//��Щ�㲻����B����a����C
            }
        }
    }
    for(int i=1;i<=n;i++)//��������ͨ�����Ⱦɫ
    {
        if(is_ac[i]==false)//��B�Ļ�ֱ�Ӳ��ÿ���
            continue;
        int temp_color=color[i];
        if(temp_color==-1)//Ҫ����������ɫ���ǳ�ʼ��-1�Ļ�
            temp_color=0;
        if(colored[i]==false)//�������㻹û����չ��/���ڲ�ͬ����ͨ��
            paint(i,temp_color);
    }
    if(ans)//���Ⱦɫ��ϣ���Ϊtrue
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
        {
            if((a[i][j]==1)&&(color[i]+color[j]==1))//�Ե�һ���������
                ans=false;
        }
    }
    if(ans)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    if(ans)
    {
        for(int i=1;i<=n;i++)
        {
            if(is_ac[i]==false)
                cout<<"b";
            else if(color[i])
                cout<<"a";
            else
                cout<<"c";
        }
    }
    return 0;
}
