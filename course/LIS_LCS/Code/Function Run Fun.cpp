#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define MAX 52
using namespace std ;
int dp[ MAX ][ MAX ][ MAX ] ;
int DP( int a , int b , int c )
{
    if( a <= 0 || b <= 0 || c <= 0 )
        return 1 ;
    if( a > 20 || b > 20 || c > 20 )
        return DP( 20 , 20 , 20 ) ;
    if( dp[ a ][ b ][ c ] )
        return dp[ a ][ b ][ c ] ;
    if( a < b && b < c )
        dp[ a ][ b ][ c ] = DP( a , b , c-1 ) + DP( a , b-1 , c-1 ) - DP( a , b-1 , c ) ;
    else
        dp[ a ][ b ][ c ] = DP( a-1 , b , c ) + DP( a-1 , b-1 , c ) + DP( a-1 , b , c-1 ) - DP( a-1 , b-1 , c-1 ) ;
    return dp[ a ][ b ][ c ] ;
}
int main( )
{
    int a , b , c ;
    memset( dp , 0 , sizeof( dp ) ) ;
    while( ~scanf( "%d%d%d" , &a , &b , &c ) )
    {
        if( a == -1 && b == -1 && c == -1 )
            break ;
        printf( "w(%d, %d, %d) = %d\n" , a , b , c , DP( a , b , c ) ) ;
    }
    return 0 ;
}
