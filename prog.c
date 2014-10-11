#include <ncurses.h>			// ncurses.h includes stdio.h
#include <string.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define getIndex(x,y) y*width + x
#define born(x,y) (getNrAlive(x, y) == 3)
#define dies(x,y) (!(((unsigned int)getNrAlive(x, y)-2)<2))

int getNrAlive(int x, int y);
bool readFile(char *filename);

void updateLife();
void printLife(int it);

int height, width, size;	// to store the number of heights and the number of widthums of the screen
bool *buffer1, *buffer2;
bool *current, *previous;

int main(int argc, char **argv)
{
	for(int i=0; i<9; i++)
	{
		bool org = (i < 2) || (i > 3);
		bool new = !(((unsigned int)i-2)<2);
		
		printf("i: %s %s\n", org ? "true":"false", new ? "true":"false");
	}
	
	initscr();						// start the curses mode
	getmaxyx(stdscr,height,width);	// get the number of heights and widthumns
	halfdelay(1);					// Set timeout on getch()
	
	start_color();					// Start color
	init_pair(1, COLOR_RED, COLOR_WHITE);	// Create pair
	attron(COLOR_PAIR(1));					// Set pair
		
	curs_set(0);							// Disable the cursor
	
	size = height*width;
		
	bool *buffer1 = calloc(size, sizeof(bool));
	bool *buffer2 = calloc(size, sizeof(bool));
	
	current = buffer1;
	previous = buffer2;
	
	bool loadDemo = true;
	
	// Initial board
	if(argc > 1)
	{
		loadDemo = !readFile(argv[1]);
	}
	
	if(loadDemo)
	{
		readFile("demo.life");
	}
	
	int iteration = 0;
	printLife(iteration++);
	
	while(getch() == ERR)
		;// Wait for user to press a button
	
	while(true)
	{
		// Switch buffer
		bool *temp = previous;
		previous = current;
		current = temp;
		
		updateLife();
		printLife(iteration);
		iteration++;
		
		int ch = getch();
		if(ch == 'q' || ch == 'Q')
		{
			break;
		}
	}
	
	endwin();

	free(buffer1);
	free(buffer2);
}

int getNrAlive(int x, int y)
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

void updateLife()
{
	for(int y=0; y<height ; y++)
	{
		for(int x=0; x<width; x++)
		{
			int index = getIndex(x,y);
			if(previous[index])
			{
				//Are we going to die?
				if(dies(x, y))
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
				if(born(x, y))
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

void printLife(int it)
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

bool readFile(char *filename)
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