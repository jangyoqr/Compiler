%{
#include<stdio.h>
int count=0;
int count1=0;
int count2=0;
%}
%%
[A-Z]{1}[a-z]+ {
	for(int i=1; i<yyleng; i++)
	{count++;}
	printf("the alpha num are %d\n",count);
	count=0;
}
\/"*" {count1++;}
"*"\/ {count2++;}
"{" {printf("begin ");}
"}" {printf(" end\n");}
[\n]* {for(int i=0; i<yyleng; i++)printf(" ");	}
%%
int main()
{
	yylex();
	if(count1==count2) printf("the */ and /* counts are same\n");
	else printf("the */ and /* counts are different\n");
}

