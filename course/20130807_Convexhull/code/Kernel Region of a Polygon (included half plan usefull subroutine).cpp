/* Library: 找出一個多邊形核的面積
 *
 * 注意如果回傳0的時候有可能是一條線，要看題目的規定，當然題目如果沒有
 * 這種測試資料，就不用管他...不過通常一條直線也算核存在，即使面積為0
 * 通常這邊不注意就很容易WA
 *
 * Algorithm: 主要是利用半平面相交演算法，O(N2)
 *
 * 套樣板: 找出兩個多邊形 "核區域" 的交集面積，就是傳入的多邊形一樣就可以了
 *
 * 主要核心是在掃描部分，注意在掃描時候是設定為逆時針繞polygon，當然如果輸入
 * 是順時針，程式會自己去掉
 *
 * 面積判斷那邊會傳回負值(有可能)，因為要判定原先給定的順序是逆時針or順時針
 * 所以在回傳時要自己在判斷一下
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

//點
typedef struct POINT_INFO
{
	double x, y;
}POINT;

//線or線段
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

/* 離散化function，判斷>0或者<0最好都用這個先轉換 */
int dblcmp(double in)
{
	if(IsZero(in)) return 0;
	return in>0 ? 1:-1;
}

double cross(POINT p0, POINT p1, POINT p2)
{
	return (p1.x-p0.x)*(p2.y-p0.y) - (p1.y-p0.y)*(p2.x-p0.x);
}


/* Line Equation: 找出兩點的直線方程式 ax+by+c=0 */
void LineEquation(LINE &line)
{
	POINT p1 = line.p1, p2 = line.p2;
	line.a = p2.y-p1.y;
	line.b = p1.x-p2.x;
	line.c = p1.y*p2.x - p1.x*p2.y;
}

/* Area of Polygon: 記得讀進來的點要順時針繞一圈或者逆時針繞一圈 ，注意精度問題
 * 看題目的要求做適當整數福點數的變換。*/
double FindPolygonArea( vector<POINT>&p )
{
	int i, n=(int)p.size();
	double area=0;
	for(i=1; i<=n; i++)
		area += p[i-1].x*p[i%n].y - p[i%n].x*p[(i-1)].y;
	//area = abs(area);			//要判斷順時針or逆時針
	return (double)area/2.0;
}

//找出兩條"線"的交點
POINT CheckTwoLine(LINE line1, LINE line2)	//給定line任意兩端點
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

/* 找出interpoly對於線段p1p2在逆時針方向的半平面交集 */
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

	/* 重新調整，去除重複的點 */
	if(newpoly.size()==0) return newpoly;

	ans.push_back(newpoly[0]);
	for(i=1; i<(int)newpoly.size(); i++)
		if(!(newpoly[i]==newpoly[i-1]))
			ans.push_back(newpoly[i]);

	if(ans.size()>1 && ans.back()==ans[0])	ans.pop_back();
	return ans;
}

/* 找出兩個多邊形 "核" 區域的交集，如果傳入兩個polygon都是convex hull，回傳的
 * 就是這兩個convex hull的交集 */
double IntersectionOfConvexHull(vector<POINT>poly1, vector<POINT>poly2)
{
	int N1, N2, i;
	N1 = (int)poly1.size(), N2 = (int)poly2.size();

	/* 調整到逆時針 */
	if(FindPolygonArea(poly1)<0) reverse(poly1.begin(), poly1.end());
	if(FindPolygonArea(poly2)<0) reverse(poly2.begin(), poly2.end());

	/* 任選一個convex hull */
	vector<POINT>interpoly;
	interpoly = poly2;

	/* 枚舉一條向量邊，更新交集區域，也就是要在這個向量邊的逆時針方向半平面 */
	for(i=0; i<N1; i++)
	{
		if(interpoly.size()==0) return 0.0;
		interpoly = FindHalfPlanCut(poly1[i], poly1[(i+1)%N1], interpoly);
	}

	/* 找出交集的區域 */

	//這段註解的程式碼主要是在判斷有可能交集是一條線...這樣要看題目要求，通常一條線
	//也算是有核存在
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
		//秀出核的區域
		printf("%d\n", dblcmp(IntersectionOfConvexHull(poly1, poly2)));;
	}
	return 0;
}


















