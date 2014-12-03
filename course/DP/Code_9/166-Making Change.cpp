#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX 1200
#define INF 200000000
using namespace std ;
int c[ 6 ] ;
int dp[ MAX ] ;
int dp2[ MAX ] ;
int D ;
int coin[ 6 ] = { 5 , 10 , 20 , 50 , 100 , 200 } ;
int main( )
{
	int t2 , t3 ;
	while( ~scanf( "%d%d%d%d%d%d" , &c[ 0 ] , &c[ 1 ] , &c[ 2 ] , &c[ 3 ] , &c[ 4 ] , &c[ 5 ] ) )
	{
		if( c[ 0 ] == 0 && c[ 1 ] == 0 && c[ 2 ] == 0 && c[ 3 ] == 0 && c[ 4 ] == 0 && c[ 5 ] == 0 )
			break ;
		scanf( "%d.%d", &t2, &t3 ) ;
        D = ( t2*100+t3 ) ;
		for( int i = 0 ; i < MAX ; i++ )
			dp[ i ] = dp2[ i ] = INF ;
		dp[ 0 ] = dp2[ 0 ] = 0 ;
		for( int i = 0 ; i < 6 ; i++ )
			for( int j = 0 ; j < c[ i ] ; j++ )
				for( int k = MAX-1 ; k >= coin[ i ] ; k-- )
					dp[ k ] = min( dp[ k ] , dp[ k-coin[ i ] ]+1 ) ;
		for( int i = 0 ; i < 6 ; i++ )
			for( int j = coin[ i ] ; j < MAX ; j++ )
				dp2[ j ] = min( dp2[ j ] , dp2[ j-coin[ i ] ]+1 ) ;
		int ans = INF ;
		for( int i = MAX-1 ; i >= 0 ; i-- )
		{
			t2 = i >= D ? i : i ;
			t3 = i >= D ? i-D : D-i ;
			//if( dp[ t2 ] != INF && dp[ t3 ] != INF )
				//printf( "%d %d %d %d\n" , t2 , t3 , dp[ t2 ] , dp[ t3 ] ) ;
			if( i >= D )
				ans = min( ans , dp[ t2 ] + dp2[ t3 ] ) ;
			else
				ans = min( ans , dp[ t2 ] + dp[ t3 ] ) ;
		}
		ans = min( ans , dp[ D ] ) ;
		printf( "%3d\n" , ans ) ;
	}
	return 0 ;
}
