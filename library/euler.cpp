int euler(int n)
{
	int num;
	num=n;
	for(int i=2;i<=n;i++)
		if(n%i==0){
			num=(num/i)*(i-1);
			while(n%i==0)	n=n/i;
		}
	return num;
}
