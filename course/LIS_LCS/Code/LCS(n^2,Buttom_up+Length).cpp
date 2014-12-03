#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAX_1  500
#define MAX_2 1200
using namespace std ;
char s1[ MAX_1 ] ;
char s2[ MAX_2 ] ;
int  dp[ MAX_1 ][ MAX_2 ] ;
int main( )
{
    while( ~scanf( "%s%s" , &s1 , &s2 ) != EOF )
    {
        //初始化注意
        memset( dp , 0  , sizeof( dp ) ) ;
                         /*為'\0'時跳出, i < stelen( s1 )亦可*/
        for( int i = 0 ; s1[ i ] ; i++ )
        {
            for( int j = 0 ; s2[ j ] ; j++ )
            {
                if( s1[ i ] == s2[ j ] )
                    dp[ i+1 ][ j+1 ] = dp[ i ][ j ] + 1 ;
                else
                    dp[ i+1 ][ j+1 ] = max( dp[ i ][ j+1 ] , dp[ i+1 ][ j ] ) ;
            }
        }
        printf( "%d %d %d\n" , strlen( s1 ) , strlen( s2 ) , dp[ strlen( s1 ) ][ strlen( s2 ) ] ) ;
    }
    return 0 ;
}
/*
三組測資:
pretty
women

walking
down

the
street

6 5 1
7 4 2
3 6 2

*/
