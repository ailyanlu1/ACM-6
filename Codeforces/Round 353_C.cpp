#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>
#include<ctype.h>
#include<algorithm>
using namespace std;
struct TreeNode
{
	int key;//frep��¼��ֵ���ֵĴ���
	int lson,rson;
};
const int maxn=100000+10;
TreeNode tree[maxn];
int A[maxn];
int root=1,n,m,x,tot;//rootΪ1 �ս����0��ʾ
//�������
void insert(int k,int x)
{
	//����Ϊ�����
	if((x<tree[k].key)&&(tree[k].lson==0)){
		tot++;
		tree[k].lson=tot;
		tree[tot].key=x;
		printf("%d ",tree[k].key);
		return;
	}

	//����Ϊ�Ҷ���
	if((x>tree[k].key)&&(tree[k].rson==0)){
		tot++;
		tree[k].rson=tot;
		tree[tot].key=x;
		printf("%d ",tree[k].key);
		return;
	}

	if(x<tree[k].key)insert(tree[k].lson,x);
	else insert(tree[k].rson,x);
}
int main(void)
{

    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {

        tree[i].lson=tree[i].rson=0;
    }
    tot=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        if(i==0)
        {
            tree[1].key=A[i];
        }
        else
        {
            insert(1,A[i]);
        }
    }
    return 0;
}

