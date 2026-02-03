#include <ncurses/ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct control_buttons
{
	int down;
	int up;
	int left;
	int right;
} control_buttons;

control_buttons default_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};

typedef struct tail_t {
    int x;
    int y;
} tail_t;

typedef struct snake_t {
	int x;
    int y;
    int direction;
    size_t tsize;
    tail_t *tail;
    control_buttons controls;
} snake_t ;

void initTail(tail_t *tail, size_t size);
void initHead(snake_t *snake, int x, int y);
void initSnake(snake_t *snake, size_t size, int x, int y);
void go(snake_t *snake);
void goTail(snake_t *snake);
void changeDirection(snake_t *snake, const int32_t key);
int detectSelfTouch(snake_t *snake);

enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME='q'};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3};

int main(int argc, char **argv)
{
	double delay = 0.2;
	clock_t begin;
	snake_t *snake = (snake_t*)malloc(sizeof(snake_t));
	initSnake(snake, START_TAIL_SIZE, 10, 10);
	initscr();
	keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
	raw();
	noecho();
	curs_set(FALSE);
	mvprintw(0, 1,"Use arrows for control. Press 'q' for EXIT");
	timeout(0);
	int key_pressed=0;
	while (key_pressed != STOP_GAME) {
		begin = clock(); 
		while((double)(clock() - begin)/CLOCKS_PER_SEC < delay){
			key_pressed = getch(); // Считываем клавишу
			if (key_pressed > 0) break;
		}
		changeDirection(snake, key_pressed);
		goTail(snake);
		go(snake);
		if (detectSelfTouch(snake)) break;
	}
	free(snake->tail);
	free(snake);
	endwin(); 
return 0;
}

void initTail(tail_t *tail, size_t size)
{
	for(size_t i=0; i<size; i++)
	{
		(tail+i)->x=0;
		(tail+i)->y=0;
	}
}

void initHead(snake_t *snake,int x,int y)
{
	snake->x = x;
	snake->y = y;
	snake->direction = RIGHT;
}

void initSnake(snake_t *snake, size_t size, int x, int y)
{
	tail_t *tail = (tail_t*)malloc(MAX_TAIL_SIZE*sizeof(tail_t));
	initTail(tail, MAX_TAIL_SIZE);
	initHead(snake, x, y);
	snake->tail = tail;
	snake->tsize = size+10;
	snake->controls = default_controls;
}

void go(snake_t *snake) 
{
    char ch = '@';
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x);
    switch (snake->direction)
    {
        case LEFT:
			if (snake->x == 0) snake->x = max_x;
            mvprintw(snake->y, --(snake->x), "%c", ch);
			break;
        case RIGHT:
			if (snake->x == max_x-1) snake->x = -1;
            mvprintw(snake->y, ++(snake->x), "%c", ch);
			break;
        case UP:
			if (snake->y == 1) snake->y = max_y;
            mvprintw(--(snake->y), snake->x, "%c", ch);
			break;
        case DOWN:
			if (snake->y == max_y-1) snake->y = 0;
            mvprintw(++(snake->y), snake->x, "%c", ch);
			break;
    }
}

void goTail(snake_t *snake)
{
	char ch = '*';
    mvprintw(snake->tail[snake->tsize-1].y, snake->tail[snake->tsize-1].x," ");
	for(size_t i = snake->tsize-1; i>0; i--)
        snake->tail[i] = snake->tail[i-1];
    snake->tail->x = snake->x;
    snake->tail->y = snake->y;
    mvprintw(snake->tail->y, snake->tail->x, "%c", ch);
}

void changeDirection(snake_t* snake, const int32_t key)
{
	
	if (key == snake->controls.down && snake->direction != UP)
		snake->direction = DOWN;
	else if (key == snake->controls.up && snake->direction != DOWN)
		snake->direction = UP;
	else if (key == snake->controls.left && snake->direction != RIGHT)
		snake->direction = LEFT;
	else if (key == snake->controls.right && snake->direction != LEFT)
		snake->direction = RIGHT;
}

int detectSelfTouch(snake_t *snake)
{
	for (size_t i=3; i < snake->tsize; i++){
		if (snake->tail[i].x == snake->x && snake->tail[i].y == snake->y){
			for (size_t j=0; j < snake->tsize; j++){
				getch();
				timeout(25);
				mvprintw(snake->tail[j].y, snake->tail[j].x, " ");
			}
			return 1;
		}
	}
	return 0;
}
