#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1200
using namespace std ;
int  len ;
bool use[ MAX ][ MAX ] ;
int   dp[ MAX ][ MAX ] ;
int path[ MAX ][ MAX ] ;
char  w1[ MAX ] , w2[ MAX ] , w3[ MAX ] ;
int LCS( int n1 , int n2 )//1000ms limit for MAXSIZE = 10XX is OK
{
	if( n1 < 0 || n2 < 0 )
		return 0 ;
	if( use[ n1 ][ n2 ] == true )
		return dp[ n1 ][ n2 ] ;
	if( w1[ n1 ] == w2[ n2 ] )
	{
		dp[ n1 ][ n2 ]   = LCS( n1-1 , n2-1 ) + 1 ;
		path[ n1 ][ n2 ] = 1 ;
	}
	else
	{
		int t1 = LCS( n1-1 , n2 ) ;
		int t2 = LCS( n1 , n2-1 ) ;
		if( t1 < t2 )
			dp[ n1 ][ n2 ] = t2 , path[ n1 ][ n2 ] = 2 ;
		else
			dp[ n1 ][ n2 ] = t1 , path[ n1 ][ n2 ] = 3 ;
	}
	use[ n1 ][ n2 ] = true ;
	return dp[ n1 ][ n2 ] ;
}
void find_LCS( int n1 , int n2 )
{
	if( n1 < 0 || n2 < 0 )
		return ;
	if( path[ n1 ][ n2 ] == 3 )
		find_LCS( n1-1 , n2 ) ;
	else if( path[ n1 ][ n2 ] == 2 )
		find_LCS( n1 , n2-1 ) ;
	else if( path[ n1 ][ n2 ] == 1 )
	{
		w3[ --len ] = w1[ n1 ] ;
		find_LCS( n1-1 , n2-1 ) ;
	}
}
int main( )
{
	int m ;
	while( ~scanf( "%s%s" , &w1 , &w2 ) )
	{
		memset( use  , 0 , sizeof( use ) ) ;
		memset( dp   , 0 , sizeof( dp ) ) ;
		memset( path , 0 , sizeof( path ) ) ;
		m = len = LCS( strlen( w1 )-1 , strlen( w2 )-1 ) ;
		find_LCS( strlen( w1 )-1 , strlen( w2 )-1 ) ;
		w3[ m ] = '\0' ;
		printf( "%s\n" , w3 ) ;
		//system("pause");
	}
	return 0 ;
}
/*
LSC 最長共同子序列( Top-down方法 , n^2 )
注意 dp[][] , use[][] , path[][] 的大小限制 及其意義

三組測資:
pretty
women

walking
down

the
street

e
wn
te

*/
