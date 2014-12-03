#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
#define MAX 100000
using namespace std ;
int  num[ MAX ] , n ;
int  lis[ MAX ] ;
int prev[ MAX ] ;	                // prev[x] 紀錄 s[x] 是接在哪個位置的數字後面
                                    // 如果它前面沒有數字就紀錄 -1
int set ;
void print_LIS( int x )
{
    if( prev[ x ] != -1 )
		print_LIS( prev[ x ] ) ;
	printf( "%d " , num[ x ] ) ;
}
void LIS1( )                        //最長lis的一組解(含印出) + 最長lis值
{
    for( int i = 0 ; i < n ; i++ )	// -1 代表這個數字沒有接在其他數字之後
		prev[ i ] = -1 ;
    for( int i = 0 ; i < n ; i++ )
    {
        for( int j = 0 ; j < i ; j++ )
            if( num[ j ] < num[ i ] )
                if( lis[ j ] + 1 > lis[ i ] )
                {
                    lis[ i ]  = lis[ j ] + 1 ;
                    prev[ i ] = j ;	// s[i] 接在 s[j] 後面
                	set       = i ;
				}
    }
    int ans = 0 ;
    for( int i = 0 ; i < n ; i++ )
        ans = max( ans , lis[ i ] ) ;
    printf( "LIS SIZE : %d\n" , ans ) ;
    print_LIS( set ) ;
    printf( "\n" ) ;
}
void LIS2( )//最長lis值
{
  	int lismax = 1 ;//避免為一個測資
  	for( int i = 0 ; i < n ; i++ )
  	{
     	for( int j = i-1 ; j >= 0 ; j-- )
     	{
        	if( num[ i ] > num[ j ] )
        	{
           		lis[ i ] = max( lis[ i ] , lis[ j ]+1 ) ;
           		lismax   = max( lismax , lis[ i ] ) ;
        	}
     	}
  	}
  	printf( "LIS SIZE : %d\n" , lismax ) ;
}
int main( )
{
   	while( scanf( "%d" , &n ) != EOF )
   	{
	  	for( int i = 0 ; i < n ; i++ )
	  	{
	     	scanf( "%d" , &num[i] ) ;
	     	lis[ i ] = 1 ;
	  	}
	  	LIS1( ) ;
	  	LIS2( ) ;
   	}
   	return 0 ;
}
/*
9
9 5 2 8 7 3 1 6 4
*/

