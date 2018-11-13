%{
 #include <stdio.h>
%}
Alpha [A-Z]
alpha [a-z]
digit [0-9]
%%
{Alpha}{alpha}+$ {printf("correct %s\n",yytext);}
"["{Alpha}+"]"$ {printf("correct %s\n", yytext);}
[0-1]+$ {
	int k=0;
	 int a, cnt = 1;
	 int re = 0, i;
		a = atoi(yytext);
	while (a>0){
								         if (a % 10==1)
													re += cnt;
												   cnt *= 2;
												a /= 10;
						 }
	if(a%4==0)printf("%s is divisible by 4\n",yytext);
	else printf("%s is not divisible by 4\n",yytext);
				 }
"0B"[0-1]+$ {printf("correct binary number %s\n",yytext);}
"0O"[0-7]+$ {printf("correct octal number %s\n",yytext);}
"0X"{digit}*[A-F|a-f]*{digit}*$ {printf("correct hex number %s\n",yytext);}
"//"[\40-\176]*$ {printf("comment sentence %s\n",yytext);}
"/*"[\40-\176]*"*/"$ {printf("comment lines %s\n",yytext);}
[\40-\176]+$ {printf("C string set %s\n",yytext);}



%%
int main()
{
	yylex();
}
