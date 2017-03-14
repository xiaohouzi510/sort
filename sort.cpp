#include <stdio.h>
#include <string.h>
#include <map>
#include <stdlib.h>
#include <time.h>

using namespace std;

void quick_sort(int data[],int l,int r)
{
	if(l >= r)
		return ;
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

void merge_array(int src[],int l,int m,int r,int result[])
{
	int k = l;
	int i = l;
	int j = m+1;
	while(i <= m && j <= r)
	{
		if(src[i] < src[j])
			result[k++] = src[i++];
		else
			result[k++] = src[j++];
	}

	for(int z = i;z <= m;++z)
	{
		result[k++] = src[z];
	}

	for(int z = j;z <= r;++z)
	{
		result[k++] = src[z];
	}
	for(int z = l;z <= r;++z)
	{
		src[z] = result[z];
	}
}

void merge_sort(int src[],int l,int r,int result[])
{
	if(l >= r)
		return;
	int mid = (l+r)/2;
	merge_sort(src,l,mid,result);
	merge_sort(src,mid+1,r,result);
	merge_array(src,l,mid,r,result);
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

void merge_sort_test()
{
	srand(time(NULL));
	map<int,bool> haves;
	int len = 10;
	int *array  = new int[len];
	int *result = new int[len];
	map<int,bool>::iterator it;
	int value = 0;
	for(int i = 0;i < len;++i)
	{

		while(true)
		{
			value = rand()%10000;
			it    = haves.find(value);
			if(it == haves.end())
			{
				haves[value] = true;
				array[i]      = value;
				break;
			}
		}
	}
	display(array,len);
	memset(result,0,len);
	merge_sort(array,0,len-1,result);
	display(result,len);
	delete [] array;
	delete [] result;
}

int main(int argc,char *argv[])
{
	merge_sort_test();
	return 0;
}