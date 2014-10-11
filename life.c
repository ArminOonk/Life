#include <ncurses.h>			// ncurses.h includes stdio.h
#include <string.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int getIndex(int x, int y);
int getNrAlive(bool *previous, int x, int y);
bool dies(bool *previous, int x, int y);
bool born(bool *previous, int x, int y);
void updateLife(bool *previous, bool *current);
void printLife(bool *current, int it);

int height, width, size;	// to store the number of heights and the number of widthums of the screen
bool *buffer1, *buffer2;

bool readFile(bool *current, char *filename)
{
	bool retVal = false;
	FILE *readFP = fopen(filename, "r");
	bool startOfLine = true;
	bool skipLine = false;
	
	if ( readFP != NULL )
	{
		retVal = true;

		int x = 0;
		int y = 0;
		int ch;
		while  ((ch = fgetc( readFP ) ) != EOF )
		{
			if(startOfLine)
			{
				startOfLine = false;
				if(ch == '!')
				{
					skipLine = true;
				}
			}
			
			if(ch == '\n')
			{
				y++;
				x=0;
				startOfLine = true;
				skipLine = false;
			}
			else if(!skipLine)
			{
				current[getIndex(x,y)] = !(isspace(ch) || ch == '.'); // Make it alive when not space
				x++;
			}
			
			if(x >= width)
			{
				x = 0;
				y++;
			}
			
			if(y >= height)
			{
				break;
			}
		}
	}	
	fclose(readFP);
	
	return retVal;
}


int main(int argc, char **argv)
{
	initscr();						// start the curses mode
	getmaxyx(stdscr,height,width);	// get the number of heights and widthumns
	halfdelay(1);					// Set timeout on getch()
	
	start_color();					// Start color
	init_pair(1, COLOR_RED, COLOR_WHITE);	// Create pair
	attron(COLOR_PAIR(1));					// Set pair
		
	curs_set(0);							// Disable the cursor
	
	size = height*width;
	
	//printf("Dimension: heights %d widths %d Size: %d\n", height, width, size);
	
	bool *buffer1 = calloc(size, sizeof(bool));
	bool *buffer2 = calloc(size, sizeof(bool));
	
	bool *current = buffer1;
	bool *previous = buffer2;
	
	bool loadDemo = true;
	
	// Initial board
	if(argc > 1)
	{
		loadDemo = !readFile(current, argv[1]);
	}
	
	if(loadDemo)
	{
		readFile(current, "demo.life");
	}
	
	int iteration = 0;
	printLife(current, iteration++);
	
	while(getch() == ERR)
		;// Wait for user to press a button
	
	while(getch() != 'q')
	{
		// Switch buffer
		bool *temp = previous;
		previous = current;
		current = temp;
		
		updateLife(previous, current);
		printLife(current, iteration);
		iteration++;
	}
	
	endwin();

	free(buffer1);
	free(buffer2);
}

int getIndex(int x, int y)
{
	return y*width + x;
} 

int getNrAlive(bool *previous, int x, int y)
{
	int nrAlive = 0;
	for(int dy=(y-1); dy<= (y+1); dy++)
	{
		for(int dx=(x-1); dx<=(x+1); dx++)
		{
			if(dx == x && dy == y)
			{
				continue;
			}
			
			int xt = dx;
			int yt = dy;

			if(xt < 0)
			{
				xt = width-1;
			}
			else if(xt >= width)
			{
				xt = 0;
			}

			if(yt < 0)
			{
				yt = height-1;
			}
			else if(yt >= height)
			{
				yt = 0;
			}

			if(previous[getIndex(xt, yt)])
			{
				nrAlive++;
			}
		}
	}
	return nrAlive;
}

bool dies(bool *previous, int x, int y)
{
	int nrAlive = getNrAlive(previous, x, y);
	return (nrAlive < 2) || (nrAlive > 3);
}

bool born(bool *previous, int x, int y)
{
	int nrAlive = getNrAlive(previous, x, y);
	return (nrAlive == 3);
}

void updateLife(bool *previous, bool *current)
{
	for(int y=0; y<height ; y++)
	{
		for(int x=0; x<width; x++)
		{
			int index = getIndex(x,y);
			if(previous[index])
			{
				//Are we going to die?
				if(dies(previous,  x, y))
				{
					current[index] = false; // We died
				}
				else
				{
					current[index] = true; // Alive
				}
			}
			else
			{
				if(born(previous, x, y))
				{
					current[index] = true; // Alive
				}
				else
				{
					current[index] = false; // We died
				}
			}
		}
	}
}

void printLife(bool *current, int it)
{
	move(0,0);
	for(int i=0; i<size; i++)
	{
		if(current[i])
		{
			addch('*');
		}
		else
		{
			addch(' ');
		}
	}
	mvprintw(0,0,"Iteration: %d", it);
	refresh();
}