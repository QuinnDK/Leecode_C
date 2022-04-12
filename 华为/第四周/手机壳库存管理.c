#include <stdio.h>
#include <stdlib.h>
#define MAXN 1001

typedef struct {
	float stock;    
	float price;    
	float each;    
} Phone;
int cmp ( const void *a, const void*b ) {
	Phone c1 = *(Phone *)a;    
	Phone c2 = *(Phone *)b;
	return c2.each > c1.each;    
}
int main(void) {
	int N, i;
	float D, total;
	Phone phoneK[MAXN];
	//计算单价，降序
	scanf("%d %f", &N, &D);
	for ( i = 0; i < N; i++ )	scanf("%f", &phoneK[i].stock);	
	for ( i = 0; i < N; i++ )	scanf("%f", &phoneK[i].price);
	for ( i = 0; i < N; i++ )	phoneK[i].each = phoneK[i].price / phoneK[i].stock;
 
	qsort ( phoneK, N, sizeof(Phone), cmp );    
	total = 0;
  
	for( i = 0; i < N && D > 0; i++ ) {
		if ( phoneK[i].stock <= D ) {    
			total += phoneK[i].price;    
			D -= phoneK[i].stock;    
		} else {    
			total += D * phoneK[i].each;   
			D = 0;   
		}
	}
	printf("%.2f\n", total);
	
	return 0;
}