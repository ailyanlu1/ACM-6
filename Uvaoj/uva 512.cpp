#include<bits/stdc++.h>
using namespace std;
int n,m,ope[30];//�������в�������/����
int num_query,num_totalope,num_ope;//�ܲ��������͵���������������/����
string operation;//�����������
struct myk
{
    int x;
    int y;
    myk(int xx=0,int yy=0):x(xx),y(yy)
    {

    }
    bool isZero()
    {
        if((x==0)&&(y==0))
            return true;
        else
            return false;
    }
};
myk a[60][60],temp[60][60];//��¼Ŀǰÿ���������λ��
void init(void)
{
    for(int i=1;i<=50;i++)
    {
        for(int j=1;j<=50;j++)
        {
            if((i<=n)&&(j<=m))
                a[i][j]=myk(i,j);
            else
                a[i][j]=myk(0,0);
        }
    }
}
int translate(const string &X)
{
    if(X=="DR")
        return 0;
    if(X=="DC")
        return 1;
    if(X=="IC")
        return 2;
    if(X=="IR")
        return 3;
    if(X=="EX")
        return 4;
}
void back_up(void)
{
    for(int i=1;i<=50;i++)
    {
        for(int j=1;j<=50;j++)
            temp[i][j]=a[i][j];
    }
}
void deleteRow(void)//ԭ����һ��flag��־����־ÿһ����û��ɾ�������ɨһ��
{
    back_up();
    bool flag[60];
    memset(flag,0,sizeof(flag));//����һ��ʼȫ��û��ɾ������ʼ��
    for(int i=0;i<num_ope;i++)
    {
        flag[ope[i]]=1;//ɾ��
    }
    int ii=1;
    for(int i=1;i<=50;i++)
    {
        if(flag[i]==0)//��һ��û�б�ɾ�����ӵ��µ�a����
        {
            for(int j=1;j<=50;j++)
                a[ii][j]=temp[i][j];
            ii++;
        }
        else
        {
            continue;//����
        }
    }
    while(ii<=50)
    {
        for(int j=1;j<=50;j++)
            a[ii][j]=myk(0,0);
        ii++;
    }
}
void deleteColumn(void)
{
    back_up();
    bool flag[60];
    memset(flag,0,sizeof(flag));
    for(int i=0;i<num_ope;i++)
    {
        flag[ope[i]]=1;
    }
    int jj=1;//�µ���
    for(int j=1;j<=50;j++)
    {
        if(flag[j]==0)//�����һ�б�ɾ����
        {
            for(int i=1;i<=50;i++)
                a[i][jj]=temp[i][j];
            jj++;
        }
        else
        {
            continue;
        }
    }
    while(jj<=50)
    {
        for(int i=1;i<=50;i++)
            a[i][jj]=myk(0,0);
        jj++;
    }
}
void exchange(void)
{
    int r1=ope[0],c1=ope[1],r2=ope[2],c2=ope[3];
    myk temp_myk=a[r1][c1];
    a[r1][c1]=a[r2][c2];
    a[r2][c2]=temp_myk;
}
void increaseRow(void)
{
    back_up();
    bool flag[60];
    memset(flag,0,sizeof(flag));
    for(int i=0;i<num_ope;i++)
    {
        flag[ope[i]]=1;
    }
    int ii=1;
    for(int i=1;i<=50;i++)
    {
        if(ii>50)
            break;
        if(flag[i]==0)//û�в���
        {
            for(int j=1;j<=50;j++)
                a[ii][j]=temp[i][j];
            ii++;
        }
        else
        {
            for(int j=1;j<=50;j++)
                a[ii][j]=myk(0,0);
            ii++;
            for(int j=1;j<=50;j++)
                a[ii][j]=temp[i][j];
            ii++;
        }
    }
}
void increaseColumn(void)
{
    back_up();
    bool flag[60];
    memset(flag,0,sizeof(flag));
    for(int i=0;i<num_ope;i++)
    {
        flag[ope[i]]=1;
    }
    int jj=1;
    for(int j=1;j<=50;j++)
    {
        if(jj>50)
            break;
        if(flag[j]==0)//�����޲���
        {
            for(int i=1;i<=50;i++)
                a[i][jj]=temp[i][j];
            jj++;
        }
        else
        {
            for(int i=1;i<=50;i++)
                a[i][jj]=myk(0,0);
            jj++;
            for(int i=1;i<=50;i++)
                a[i][jj]=temp[i][j];
            jj++;
        }
    }
}
myk query(int xx,int yy)
{
    int flag=0,ans_x,ans_y;
    for(int i=1;i<=50;i++)
    {
        for(int j=1;j<=50;j++)
        {
            if((a[i][j].x==xx)&&(a[i][j].y==yy))
            {
                flag=1;
                ans_x=i;
                ans_y=j;
                break;
            }
        }
    }
    if(flag)
        return myk(ans_x,ans_y);
    else
        return myk(0,0);
}
void doit(void)//just do it!
{
    int index_operation;
    cin>>operation;
    index_operation=translate(operation);
    if(index_operation!=4)
    {
        cin>>num_ope;//�������������˼���/��
        for(int i=0;i<num_ope;i++)
            cin>>ope[i];
    }
    else
    {
        num_ope=4;
        for(int i=0;i<num_ope;i++)
            cin>>ope[i];
    }
    switch(index_operation)
    {
        case 0:deleteRow();
               break;
        case 1:deleteColumn();
               break;
        case 2:increaseColumn();
               break;
        case 3:increaseRow();
               break;
        case 4:exchange();
               break;
    }
}
void answerit(void)
{
    int xx,yy,ans=1;
    cin>>xx>>yy;
    myk ANS=query(xx,yy);
    if(ANS.isZero())
        ans=0;
    if(ans==0)
        printf("Cell data in (%d,%d) GONE\n",xx,yy);
    else
        printf("Cell data in (%d,%d) moved to (%d,%d)\n",xx,yy,ANS.x,ANS.y);
}
int main(void)
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cnt=1;
    while(cin>>n>>m)
    {
        if(n+m==0)
            break;
        if(cnt!=1)
            printf("\n");
        printf("Spreadsheet #%d\n",cnt);
        cnt++;
        init();
        cin>>num_totalope;
        //printf("num_totalope=%d\n",num_totalope);
        while(num_totalope--)
            doit();
        cin>>num_query;
        //printf("num_query=%d\n",num_query);
        while(num_query--)
            answerit();
    }
    return 0;
}
