#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 120
using namespace std ;
int n , num[ MAX ][ MAX ] ;
int Maximum_Subarray( int a , int b )
{
	int max_sum = 0, sum = 0;
	for( int i = 1 ; i <= n ; i++ )
	{
		sum += num[i][b] - num[i][a] ;  // ÀH®É­pºâÁ`©M
		if( sum < 0 )
			sum = 0 ;                   // ¹sÁ`€ñ­tŒÆŠn
		if( sum > max_sum )
			max_sum = sum ;             // ÀH®É¬ö¿ý³Ì€j­È
	}
	return max_sum ;
}
int main( )
{
	int ans ;
	while( scanf( "%d" , &n ) != EOF )
	{
		memset( num , 0 , sizeof( num ) ) ;
		for( int i = 1 ; i <= n ; i++ )
			for( int j = 1 ; j <= n ; j++ )
				scanf( "%d" , &num[ i ][ j ] ) ;
		for( int i = 2 ; i <= n ; i++ )
			for( int j = 1 ; j <= n ; j++ )
				num[ j ][ i ] += num[ j ][ i-1 ] ;
		/*for( i = 1 ; i <= n ; i++ )
		{
			for( j = 0 ; j <= n ; j++ )
				printf( "%d " , num[i][j] ) ;
			printf( "\n" ) ;
		}*/
		ans = 0 ;
		for( int i = 0 ; i <= n ; i++ )
			for( int j = i+1 ; j <= n ; j++ )
				ans = max( ans , Maximum_Subarray( i , j ) ) ;
		printf( "%d\n" , ans ) ;
	}
	return 0 ;
}
