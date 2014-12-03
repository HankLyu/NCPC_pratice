void print_big(node n){
	int i=1000;
	while(n.num[i]==0 &&i>=0)	i--;
	printf("%d",n.num[i]);
	i--;
	for(;i>=0;i--)
		printf("%04d",n.num[i]);
	printf("\n");
}
node add(node b,node c){
	node a;
	memset(&a,0,sizeof(a));
	int sum;
	for(int i=0;i<maxx;i++){
		sum=b.num[i]+c.num[i];
		a.num[i]+=sum%base;
		a.num[i+1]+=sum/base;
	}
	//a.num[0]+=b.num[0]+c.num[0];
	return a;
}
///////////////////////
typedef struct{
	long l,s[maxl];
}bign;
void Add(bign &c,bign &a,bign &b){
	memset(&c,0,sizeof(c));
	c.l=(a.l>b.l?a.l:b.l);
	for(long i=0;i<c.l;i++){
	   c.s[i]+=a.s[i]+b.s[i];
	   if(c.s[i]>=100000){
		  c.s[i]-=100000;
		  c.s[i+1]++;
	   }
	}
	if(c.s[c.l]) c.l++;
}
void Print(bign &a){
	printf("%ld",a.s[a.l-1]);
	for(long i=a.l-2;i>=0;i--)
	  printf("%05ld",a.s[i]);
}
bign t1,t2;
Add(t1,d[i-1],d[i-1]);
Add(t2,t1,d[i-2]);
Add(d[i],t2,d[i-3]);
