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
    for(int i=0; i<n; i++)	// -1 代表這個數字沒有接在其他數字之後
		prev[i]=-1;
    for( int i=0; i<n; i++){
        for(int j=0; j<i; j++)
            if(num[j]<num[i] && (lis[j]+1>lis[i]) ){
                    lis[ i ]  = lis[ j ] + 1 ;
                    prev[ i ] = j ;	// s[i] 接在 s[j] 後面
                	set       = i ;
				}
    }// for i=0;i<n
    int ans = 0 ;
    for( int i = 0 ; i < n ; i++ )
        ans = max( ans , lis[ i ] ) ;
    printf( "LIS SIZE : %d\n" , ans ) ;
    print_LIS( set ) ;
    printf( "\n" ) ;
}
//////////////////////////
int num[maxx],n;
int pnt[maxx],dp[maxx];
vector<int>lis;

void print_LIS()
{
	int len=lis.size();
	for(int i=n-1,j=0;j<len && i>=0;i--)
		if(dp[i]==len-j){
			pnt[len-1-j]=num[i];
			j++;
		}
	for(int i=0;i<len;i++)
		printf("%d\n",pnt[i]);
}
void LIS()
{
	vector<int> :: iterator ltr;
	lis.clear();
	lis.push_back(num[0]);
	dp[0]=1;
	for(int i=1;i<n;i++)
		if(num[i]>lis[lis.size()-1]){
			lis.push_back(num[i]);
			dp[i]=lis.size();
		}
		else{
			ltr=lower_bound(lis.begin(),lis.end(),num[i]);
			dp[i]=ltr-lis.begin()+1;
			*ltr=num[i];
		}
	printf("%d\n-\n",lis.size());
	print_LIS();
} 
