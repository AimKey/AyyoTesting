# include <stdio.h>
#include <stdlib.h>

int main () {
	int n,i, j;
	printf ("Nhap so hang N = ");
	scanf ("%d", &n);
	int m = 2*n - 1;
	int arr[n][m];
	for ( i = 0; i < n; i ++){
		for ( j = 0; j < m; j ++) {
			if (i >= abs( n - 1 - j)) {
				arr[i][j] = (2 * i + 1 - abs( n - 1 - j) ) % 10;
			} else {
				arr[i][j] = 11;
			}
		}
 	}
	for ( i = 0; i < n; i ++){
		for ( j = 0; j < m; j ++) {
			if (arr[i][j] == 11) {
				printf("  ");
			continue;
			}
			printf ("%d ", arr[i][j]);
		}
		printf ("\n");
	}
}