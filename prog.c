#include <ncurses.h>			// ncurses.h includes stdio.h
#include <string.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define gi(x,y) (y*w + x)
#define size (h*w)

#define SEXT (char*)EXT
#define EL strlen(SEXT)
#define EXT &IS[4]
#define SIS (char *)IS

#define P V[0]

#define SX (b*)((int)p ^ (int)c)
#define S p = SX; c = SX; p = SX;

#define COMMENT ((IS[6]&0xff))
#define STOP  	((IS[6]>>8)&0xff)
#define EMPTY 	((IS[6]>>16)&0xff)
#define ED 		((IS[6]>>24)&0xff)

#define DEAD IS[7]
#define h IS[8]
#define w IS[9]

#define D addch(DEAD
#define MC memcpy((char*)a
#define I foo[4](SIS);foo[4](SEXT);initscr();getmaxyx(stdscr,h,w);halfdelay(1);start_color();init_pair(1, COLOR_RED, COLOR_WHITE);attron(COLOR_PAIR(1));curs_set(0);

#define r0 return(0);

#define O foo[v--](0,0);
#define o 0
#define oo :o
#define bar(x) foo[x]();
#define b bool
#define g (unsigned int)foo[5](x, y)

int (*foo[10])();
b *c, *p;
//                   |Iteration               End of Iteration|  | .life         | IS[6]     |IS[7]|IS[8]|IS[9]|IS[10]|
unsigned int IS[] = {0x0df12b49, 0x06f513ef, 0x05e6ccff, 0x9c3f, 0xfdfd3e2e, 0xff, 0x0a2e7121, 0x20, 0x00, 0x00,  0x03}; // Game constants

int sIS(char *c)
{
	char prev = o;
	sIS:
	if(*c)	// Only do something when we are not at the end
	{
		*c += prev;
		prev = *c;
		c++;
		goto sIS;
	}
	r0
}

int gnd(int x, int y)
{
	int nrED;
	(p[gi(x, y)]) ? (nrED=-1) : (nrED=0);
	
	for(int dy=(y-1); dy<= (y+1); dy++)
	{
		for(int dx=(x-1); dx<=(x+1); dx++)
		{			
			int xt = dx;
			int yt = dy;

			(xt < o) ? (xt = w -1) : ((xt >= w ) ? (xt = o) oo);
			(yt < o) ? (yt = h-1) : ((yt >= h) ? (yt = o) oo);

			p[gi(xt, yt)] ? nrED++:o;
		}
	}
	return nrED;
}

int ul(int x, int y)
{
	p[gi(x,y)] ? ((!((g-2)<2))? (c[gi(x,y)] = false) : (c[gi(x,y)] = true)) : ((g == IS[10]) ? (c[gi(x,y)] = true) : (c[gi(x,y)] = false));
	x++;
	
	(x >= w) ? (x = o,	y++) oo;
	(y < h+1) ?  (foo[2](x, y), x=x) oo;
	r0
}

int pl(int i, int j)
{
	if(i == o)
	{
		move(o,o);
	}
	
	if (i >= size)
	{
		static int iteration;
		mvprintw(o,o, SIS, iteration++);
		refresh();
	}
	else
	{
		i[c] ? D|ED) : D);
		pl(i+1, 2);
	}
	r0
}

b rf(char *filename)
{
	b retVal = false;
	FILE *readFP = fopen(filename, "r");
	if(readFP == NULL)
	{
		return false;
	}
	
	b sol = true;
	b sl = false;
	
	if ( readFP != NULL )
	{
		retVal = true;

		int x = o;
		int y = o;
		int ch;
notEOF:
		ch = fgetc( readFP );
		
		if(ch == EOF)
		{
			goto done;
		}
		
		sol ? (sol = false, (ch == COMMENT) ? sl = true oo) oo;
		(ch == '\n') ? (y++, x=o, sol = true, sl = false) : ((!sl)?	(c[gi(x,y)] = !(isspace(ch) || ch == EMPTY)), x++oo);
		(x >= w) ? (x = o, y++) oo;
		
		if(y >= h)
		{
			goto done;
		}
		goto notEOF;
	}	
	done:
	fclose(readFP);
	
	return retVal;
}

int main(int a, char **V)
{		
	foo[o] = getch;
	foo[1] = pl;
	foo[2] = ul;
	foo[3] = endwin;
	foo[4] = sIS;
	foo[5] = gnd;
	
	I

	c = calloc(size<<1, sizeof(b));// Create a double sized buffer  
	p = c+size;				// Set p to half of the buffer
	b ld = true;
	
	// Initial board
	(a > 1) ? (ld = !rf(V[1]))oo;
	ld ? (a = (int)calloc( strlen(P) + EL + 1, 1), MC, P, strlen(P)), MC+strlen(P), EXT, EL), rf((char*)a)) oo;
	
	foo[1](o);
	
	while(foo[o]() == ERR);// Wait for user to press a button
	
again:
	S
	int v=2;
	O
	O
	a = bar(o);
	
	if(a == STOP || a == (STOP-0x20))
		goto stop;
	goto again;
stop:	
	foo[3]();
}