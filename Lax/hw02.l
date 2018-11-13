%{
#include <stdio.h>
	void dtob10(int n)
   {     
		 if(n!=1)  dtob10(n/2);
		 printf("%d",n%2);
   }

	 int hextobin(char *hex) {
     int i, h, len = strlen(hex) - 1, buf[8];
			 while (len--) {
			   h = *hex>96 ? *hex++ - 87 : *hex++ - 48;
	       for (i = 7; i >= 0; i--) {
			   buf[i] = h % 2;
				 h = h / 2;
				 }
				 for (i = 0; i<8; i++) {
					 printf("%d", buf[i]);
				 } 
			 }
			 printf("\n");
			 return 0;
	 }
	int count=0;
%}
alpha [a-z]
Alpha [A-Z]
%%
[\t] {printf(" "); count++;} 
{alpha}{4} {
	 printf("alpha change->\t%c%c",yytext[0],yytext[1]);
				 for(int i=2; i<yyleng; i++)  printf("%c",yytext[i]-32);
		    printf("\n");
}

[\32|\n] {count++;}
{alpha}+[\t|\32]*{alpha}* {
						printf("capital letters->");
									  
		
						for(int i=0; i<yyleng; i++)
						 {
							 if(yytext[i]=='\t' | yytext[i]=='\32' | yytext[i]=='\n'){}
							 else if (i==yyleng-1)printf(" %c",yytext[i]-32);
							 else printf("%c",yytext[i]-32);
						 }printf("\n");
				 }
[0-9]+ {
	printf("the decimal number change to binary number ->\t"); 
	dtob10(atoi(yytext));
	 printf("\n");
 }
[a-f|0-9]+ {
	printf("the hex number change to binary number ->\t"); 
	hextobin(yytext);
}


%%
int main()
{
	yylex();
	printf("the space characters are %d\n",count);
}
