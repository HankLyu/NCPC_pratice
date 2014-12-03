/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

#define maxx 50005

using namespace std;

struct node
{
	int x,y;
	bool operator<(const node& a)const{
		return x<a.x;
	}
}line[maxx];
vector<node>ans;

int main()
{
	int test;
	int n,len,a,b;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&len);
		n=0;
		while(scanf("%d %d",&a,&b)!=EOF){
			if(a==0 && b==0)	break;
			line[n].x=a,line[n].y=b;
			n++;
		}
		sort(line,line+n);
		int left=0,right=0,tmp;
		for(int i=0;i<n;i++){
			tmp=-1;
			for(;i<n && line[i].x<=left;i++)
				if(line[i].y>right){
					right=line[i].y;
					tmp=i;
				}
			if(tmp==-1)	break;
			ans.push_back(line[tmp]);
			if(right>=len)	break;
			left=right;
			i--;
		}
		if(right<len){
			printf("0\n");
			continue;
		}
		len=ans.size();
		printf("%d\n",len);
		for(int i=0;i<len;i++)
			printf("%d %d\n",ans[i].x,ans[i].y);
		ans.clear();
		if(test)	printf("\n");
	}
	return 0;
}*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
 
int M;
 
struct Segment{
  int start;
  int end;
};
 
bool cmp( Segment a, Segment b ){
  if( a.start < b.start ) return true;
  return false;
}
 
int main(){
  int testcase;
  int temp, left, right;
  Segment input;
  vector<Segment> lines, answer;
   
  while( scanf( "%d", &testcase ) != EOF ){
    for( int i = 0 ; i < testcase ; i++ ){
      if( i ) printf( "\n" );
       
      scanf( "%d", &M );
       
      lines.clear();
      while( scanf( "%d%d", &input.start, &input.end ) != EOF &&
             ( input.start != 0 || input.end != 0 ) )
        lines.push_back( input );
         
      sort( lines.begin(), lines.end(), cmp );
       
      answer.clear();
      left = 0;
      right = 0;
      for( int i = 0 ; i < lines.size() ; i++ ){
        temp = -1;
        for( ; i < lines.size() && lines[i].start <= left ; i++ )
          if( lines[i].end > right ){
            right = lines[i].end;
            temp = i;
          }
        if( temp == -1 ) break;
        answer.push_back( lines[temp] );
        if( right >= M ) break;
        left = right;
        i--;
      }
       
      if( right < M ){
        printf( "0\n" );
        continue;
      }
      printf( "%d\n", answer.size() );
      for( int i = 0 ; i < answer.size() ; i++ )
        printf( "%d %d\n", answer[i].start, answer[i].end );
    }
  }
  return 0;
}
