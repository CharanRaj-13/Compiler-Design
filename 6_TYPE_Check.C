#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
    int n,i,k,flag=0;
    char var[15],typ[15],b[15],c;
    clrscr();
    printf("Enter the number of variables : ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
	printf("Enter the variable [%d]: ",i);
	scanf(" %c",&var[i]);

	printf("Enter the variable type[%d] (float-f,int-i): ",i);
	scanf(" %c",&typ[i]);

	if(typ[i]=='f')
	    flag = 1;
    }
    printf("Enter the expression terminated with '$': ");
    i = 0;

    while((c=getchar())!='$'){
	b[i]=c;
	i++;
    }
    k = i;
    for(i=0;i<k;i++){
	if(b[i]=='/'){
	    flag = 1;
	    break;
	}
    }
    for(i=0;i<n;i++){
	if(b[i]==var[i]){
	    if(flag==1){
		if(typ[i]=='f'){
		    printf("The Datatype is Correctly Defined \n");
		    break;
		}
		else{
		    printf("Identifier %c must be Float Type \n",var[i]);
		    break;
		}
	    }
	    else{
		printf("The Datatype is Correctly Defined \n");
		break;
	    }
	}
    }
    getch();
    return 0;
}