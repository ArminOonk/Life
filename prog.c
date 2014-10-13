#include <ncurses.h>			// ncurses.h includes stdio.h
#include <string.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define B 		(char *)e
#define C 		((e[6]&0xff))
#define D 		addch(DEAD
#define DEAD 	e[7]
#define E 		strlen(T)
#define ED 		((e[6]>>24)&0xff)
#define F  		((e[6]>>8)&0xff)
#define I 		foo[4](B);foo[4](T);initscr();getmaxyx(stdscr,h,w);halfdelay(1);start_color();init_pair(1, COLOR_RED, COLOR_WHITE);attron(COLOR_PAIR(1));curs_set(0);
#define M 		memcpy((char*)a
#define O 		foo[v--](0,0);
#define P 		V[0]
#define S 		p = Y; c = Y; p = Y;
#define Y 		(b*)((int)p ^ (int)c)
#define T 		(char*)X
#define X 		&e[4]

#define a(x,y) 	(y*w + x)
#define b 		bool
#define d(x) 	foo[x]();
#define g 		(unsigned)foo[5](x, y)
#define h 		e[8]
#define i 		1
#define o 		0
#define oo 		:o
#define r 		return(0);
#define s 		(h*w)
#define t 		true
#define w 		e[9]

int (*foo[10])();
b *c, *p;
//                   |Iteration               End of Iteration|  | .life         | e[6]     |e[7]|e[8]  |e[9]  |e[10]|
unsigned int e[] = {0x0df12b49, 0x06f513ef, 0x05e6ccff, 0x9c3f, 0xfdfd3e2e, 0xff, 0x0a2e7121, 0x20, 0xdead, 0xbeef,  0x03}; // Game constants

int se(char *c)
{
	char pv = o;
	se:
	if(*c)	// Only do something when we are not at the end
	{
		*c += pv;
		pv = *c;
		c++;
		goto se;
	}
	r
}

int gnd(int x, int y)
{
	int nrED; (p[a(x, y)]) ? (nrED=-i) : (nrED=0);
	
	for(int dy=(y-i); dy<= (y+i); dy++)
	{
		for(int dx=(x-i); dx<=(x+i); dx++)
		{			
			int xt = dx;
			int yt = dy;

			(xt < o*i) ? (xt = w -i) : ((xt >= w ) ? (xt = o) oo);
			(yt < o) ? (yt = h-i) : ((yt >= h) ? (yt = i>>i) oo);

			p[a(xt, yt)] ? nrED++:o;
		}
	}
	return nrED;
}

int ul(int x, int y)
{
	p[a(x,y)] ? ((!((g-(i<<i))<2))? (c[a(x,y)] = !t) : (c[a(x,y)] = t)) : ((g == e[10]) ? (c[a(x,y)] = t) : (c[a(x,y)] = !t));
	x++;
	
	(x >= w) ? (x = o,	y++) oo;
	(y < h+i) ?  (foo[2](x, y), x=x) oo;
	r
}

int pl(int q, int j)
{
	if(q == o)
	{
		move(o,o);
	}
	
	if (q >= s)
	{
		static int iteration;
		mvprintw(o,o, B, iteration++);
		refresh();
	}
	else
	{
		q[c] ? D|ED) : D);
		pl(q+i, 2);
	}
	r
}

b rf(char *filename)
{
	b retVal = !t;
	FILE *f = fopen(filename, "r");
	if(f == NULL)
	{
		return !t;
	}
	
	b il = t;
	b li = !t;
	
	if ( f != NULL )
	{
		retVal = t;

		int x = o;
		int y = o;
		int ch;
notEOF:
		ch = fgetc( f );
		
		if(ch == EOF)goto done;
		
		il ? (il = !t, (ch == C) ? li = t oo) oo;
		(ch == '\n') ? (y++, x=o, il = t, li = !t) : ((!li)?	(c[a(x,y)] = !(isspace(ch) || ch == ((e[6]>>16)&0xff))), x++oo);
		(x >= w) ? (x = o, y++) oo;
		
		if(y >= h) goto done; goto notEOF;
	}	
	done:
	fclose(f);
	
	return retVal;
}

int main(int a, char **V)
{		
	foo[o] = getch;
	i[foo] = pl;
	foo[2] = ul;
	foo[3] = endwin;
	foo[4] = se;
	foo[5] = gnd;
	
	I

	c = calloc(s<<i, sizeof(b));// Create a double sized buffer  
	p = c+s;				// Set p to half of the buffer
	b ld = t;
	
	// Initial board
	(a > o+i) ? (ld = !rf(i[V]))oo;
	ld ? (a = (int)calloc( strlen(P) + E + i, i), M, P, strlen(P)), M+strlen(P), X, E), rf((char*)a)) oo;
	
	i[foo](o);
	
	while(foo[o]() == ERR);// Wait for user to press a button
	
again:
	S
	int v=i+o+i;
	O
	O
	a = d(o);
	
	if(a == F || a == (F-DEAD))
		goto stop;
	goto again;
stop:	
	foo[((i<<i)+i)]();
}