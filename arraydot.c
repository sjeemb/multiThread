#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a[100],b[100],c[100];
	int i;

	for(i=0;i<100;i++)
	{
		a[i]=i;
		b[i]=i+2;
		c[i]=a[i]*b[i];
	}
}	
