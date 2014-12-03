/* Library: ��X�@�Ӧh��ή֪����n
 *
 * �`�N�p�G�^��0���ɭԦ��i��O�@���u�A�n���D�ت��W�w�A��M�D�ئp�G�S��
 * �o�ش��ո�ơA�N���κޥL...���L�q�`�@�����u�]��֦s�b�A�Y�ϭ��n��0
 * �q�`�o�䤣�`�N�N�ܮe��WA
 *
 * Algorithm: �D�n�O�Q�Υb�����ۥ�t��k�AO(N2)
 *
 * �M�˪O: ��X��Ӧh��� "�ְϰ�" ���涰���n�A�N�O�ǤJ���h��Τ@�˴N�i�H�F
 *
 * �D�n�֤߬O�b���y�����A�`�N�b���y�ɭԬO�]�w���f�ɰw¶polygon�A��M�p�G��J
 * �O���ɰw�A�{���|�ۤv�h��
 *
 * ���n�P�_����|�Ǧ^�t��(���i��)�A�]���n�P�w������w�����ǬO�f�ɰwor���ɰw
 * �ҥH�b�^�Ǯɭn�ۤv�b�P�_�@�U
 *
 *  */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define eps 1e-6
#define sqr(a) ((a) * (a))
#define IsZero(a) (fabs(a) < eps)
#define IsSame(a, b) (fabs((a) - (b)) < eps)
#define dot(a, b) (a.x * b.x + a.y * b.y)

//�I
typedef struct POINT_INFO
{
	double x, y;
}POINT;

//�uor�u�q
typedef struct LINE_EQ_INFO
{
	POINT p1, p2;				//two ending point
	double a, b, c;				//equation
}LINE;

bool operator == (const POINT a, const POINT b)
{
	if( fabs(a.x-b.x)>eps ) return false;
	if( fabs(a.y-b.y)>eps ) return false;
	return true;
}

/* ������function�A�P�_>0�Ϊ�<0�̦n���γo�ӥ��ഫ */
int dblcmp(double in)
{
	if(IsZero(in)) return 0;
	return in>0 ? 1:-1;
}

double cross(POINT p0, POINT p1, POINT p2)
{
	return (p1.x-p0.x)*(p2.y-p0.y) - (p1.y-p0.y)*(p2.x-p0.x);
}


/* Line Equation: ��X���I�����u��{�� ax+by+c=0 */
void LineEquation(LINE &line)
{
	POINT p1 = line.p1, p2 = line.p2;
	line.a = p2.y-p1.y;
	line.b = p1.x-p2.x;
	line.c = p1.y*p2.x - p1.x*p2.y;
}

/* Area of Polygon: �O�oŪ�i�Ӫ��I�n���ɰw¶�@��Ϊ̰f�ɰw¶�@�� �A�`�N��װ��D
 * ���D�ت��n�D���A���ƺ��I�ƪ��ܴ��C*/
double FindPolygonArea( vector<POINT>&p )
{
	int i, n=(int)p.size();
	double area=0;
	for(i=1; i<=n; i++)
		area += p[i-1].x*p[i%n].y - p[i%n].x*p[(i-1)].y;
	//area = abs(area);			//�n�P�_���ɰwor�f�ɰw
	return (double)area/2.0;
}

//��X���"�u"�����I
POINT CheckTwoLine(LINE line1, LINE line2)	//���wline���N����I
{
	POINT all[4];

	double a1, a2, b1, b2, c1, c2;
	double d, dx, dy;

	all[0].x = line1.p1.x, all[0].y = line1.p1.y;
	all[1].x = line1.p2.x, all[1].y = line1.p2.y;

	all[2].x = line2.p1.x, all[2].y = line2.p1.y;
	all[3].x = line2.p2.x, all[3].y = line2.p2.y;

	a1=all[0].y-all[1].y, a2=all[2].y-all[3].y;
	b1=all[1].x-all[0].x, b2=all[3].x-all[2].x;
	c1=all[1].x*all[0].y-all[1].y*all[0].x;
	c2=all[3].x*all[2].y-all[3].y*all[2].x;
	d=a1*b2-a2*b1;
	dx=c1*b2-c2*b1,	dy=a1*c2-a2*c1;
	POINT inter;
	inter.x = dx/d, inter.y = dy/d;
	return inter;
}

/* ��Xinterpoly���u�qp1p2�b�f�ɰw��V���b�����涰 */
vector<POINT> FindHalfPlanCut(POINT p1, POINT p2, vector<POINT> interpoly)
{
	int a, b, i, k, N;
	N = (int)interpoly.size();
	vector<POINT>newpoly, ans;

	for(k=0; k<N; k++)
	{
		a = dblcmp(cross(p1, p2, interpoly[k]));
		b = dblcmp(cross(p1, p2, interpoly[(k+1)%N]));

		if(a*b==0)
		{
			if(a>=0) newpoly.push_back(interpoly[k]);
			if(b>=0) newpoly.push_back(interpoly[(k+1)%N]);
		}
		else if(a>0 && b>0)
		{
			newpoly.push_back(interpoly[k]);
			newpoly.push_back(interpoly[(k+1)%N]);
		}
		else if(a*b<0)
		{
			LINE l1, l2;
			l1.p1 = p1, l1.p2 = p2;
			l2.p1 = interpoly[k], l2.p2 = interpoly[(k+1)%N];
			POINT interpoint = CheckTwoLine(l1, l2);
			if(b>0)
			{
				newpoly.push_back(interpoint);
				newpoly.push_back(interpoly[(k+1)%N]);
			}
			else
			{
				newpoly.push_back(interpoly[k]);
				newpoly.push_back(interpoint);
			}
		}
	}

	/* ���s�վ�A�h�����ƪ��I */
	if(newpoly.size()==0) return newpoly;

	ans.push_back(newpoly[0]);
	for(i=1; i<(int)newpoly.size(); i++)
		if(!(newpoly[i]==newpoly[i-1]))
			ans.push_back(newpoly[i]);

	if(ans.size()>1 && ans.back()==ans[0])	ans.pop_back();
	return ans;
}

/* ��X��Ӧh��� "��" �ϰ쪺�涰�A�p�G�ǤJ���polygon���Oconvex hull�A�^�Ǫ�
 * �N�O�o���convex hull���涰 */
double IntersectionOfConvexHull(vector<POINT>poly1, vector<POINT>poly2)
{
	int N1, N2, i;
	N1 = (int)poly1.size(), N2 = (int)poly2.size();

	/* �վ��f�ɰw */
	if(FindPolygonArea(poly1)<0) reverse(poly1.begin(), poly1.end());
	if(FindPolygonArea(poly2)<0) reverse(poly2.begin(), poly2.end());

	/* ����@��convex hull */
	vector<POINT>interpoly;
	interpoly = poly2;

	/* �T�|�@���V�q��A��s�涰�ϰ�A�]�N�O�n�b�o�ӦV�q�䪺�f�ɰw��V�b���� */
	for(i=0; i<N1; i++)
	{
		if(interpoly.size()==0) return 0.0;
		interpoly = FindHalfPlanCut(poly1[i], poly1[(i+1)%N1], interpoly);
	}

	/* ��X�涰���ϰ� */

	//�o�q���Ѫ��{���X�D�n�O�b�P�_���i��涰�O�@���u...�o�˭n���D�حn�D�A�q�`�@���u
	//�]��O���֦s�b
	/*if( dblcmp(fabs(FindPolygonArea(interpoly)))==0 )
	{
		if(interpoly.size()==0) return 0;
		else return 1;
	}
	return 1; */
	return fabs(FindPolygonArea(interpoly));
}

int main()
{
	freopen("3335", "r", stdin);

	int i, N, datacase;
	vector<POINT>poly1, poly2;
	POINT p;

	scanf("%d", &datacase);

	while(datacase--)
	{
		/* initialization */
		poly1.clear();
		poly2.clear();

		/* read the polygon */
		scanf("%d", &N);

		for(i=0; i<N; i++)
		{
			scanf("%lf %lf", &p.x, &p.y);
			poly1.push_back(p);
			poly2.push_back(p);
		}
		//�q�X�֪��ϰ�
		printf("%d\n", dblcmp(IntersectionOfConvexHull(poly1, poly2)));;
	}
	return 0;
}


















