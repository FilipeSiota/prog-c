#include <stdio.h>
#include <stdlib.h>

int main() {
	int end;
	
	printf("Hello World!\n");
	
	printf("\nSequencia ate: ");
	scanf("%d", &end);
	
	for(int i = 0; i <= end; i++){
		printf("%d\n",i);
	}
	
	system("pause");
	return 0;
}
