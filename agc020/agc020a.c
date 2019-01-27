#Include<stdio.h>

int main(){
	int n,a,b;
	scanf("%d %d %d", &n,&a,&b);
	int m = a<b ? b : a;
	int l = a<b ? a : b;

	if((m-l)%2) printf("Borys\n");
	else printf("Alice\n");
	return 0;

}
