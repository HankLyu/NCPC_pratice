/* Library : Data structure for Defined Segment tree
 *
 * (1) Create (initialize the segment tree).
 *
 * (2) Operation template.
 *
 * Note the index of the first is from 1.
 *
 *  */


#include <iostream>
#include <algorithm>
#define MAXN 100010
using namespace std;

/* create the segment tree */
typedef struct NODE_INFO
{
	int beg, end, cost;
}NODE;
NODE tree[3*MAXN];

/* subroutine: Create the tree */
void create(int id, int beg, int end)
{
	/* Set the segment */
	tree[id].beg = beg, tree[id].end = end;

	/* For the leaf */
	if(beg==end)
	{
		tree[id].cost = 1;		//user defined cost for leaf
		return;
	}

	/* Two part */
	int mid = (beg+end) >> 1;

	create(2*id, beg, mid);
	create(2*id+1, mid+1, end);

	/* set the freq by the two part and compare with mid
	 * => This can also be used defined.
	 * */
	tree[id].cost = max(tree[2*id].cost, tree[2*id+1].cost);

}

/* Find the interval and set the interval
 *
 * Do some specific operation in the range [ita, itb]
 *
 *  */
int find_interval(int id, int beg, int end, int ita, int itb)
{
	/* invalid condition */
	if( ita>end || itb<beg ) return 0;

	/* For all cover */
	if( ita<=beg && end<=itb )
	{
		return tree[id].cost;
	}

	/* Travel */
	if(beg==end)	//for the leaf
	{
		return 1;	//cost is user-defined
	}
	else			//for the two part
	{
		int lf, rf, mid;
		mid = (beg+end) >>1;

		lf = find_interval(2*id, beg, mid, ita, itb);
		rf = find_interval(2*id+1, mid+1, end, ita, itb);

		return max(lf, rf);
	}
	return -1;
}

int main()
{
	/* create the segment tree
	 *
	 * create(1, 1, MAXRANGE);
	 *
	 * */

	/* Use the operation */
}
