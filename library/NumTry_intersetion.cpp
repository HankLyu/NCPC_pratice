struct node
{
	int x1,y1,x2,y2;
}line[5];

int cross(int x1,int y1,int x2,int y2)
{
	return x1*y2-x2*y1;
}
bool onsegment(int x1,int y1,int x2,int y2,int x3,int y3)
{
	if(min(x2,x3)<=x1 && x1<=max(x2,x3) &&
		min(y2,y3)<=y1 && y1<=max(y2,y3))
		return true;
	return false;
}
bool check(int j,int i)
{
	int d1,d2,d3,d4;
	d1=cross(line[j].x1-line[i].x1, line[j].y1-line[i].y1,
			 line[i].x2-line[i].x1, line[i].y2-line[i].y1);
	d2=cross(line[j].x2-line[i].x1, line[j].y2-line[i].y1,
			 line[i].x2-line[i].x1, line[i].y2-line[i].y1);
	d3=cross(line[i].x1-line[j].x1, line[i].y1-line[j].y1,
			 line[j].x2-line[j].x1, line[j].y2-line[j].y1);
	d4=cross(line[i].x2-line[j].x1, line[i].y2-line[j].y1,
			 line[j].x2-line[j].x1, line[j].y2-line[j].y1);
	if(d1*d2<0 && d3*d4<0)	return true;
	if(d1==0 && onsegment(line[j].x1,line[j].y1,
						  line[i].x1,line[i].y1,
						  line[i].x2,line[i].y2))
		return true;
	if(d2==0 && onsegment(line[j].x2,line[j].y2,
						  line[i].x1,line[i].y1,
						  line[i].x2,line[i].y2))
		return true;
	if(d3==0 && onsegment(line[i].x1,line[i].y1,
						  line[j].x1,line[j].y1,
						  line[j].x2,line[j].y2))
		return true;
	if(d4==0 && onsegment(line[i].x2,line[i].y2,
						  line[j].x1,line[j].y1,
						  line[j].x2,line[j].y2))
		return true;
	return false;
}