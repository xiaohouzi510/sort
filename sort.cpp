#include <stdio.h>

void quick_sort(int data[],int l,int r)
{
	if(l < r)
	{
		int x = data[l];
		int i = l;
		int j = r;
		while(i < j)
		{
			while(i < j && x < data[j])
			{
				--j;
			}

			if(i < j)
			{
				data[i++] = data[j];
			}

			while(i < j && x > data[i])
			{
				++i;
			}

			if(i < j)
			{
				data[j--] = data[i];
			}
		}
		data[i] = x;
		quick_sort(data,l,i-1);
		quick_sort(data,i+1,r);
	}
}

void display(int data[],int len)
{
	for(int i = 0;i < len;++i)
	{
		printf("%d ",data[i]);
	}
	printf("\n");
}

void quick_sort_test()
{
	int array[] = {10,30,8,77,99,28,43,65};
	int len = sizeof(array)/sizeof(array[0]);
	display(array,len);
	quick_sort(array,0,len-1);
	display(array,len);
}

int main(int argc,char *argv[])
{
	return 0;
}