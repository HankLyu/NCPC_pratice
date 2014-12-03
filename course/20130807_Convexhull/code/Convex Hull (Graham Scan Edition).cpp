/* Library: Graham Scan to find the convex hull
 *
 * The point is based from 0~N-1.
 *
 * 如果輸入有許多點共線，則只會出出那些端點構成convex hull的點集合，答案會回存
 * 在hull裡面，回傳hull的點數目
 *
 * 另外會順便記錄那些不是在convex hull裡面的點集合
 *
 * ex: 輸入
 *
 * 6
   0 0
   1 2
   3 4
   2 0
   2 4
   5 0
 *
 * convex: (0, 0) (5, 0) (3, 4) (2, 4) (0, 0) <-包含起點 (程式會自己加)
 * non   : (2, 0) (1, 2)
 *
 * 注意輸入必須要三個點以上...如果輸出的convex hull為一條直線，不存在回傳0
 *
 * 一些類似變形要注意地方
 *
 * (1)求凸包周長: 一個點要直接回傳0.0，其它就"直接"從hull array去計算，不用擔心
 *               那種只有兩個點或者共線情形，因為就算兩個點，也要繞一圈才可
 *               ex: 給定兩個點 (0, 0) (3, 0) => 算出來的hull:
 *               								(0, 0) (3, 0) (0, 0)
 *               因此周長為 3+3 = 6
 *
 * (2)點共線: 如果輸入資料全部都共線，例如(0, 0) (1, 0) (2, 0) (3, 0) 則凸包
 *            會找出這樣 (0, 0) (3, 0) (2, 0)，也就是top回傳要大於等於4才可能
 *            形成一個凸包，當然還是主要要看題目的要求做更改輸出
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
	/* 這邊一定要看好題目要求判斷.... */
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

	/* 再加一是因為要讓輸出可以在多一個base點，也可以選擇不要 */
	++top;						//the hull number

	//這邊也要判斷清楚...看題目說啥...有些題目會故意給兩個點之類...
	if(top<=3)
	{
		printf("Please check the problem description again...\n");
		return 0;		//invalid hull (因為base點會再重複算一次)
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
