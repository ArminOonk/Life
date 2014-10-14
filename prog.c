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
#define G		for(int
#define I 		m[8](&m[5], 7);m[4](B);m[4](T);initscr();getmaxyx(stdscr,h,w);halfdelay(1);start_color();init_pair(1, COLOR_RED, COLOR_WHITE);attron(COLOR_PAIR(1));curs_set(0);
#define M 		memcpy((char*)a
#define O 		m[v--](0,0);
#define P 		V[0]
#define Q 		e[10]
#define S 		p = Y; c = Y; p = Y;
#define Y 		(b*)((int)p ^ (int)c)
#define T 		(char*)X
#define X 		&e[4]

#define a(x,y) 	(y*w + x)
#define b 		bool
#define d(x) 	m[x]();
#define g 		(unsigned)m[5](z, l)
#define h 		e[8]
#define i 		1
#define o 		0
#define oo 		:o
#define r 		return(0);
#define s 		(h*w)
#define t 		true
#define u 		G dy=(x-i); dy<= (x+i); dy++){G dx=(y-i); dx<=(y+i); dx++){
#define w 		e[9]

int (*m[10])();
b *c, *p;
//             |Iteration               End of Iteration| | .life           | e[6]      |e[7] |e[8]   |e[9]   |e[10]|
unsigned e[] = {0x0df12b49, 0x06f513ef, 0x05e6ccff, 0x9c3f, 0xfdfd3e2e, 0xff, 0x0a2e7123, 0x20, 0xdead, 0xbeef,  0x03}; // Game constants

int se(char *c)
{
	char pv = o;
	se:
	if(*c)
	{
		*c += pv;
		pv = *c;
		c++;
		goto se;
	}
	r
}

int gnd(int y, int x)
{
int nrED; (p[a(y, x)]) ? (nrED=-i) : (nrED=0);
	
u int xt = dx;
int yt = dy;

(xt < o*i) ? (xt = w -i) : ((xt >= w ) ? (xt = o) oo);
(yt < o) ? (yt = h-i) : ((yt >= h) ? (yt = i>>i) oo);

p[a(xt, yt)] ? nrED++:o;}}return nrED;
}

int ul(int z, int l)
{
	p[a(z,l)] ? ((!((g-(i<<i))<2))? (c[a(z,l)] = !t) : (c[a(z,l)] = t)) : ((g == Q) ? (c[a(z,l)] = t) : (c[a(z,l)] = !t));
	z++;
	
	(z >= w) ? (z = o,	l++) oo;
	(l < h+i) ?  (m[2](z, l), z=z) oo;
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
		static int n;
		mvprintw(o,o, B, n++);
		refresh();
	}
	else
	{
		q[c] ? D|ED) : D);
		pl(q+i, 2);
	}
	r
}

b rf(char *l)
{
	b z = !t;
	FILE *f = fopen(l, "r");
	if(f == NULL)
	{
		return !t;
	}
	
	b il = t;
	b li = !t;
	
	if ( f != NULL )
	{
		z = t;

		int x = o;
		int y = o;
		int ch;
notEOF:
		ch = m[7]( f );
		
		if(ch == EOF)goto done;
		
		il ? (il = !t, (ch == C) ? li = t oo) oo;
		(ch == '\n') ? ((!li)?y++ oo, x=o, il = t, li = !t) : ((!li)?	(c[a(x,y)] = !(m[6](ch) || ch == ((e[6]>>16)&0xff))), x++oo);
		(x >= w) ? (x = o, y++) oo;
		
		if(y >= h) goto done; goto notEOF;
	}	
	done:
	m[9](f);
	
	return z;
}

int f(int (**j)(), int k)
{
m[k&0xc4] = se;
*j = gnd;
m[k] = fgetc;
m[k+i+i] = fclose;
r
}

int main(int a, char **V)
{	
	m[8] = f;
	m[2*Q] = isspace;
		
	m[o] = getch;
	i[m] = pl;
	m[Q^i] = ul;
	Q[m] = endwin;
	
	I

	c = calloc(s<<i, sizeof(b));// Create a double sized buffer  
	p = c+s;				// Set p to half of the buffer
	b ld = t;
	
	// Initial board
	(a > o+i) ? (ld = !rf(i[V]))oo;
	ld ? (a = (int)calloc( strlen(P) + E + i, i), M, P, strlen(P)), M+strlen(P), X, E), rf((char*)a)) oo;
	
	i[m](o);
	
	while(m[o]() == ERR);// Wait for user to press a button
	
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
	m[((i<<i)+i)]();
}