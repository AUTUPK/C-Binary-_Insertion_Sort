#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct {
	int key;
}retype;
typedef struct {
	retype data[MAX];
	int len ;
}sqlist;

void Binsort(sqlist* r,int n) {
	int low, high, mid, i, j;
	
	for ( i = 2; i <=n; i++)
	{
		r->data[0] = r->data[i];
		low = 1; high = i - 1;
		while (low<=high)
		{
			mid = (low + high) / 2;
			if (r->data[0].key >= r->data[mid].key)low = mid + 1;
			else high = mid - 1;
		}
		for ( j =i-1 ; j >=low ; j--)r->data[j + 1] = r->data[j];
		r->data[low] = r->data[0];
	}
}
int main() {
	int n;
	retype a[MAX-1] = { 5,6,1,9,8,2,7,3,4 };
	n = sizeof(a) / sizeof(a[0]);
	sqlist* r = (sqlist*)malloc(sizeof(sqlist));
	for  (int i = 1;  i <= n;  i++)
	{
		r->data[i] = a[i - 1];
	}
	r->len = n;
	Binsort(r, n);
	for (int i = 1; i <=n-1; i++)
	{
		printf("%d,", r->data[i].key);
	}
	printf("%d\n", r->data[n].key);
}