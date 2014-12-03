#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAX 310
#define INF 10000000
using namespace std ;
long long int dp1[ MAX ][ MAX ] ;
struct C
{
    int c1 , c2 ;
};
C c[ 45 ] ;
int n , m ;
bool cmp( C a , C b )
{
    if( a.c1 < b.c1 )
        return 1 ;
    if( a.c1 == b.c2 && a.c2 < b.c2 )
        return 1 ;
    return 0 ;
}
int main( )
{
    int t ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        scanf( "%d %d" , &n , &m ) ;
        for( int i = 0 ; i < n ; i++ )
            scanf( "%d %d" , &c[ i ].c1 , &c[ i ].c2 ) ;
        for( int i = 0 ; i < MAX ; i++ )
            for( int j = 0 ; j < MAX ; j++ )
                dp1[ i ][ j ] = INF*INF ;
        dp1[ 0 ][ 0 ] = 0 ;
        //sort( c , c+n , cmp ) ;
        for( int i = 0 ; i < n ; i++ )
            for( int j = c[ i ].c1 ; j < MAX ; j++ )
                for( int k = c[ i ].c2 ; k < MAX ; k++ )
                    dp1[ j ][ k ] = min( dp1[ j ][ k ] , dp1[ j-c[ i ].c1 ][ k-c[ i ].c2 ]+1 ) ;
        long long int ans = INF*INF ;
        for( int i = 0 ; i <= m ; i++ )
            for( int j = 0 ; j <= m ; j++ )
                if( i*i+j*j == m*m )
                    ans = min( ans , dp1[ i ][ j ] ) ;
        if( ans == INF*INF )
            printf( "not possible\n" ) ;
        else
            printf( "%lld\n" , ans ) ;
    }
    return 0 ;
}
