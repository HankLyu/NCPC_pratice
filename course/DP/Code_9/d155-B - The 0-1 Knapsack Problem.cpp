#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXSIZE 1200
using namespace std ;
int W , n ;
int dp[MAXSIZE] ;
struct P
{
	int weight , value ;
};
P p[120] ;
bool cmp( P a , P b )
{
	return a.weight < b.weight ;
}
void DP( )
{
	int i , j ;
	memset( dp , 0 , sizeof( dp ) ) ;
	for( i = 0 ; i < n ; i++ )
		for( j = W ; j >= p[i].weight ; j-- )
			dp[j] = max( dp[j-p[i].weight] + p[i].value , dp[j] ) ;		
} 
int main( )
{
	int i , j ;
	int t ;
	scanf( "%d" , &t ) ;
	while( t-- )
	{
		scanf( "%d" , &W ) ;
		scanf( "%d" , &n ) ;
		for( i = 0 ; i < n ; i++ )
			scanf( "%d" , &p[i].value ) ;
		for( i = 0 ; i < n ; i++ )
			scanf( "%d" , &p[i].weight ) ;
		//sort( p , p+n , cmp ) ;
		DP( ) ;
		printf( "%d\n" , dp[W] ) ;
	}
	return 0 ;
}
