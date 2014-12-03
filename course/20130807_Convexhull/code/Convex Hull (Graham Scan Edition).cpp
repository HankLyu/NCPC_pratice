/* Library: Graham Scan to find the convex hull
 *
 * The point is based from 0~N-1.
 *
 * �p�G��J���\�h�I�@�u�A�h�u�|�X�X���Ǻ��I�c��convex hull���I���X�A���׷|�^�s
 * �bhull�̭��A�^��hull���I�ƥ�
 *
 * �t�~�|���K�O�����Ǥ��O�bconvex hull�̭����I���X
 *
 * ex: ��J
 *
 * 6
   0 0
   1 2
   3 4
   2 0
   2 4
   5 0
 *
 * convex: (0, 0) (5, 0) (3, 4) (2, 4) (0, 0) <-�]�t�_�I (�{���|�ۤv�[)
 * non   : (2, 0) (1, 2)
 *
 * �`�N��J�����n�T���I�H�W...�p�G��X��convex hull���@�����u�A���s�b�^��0
 *
 * �@�������ܧέn�`�N�a��
 *
 * (1)�D�Y�]�P��: �@���I�n�����^��0.0�A�䥦�N"����"�qhull array�h�p��A���ξ��
 *               ���إu������I�Ϊ̦@�u���ΡA�]���N�����I�A�]�n¶�@��~�i
 *               ex: ���w����I (0, 0) (3, 0) => ��X�Ӫ�hull:
 *               								(0, 0) (3, 0) (0, 0)
 *               �]���P���� 3+3 = 6
 *
 * (2)�I�@�u: �p�G��J��ƥ������@�u�A�Ҧp(0, 0) (1, 0) (2, 0) (3, 0) �h�Y�]
 *            �|��X�o�� (0, 0) (3, 0) (2, 0)�A�]�N�Otop�^�ǭn�j�󵥩�4�~�i��
 *            �Φ��@�ӥY�]�A��M�٬O�D�n�n���D�ت��n�D������X
 *  */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/*------------------------------------------------------------------------------*/
//begin of convex hull routine

#define MAXN 100
typedef struct POINT_INFO
{
	int x, y;
}POINT;

int cross(POINT p0, POINT p1, POINT p2)
{
	return (p1.x-p0.x)*(p2.y-p0.y) - (p1.y-p0.y)*(p2.x-p0.x);
}

double dis(POINT a, POINT b)
{
	return sqrt((double)((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)));
}

int top;		//N is the original point, Nh is the point number of hull
POINT base;		//base of sorting

/* sort function */
bool cmp(POINT a, POINT b)
{
	int tmp = cross(base, a, b);
	if(tmp==0)
		return dis(a, base) > dis(b, base);		//very important...
	return (tmp > 0);
}

void SORT(POINT in[], int N)
{
	/* Find the base */
	int i, minx, miny, minid;
	minx = in[0].x, miny = in[0].y, minid = 0;

	/* Find the base point */
	for(i=1; i<N; i++)
		if( in[i].y<miny || (in[i].y==miny && in[i].x<minx))
			minx = in[i].x, miny = in[i].y, minid = i;

	/* swap and sorting (remember to set the base)*/
	swap(in[0], in[minid]);
	base = in[0];
	sort(in+1, in+N, cmp);		//since the original point is the base

	for(i=0; i<N; i++)
		printf("%d %d\n", in[i].x, in[i].y);
}

int process(POINT in[], int N, POINT hull[], POINT waste[], int &Nw)
{
	/* �o��@�w�n�ݦn�D�حn�D�P�_.... */
	if(N<3)
	{
		printf("Please check this part by the problem description again...\n");
		return 0;			//special case
	}

	/* sort */
	SORT(in, N);

	/* find the hull */
	int i;
	in[N] = in[0];				//This line is very important.
	for(top = 2, i=0; i<=2; i++) hull[i] = in[i];

	for(Nw=0, i=3; i<=N; i++)
	{							//should >= 0 to delete the co-linear point.
		while( cross(hull[top-1], in[i], hull[top] ) >= 0 )
		{
			//printf("now delete the point %d %d\n", hull[top].x, hull[top].y);
			waste[Nw++] = hull[top--];
			if(top==1) break;
		}
		hull[++top] = in[i];
	}

	/* �A�[�@�O�]���n����X�i�H�b�h�@��base�I�A�]�i�H��ܤ��n */
	++top;						//the hull number

	//�o��]�n�P�_�M��...���D�ػ�ԣ...�����D�ط|�G�N������I����...
	if(top<=3)
	{
		printf("Please check the problem description again...\n");
		return 0;		//invalid hull (�]��base�I�|�A���ƺ�@��)
	}
	return top;
}
//end of convex hull subroutine
/*------------------------------------------------------------------------------*/

int main()
{
	freopen("test", "r", stdin);

	int i, N, Nh, Nw;
	POINT point[MAXN], hull[MAXN], waste[MAXN];

	while(scanf("%d", &N)==1)
	{
		/* read the point */
		for(i=0; i<N; i++)
			scanf("%d %d", &point[i].x, &point[i].y);

		/* Find the hull -> hull (return the number of point in hull) */
		Nh = process(point, N, hull, waste, Nw);

		/* show the hull */
		printf("The point of the convex hull:\n");
		for(i=0; i<Nh; i++)	printf("%d %d\n", hull[i].x, hull[i].y);

		/* show the waste point */
		printf("The non convex hull point:\n");
		for(i=0; i<Nw; i++) printf("%d %d\n", waste[i].x, waste[i].y);
	}

	return 0;
}
