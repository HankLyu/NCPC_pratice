int max = 0, tmp, length, width;
for(i = 0; i < n; i++) {
	int sum[100] = {};
	for(j = i; j < n; j++) {
		for(k = 0; k < m; k++) {
			sum[k] += !map[j][k]; //be 1
			if(k == 0 || tmp != length*width)
				tmp = 0, length = 0;
			length++, width = j-i+1;
			tmp += sum[k];
			if(tmp == length*width)
				max = max > tmp ? max : tmp;
		}
	}
}
printf("%d\n", max);
