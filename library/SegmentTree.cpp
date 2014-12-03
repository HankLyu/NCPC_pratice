struct node{
	int beg,end, cmax,cmin;
}tree[3*maxx];
int num[maxx];
struct node2{// record ans
	int cmax,cmin;
};	//create(1,1,n); num for 1 to n
void create(int id,int beg,int end){
	tree[id].beg=beg,tree[id].end=end;
	if(beg==end){
		tree[id].cmax=num[beg];
		tree[id].cmin=num[end];
		return ;
	}
	int mid=(beg+end)/2;
	create(2*id,beg,mid);
	create(2*id+1,mid+1,end);
	tree[id].cmax=max(tree[2*id].cmax, tree[2*id+1].cmax);
	tree[id].cmin=min(tree[2*id].cmin, tree[2*id+1].cmin);
}	//findans(1,1,n,a,b);
node2 findans(int id,int beg,int end,int ita,int itb){
	node2 tmp;
	tmp.cmax=0,tmp.cmin=2e9;
	if(ita>end || itb<beg)	return tmp;	//is total out
	if(ita<=beg && end<=itb){			//is total in
		tmp.cmax=tree[id].cmax;
		tmp.cmin=tree[id].cmin;
		return tmp;
	}
	if(beg==end){	//one point
		tmp.cmax=tree[id].cmax;
		tmp.cmin=tree[id].cmin;
		return tmp;
	}
	int  mid=(beg+end)/2;	//some is out,some is in
	node2 lf,rf;
	lf=findans(2*id,beg,mid,ita,itb);
	rf=findans(2*id+1,mid+1,end,ita,itb);
	tmp.cmax=max(lf.cmax,rf.cmax);
	tmp.cmin=min(lf.cmin,rf.cmin);
	return tmp;
}
////////////find frequency///////////
struct node{
	int l,r;int a,b,c;
}ln[maxx*3];
int n,q;
int num[maxx],pb[maxx];

void make(int l,int r,int id){
	ln[id].l=l,ln[id].r=r;
	int mid=(l+r)/2;
	ln[id].a=pb[l],ln[id].b=pb[r];
	if(l+1==r){
		ln[id].c=pb[r]-pb[l];
		return ;
	}
	make(l,mid,2*id);
	make(mid,r,2*id+1);
	ln[id].c=max(ln[2*id].c,ln[2*id+1].c);
}
int query(int a,int b,int id){
	if(a==ln[id].a && b==ln[id].b)	return ln[id].c;

	if(ln[id].l+1==ln[id].r)	return b-a;

	if(b<=ln[2*id+1].a)	return query(a,b,2*id);
	if(a>=ln[2*id+1].a)	return query(a,b,2*id+1);
	return max(query(a,ln[2*id+1].a,2*id),query(ln[2*id+1].a,b,2*id+1));
}
int m=1;
pb[0]=0;
for(int i=1;i<n;i++)
	if(num[i]!=num[i-1])
		pb[m++]=i;
pb[m]=n;
printf("%d\n",query(a-1,b,1));
///////binary index tree////////////////
int lowbit(int in){
	return in&(-in);
}
int getsum(int end){
	int tmp=0;
	while(end){
		tmp+=s[end];
		end -= lowbit(end);
	}
	return tmp;
}
void change(int end,int delta){
	for(int i=end;i<maxx;i+=lowbit(i))
		s[i]+=delta;
}
////2 dimetion
void change(int x,int y,int delta){
	for(int i=x;i<maxx;i+=lowbit(i))
		for(int j=y;j<maxx;j+=lowbit(j))
			tree[i][j]+=delta;
}
int getsum(int x,int y){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			sum+=tree[i][j];
	return sum;
}
sum=0;
l++,b++,r++,t++;//l<x<r,b<y<t,l r is column,b t is row
sum=getsum(r,t)-getsum(l-1,t)-getsum(r,b-1)+
getsum(l-1,b-1);
printf("%d\n",sum);
/////change a rectangel
change(x1,y1,d);
change(x2+1,y2+1,d);
change(x2+1,y1,-d);
change(x1,y2+1,-d);
/////
