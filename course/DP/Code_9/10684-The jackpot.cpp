#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 12000
using namespace std ;
int n , num[ MAX ] ;
int Maximum_Subarray( )
{
	int max_sum = 0, sum = 0 ;
	for( int i = 0 ; i < n ; i++ )
	{
		sum += num[i] ;         // 隨時計算總和
		if( sum < 0 )
			sum = 0 ;           // 零總比負數好
		if( sum > max_sum )
			max_sum = sum ;     // 隨時紀錄最大值
	}
	return max_sum ;
}
int main( )
{
	while( scanf( "%d" , &n ) != EOF , n )
	{
		for( int i = 0 ; i < n ; i++ )
			scanf( "%d" , &num[i] ) ;
		int t1 = Maximum_Subarray( ) ;
		if( t1 )
			printf( "The maximum winning streak is %d.\n" , t1 ) ;
		else
			printf( "Losing streak.\n" ) ;
	}
}
