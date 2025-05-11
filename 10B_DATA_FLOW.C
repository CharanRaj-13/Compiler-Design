#include<stdio.h>
#include<string.h>

struct op{
    char l[20];
    char r[20];
}op[10];

void main(){
    int i,j,n,lineno = 1;
    char *match;
    printf("\n Enter the number of values : ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
	printf("\n Left : ");
	scanf("%s",op[i].l);
	printf("\n Right : ");
	scanf("%s",op[i].r);
    }

    printf("\n Intermediate Code");
    for(i=0;i<n;i++){
	printf("\n Line N0 = %d",lineno);
	printf("\t\t %s = %s",op[i].l,op[i].r);
	lineno++;
    }

    printf("\n ***Data Flow Analysis for Above Code***");
    for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	    match = strstr(op[j].r,op[i].l);
	    if(match)
		printf("\n %s is live at %s",op[i].l,op[j].r);
	}
    }
    getch();
}