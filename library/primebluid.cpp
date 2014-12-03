bool isprime[max];

void sieve(){
	memset(isprime,true,sizeof(isprime));
	isprime[0]=false;
	isprime[1]=false;
	for(int i=2;i<=sqrt(max);i++)
		if(isprime[i])
			for(int j=i*i;j<max;j += i)
				isprime[j]=false;
}
