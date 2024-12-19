#include <stdio.h>
#include <stdlib.h>

int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main() {
    int *arr = malloc(3*sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for(int i=0; i<3; i++){
	printf("Enter number %d:", i+1);
	while (scanf("%d", arr+i) != 1) {
		printf("Invalid input. Try again:");
		while (getchar() != '\n');
	}
    }

    printf("Sum: %d\n", add(arr, arr+1, arr+2));

    free(arr);

    return 0;
}
