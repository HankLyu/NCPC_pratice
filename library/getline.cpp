char input[max],*p;
gets(input);
int m=0;
for ( p=strtok( input," "); p!=NULL; p = strtok ( NULL, " " ) )
a[m++] = atoi ( p );
