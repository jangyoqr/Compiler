/*
DFA by goto statement.

Regular expression for a*b".
*/
#include <stdio.h>

#define FAIL 0;
#define OKAY 1;

int ch;

int dfa()
{
	ch = getchar();
S:
	if (ch == 'a') {
		ch = getchar();
		goto A;
	}
	
	else return FAIL;
A:
	if (ch == 'b') {
		ch = getchar();
		goto F;
	}
	else if (ch == 'a') {
		ch = getchar();
		goto A;
	}
	else return FAIL;

F:
	if (ch == '\n') {
		return OKAY;
	}
	else return FAIL;

}

int main()
{
	if (dfa())
		puts("OK");
	else puts("FAIL");
}
