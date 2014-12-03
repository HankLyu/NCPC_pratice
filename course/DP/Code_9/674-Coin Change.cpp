#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std ;
long long int dp[ 10000 ] ;
int n , c[ 5 ] = { 1 , 5 , 10 , 25 , 50 } ;
int main( )
{
    dp[ 0 ] = 1 ;
    for( int i = 0 ; i < 5 ; i++ )
        for( int j = c[ i ] ; j < 10000 ; j++ )
            dp[ j ] += dp[ j-c[i] ] ;
    while( ~scanf( "%d" , &n ) )
    {
        printf( "%lld\n" , dp[ n ] ) ;
    }
    return 0 ;
}
