/*
Simple DFA recognition program.
DFA -- (01)*0
*/
#include <stdio.h>

#define STATES	2	/* number of states */
#define SYMBOLS	2	/* number of symbols */

/*
State Tranisition Table in p102.
*/
int ST_TAB[STATES][SYMBOLS] = {
	/* state p */{ 1,0 },
	/* state q */{ 1, 0 }


};

void put_table(int tab[][SYMBOLS], int m, int n)
{
	int i;

	puts("State Transition Table");
	puts("\t0\t1");
	for (i = 0; i < m; i++)
		printf("%c\t%c\t%c\n",
			'A' + i, 'A' + tab[i][0], 'A' + tab[i][1]);
	puts("Final states = { B }");
}

void main()
{
	int ch;	/* input symbol */
	int cur_state = 0;	/* start state */

	put_table(ST_TAB, STATES, SYMBOLS);

	ch = getchar();
	while (ch != '\n') {
		cur_state = ST_TAB[cur_state][ch - '0'];
		if (cur_state < 0) { puts("FAIL"); return; }
		ch = getchar();
	}

	if ( cur_state == 1) puts("OK");	/* final states = { 2 } */
	else puts("FAIL");
}
