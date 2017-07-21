/* THE PROGRAM IS MADE BY PYY */
/*----------------------------------------------------------------------------//
Copyright (c) 2011 panyanyany All rights reserved.

URL   : http://acm.hdu.edu.cn/showproblem.php?pid=1175
Name  : 1175 ������

Date  : Wednesday, August 17, 2011
Time Stage : long , very long.......

Result:

Test Data:

Review:
��ϧ�������ݻ���Ū������ԭ���ñ���������
//----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
1175 ������ �������������
**---------------------------------------------------------------------------*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAXSIZE 10009
#define LIMIT	10		// ���ɵ�ͼ���� 10*10 �Ĺ��ģ������˹������Ҵ�
// ����Ҳ������ô�㣬��С�㣬�Ҿ���10���ȽϺ���

#define getNotZeroRand(x) while (!((*x) = rand() % LIMIT)) ;
#define getNumUpperThan(x, y) while ((*(x) = rand() % LIMIT) < y) ;
#define getNumInRange(x, lower, upper) while ((*(x) = rand() % upper) < lower) ;

int repeat[MAXSIZE] ;
int map[MAXSIZE][MAXSIZE] ;

int main ()
{
	//freopen ("D:\\Computer Language\\C++\\Test\\in.txt", "r", stdin) ;
	int i, j, k ;
	int n, m, num, tmp, q ;
	int x1, y1, x2, y2 ;

	//puts ("input data number : ") ;	// ��ʾ���Բ������뵽�ļ��У�����Ҫ��д

	// �ļ��ض��򣬰�ԭ��Ҫ�������Ļ�ϵ����ݣ�������ļ���ȥ
	freopen ("in.txt", "w", stdout) ;
	//scanf ("%d", &num) ;
	num=10;
	srand(unsigned(time(0)));
	//srand (0) ;	// ������������ӣ�ò�Ʋ���Ҳ���ԡ�����������
	// ��ʱֻ�����ò������������"���"һ�㣬��ʵ�����������Ҵ�
	// �̶������ݣ����Ծ����𷴸��Ĳ���

	for (i = 0 ; i < num ; ++i)
	{
		// ���� 10 * 10 ��������
		// �� getNumInRange Ҳ���ԣ������������д�ģ�Ҳ��û��ȥ����
		getNumUpperThan (&n, 1) ;
		getNumUpperThan (&m, 1) ;

		// ���ö��������ݣ���������٣���10000�����Ҿ��ܲ����������
		// ��Ȼ��������и���׼�Ĵ𰸴��룬������������ݲ�����׼�𰸣�
		// �ٺ��Լ������Ĵ𰸶Աȣ��������塣
		printf ("%d %d\n", n, m) ;

		memset (repeat, 0, sizeof (repeat)) ;	// �����������ֵ��ظ�������
		// һ��ͼ�����һ������ֻ���ظ�����

		for (j = 0 ; j < n ; ++j)
		{
			for (k = 0 ; k < m; ++k)
			{
			    tmp = rand () % (n * m) ;
				/*

				// ��ʵ��������ظ�������ѭ����ʱ���ܻ�ʱ���
				// ��ʵ���Ϻ���Ӱ�첻������û����ȥ�Ľ�
				while (repeat[tmp] >= 2)
					tmp = rand () % (n * m) ;
				++repeat[tmp] ;

				// ����޶�0�ķֲ�Ƶ�ʣ�Ϊ50%
				// Ҳ����˵�����������������������50%������0
				// ���0̫�٣�������������û��ʲô�����
				// ��������ʵ������������ò��0�����ܲ�������������������
				if ((n*m)/2 <= tmp)
					tmp = 0 ;

                */

				// ��¼���ʳ�¯���������ȣ������� :)
				map[j][k] = tmp ;
			}
		}

		//���ͼ��
		for (j = 0 ; j < n ; ++j)
		{
			for (k = 0 ; k < m - 1; ++k)
			{
				printf ("%d ", map[j][k]) ;
			}
			printf ("%d\n", map[j][k]) ;
		}

		// ��ѯ�ʴ����޶���50���ڡ������Ҳ���Ϊ0
		while (!(q = rand () % 50)) ;

		printf ("%d\n", q) ;

		for (j = 0 ; j < q ; ++j)
		{
			// �����õ�����Ҫ�� 1 <= x < n + 1
			getNumInRange (&x1, 1, n + 1) ;
			getNumInRange (&y1, 1, m + 1) ;
			getNumInRange (&x2, 1, n + 1) ;
			getNumInRange (&y2, 1, m + 1) ;

			printf ("%d %d %d %d\n", x1, y1, x2, y2) ;
		}
		// ˢ�»������������Ѿ�ûʲô�����ˡ�
		// ���տ�ʼ��ʱ�����������Щ������Ҫ��ʱˢ�����鿴���������е�����
		//fflush (stdout);
	}
	// �����˻�Ҫ�н�����һ��
	printf ("0 0\n") ;
	return 0 ;
}
