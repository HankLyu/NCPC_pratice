#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std ;
int num[ MAX ] , n ;
int pos[ MAX ] ;
int pnt[ MAX ] ;
vector <int> lis ;
void print_LIS( )
{
	for( int i = n-1 , j = 0 ; j < (int)lis.size( ) && i >= 0 ; i-- )
	{
		if( pos[ i ] == (int)lis.size( ) - j )
		{
			pnt[ (int)lis.size( )-1-j ] = num[ i ] ;
			j++ ;
		}
	}
	for( int i = 0 ; i < (int)lis.size( ) ; i++ )
		printf( "%d " , pnt[ i ] ) ;
	printf( "\n" ) ;
}
void LIS( )//最長lis的一組解(含印出) + 最長lis值
{
	vector <int> :: iterator ltr ;
	lis.clear( ) ;
	lis.push_back( num[ 0 ] ) ;
	pos[ 0 ] = 1 ;
	for( int i = 1 ; i < n ; i++ )
	{
		if( num[ i ] > lis[ lis.size()-1 ] )
		{
			lis.push_back( num[ i ] ) ;
			pos[ i ] = lis.size( ) ;
		}
		else
		{
		    //lower_bound( ) 返回鍵值>=给定元素的第一個位置
		    //http://www.cplusplus.com/reference/algorithm/lower_bound/
			ltr      = lower_bound( lis.begin() , lis.end() , num[ i ] ) ;
			pos[ i ] = ltr - lis.begin() + 1 ;
			*ltr = num[ i ] ;
		}
        /*
		for( int j = 0 ; j < lis.size( ) ; j++ )
            printf( "%d%c" , lis[ j ] , j == lis.size( )-1 ? '\n' : ' ' ) ;
        for( int j = 0 ; j < i ; j++ )
            printf( "%d%c" , pos[ j ] , j == i-1 ? '\n' : ' ' ) ;
        puts( "" ) ;
        */
	}
	printf( "LIS SIZE : %d\n" , lis.size( ) ) ;
	print_LIS( ) ;
}
int main( )
{
	while( scanf( "%d" , &n ) != EOF )
	{
		for( int i = 0 ; i < n ; i++ )
			scanf( "%d" , &num[i] ) ;
		LIS( ) ;
	}
	return 0 ;
}
