 float cross(Point& a, Point& b){	
	return a.x * b.y - b.x * a.y;
}	 // cross a-(0,0) X b-(0,0)
void polygon_area(){
	p[n] = p[0];
	float area = 0.0;
	for (int i=0; i<n; ++i)//or i<top-1(convex hull)
		area += cross(p[i], p[i+1]); 
	cout << "多邊形面積為" << fabs(area) / 2.0;
}
//////////////多面體體積//////////////////////
struct Point {float x, y, z;};
struct Facet {Point a, b, c;} f[10];
 
float dot(Point a, Point b){
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
 
Point cross(Point a, Point b){
	return (Point){
		a.y * b.z - b.y * a.z,
		a.z * b.x - b.z * a.x,
		a.x * b.y - b.x * a.y};
}
float triple(Point a, Point b, Point c){
	return dot(a, cross(b, c));
}
void polygon_volume(){
	float volume = 0.0;
	for (int i=0; i<10; i++)
		volume += triple(f[i].a, f[i].b, f[i].c);
	cout << "多面體體積為" << fabs(volume) / 6.0;
}
////////////多邊形的重心座標////////////
void polygon_centroid(){
    float cx = 0, cy = 0, w = 0;
    for (int i=n-1, j=0; j<n; i=j++){
        float a = cross(p[i], p[j]);	//area
        cx += (p[i].x + p[j].x) * a;
        cy += (p[i].y + p[j].y) * a;
        w += a;
    }
    cout << '(' << cx/3/w << ',' << cy/3/w << ')';
}
////////////判斷是否在裡面//////////////
bool point_in_polygon(){
	bool c=false;
	for(int i=0,j=n-1;i<n;j=i++)
		if( (p[i].y>input.y) != (p[j].y>input.y) &&
			input.x<((p[j].x-p[i].x)*(input.y-p[i].y)/
			(p[j].y-p[i].y)+p[i].x))
			c =!c;
	return c;
}
//////////判斷多邊形裡有幾個整數點///////
p[n]=p[0];
long long int a,b,r,count=0ll;
for(int i=0;i<n;i++){
	a=abs(p[i+1].x-p[i].x);
	b=abs(p[i+1].y-p[i].y);
	r=gcd(a,b);
	count+=r;
}
long long int area=0ll;
for(int i=0;i<n;i++)
	area+=cross(p[i],p[i+1]);
area=abs(area)/2ll;
printf("%lld\n",area+1ll-count/2ll);
//////////三角形三邊與內切圓////////////
s=(l1+l2+l3)/2;
area=sqrt(s*(s-l1)*(s-l2)*(s-l3));
r=2*area/(l1+l2+l3);
//r=abc/(4*area) 外接圓
//l1,l2,l3 為三中線, area*3 為三角形面積
