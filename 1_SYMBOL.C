#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<ctype.h>

void main(){
    int i=0,j=0,x=0,n,flag=0;
    void *p, *add[15];
    char ch, srch, b[15],d[15],c;
    
    clrscr();
    printf("Enter an Expression Terminated by '$' :");
    while((c=getchar()) != '$'){
        b[i] = c;
        i++;
    }
    n = i - 1;
    printf("The Expression is : ");
    i = 0;
    while(i<=n){
        printf("%c",b[i]);
        i++;
    }
    printf("\n Symbol Table");
    printf("\n Symbol \t Address \t Type\n");
    while(j<=n){
        c = b[j];
        if(isalpha(isascii(c))){
            p = malloc(c);
	    add[x] = p;
	    d[x] = c;
	    printf("%c\t\t %d \t\t Identifier \n",c,p);
	}
	else{
	    ch = b[j+1];
	    if(ch=='/' || ch=='+' || ch=='-' || ch=='*' || ch=='='){
		p = malloc(c);
		add[x] = p;
		d[x] = c;
		printf("%c\t\t %d \t\t Identifier \n",c,p);
		x++;
	    }
	}
	j++;
    }
    printf("Enter the identifier to be searched : ");
    srch = getch();

    for(i=0;i<=n;i++){
	if(srch==d[i]){
	    printf("Symbol Found: ");
	    printf("%c \t @Address: \t %d",srch,add[i]);
	    flag = 1;
	}
    }
    if(flag==0){
	printf("Symbol Not Found");
    }
    getch();
}