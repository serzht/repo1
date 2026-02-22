#include <ncurses/ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define CONTROLS 2
#define PLAYERS 2

typedef struct control_buttons
{
	int down;
	int up;
	int left;
	int right;
} control_buttons;

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
	control_buttons *controls;
	int score;
} snake_t;

typedef struct food_t
{
	int x;
	int y;
	time_t put_time;
	char point;
	uint8_t enable;
} food_t;

int play_game = 1;
int sel_color_of_objects[3] = {1, 2, 3};
int autopilot=0;
int level=1;
double delay = 0.2;

static inline int update(snake_t *snake, food_t *food, int32_t *key, int player);
void initTail(tail_t *tail, size_t size);
void initHead(snake_t *snake, int x, int y);
void initSnake(snake_t **snake, size_t size, int x, int y, control_buttons *default_controls);
void go(snake_t *snake);
void goTail(snake_t *snake);
void changeDirection(snake_t *snake, const int32_t key);
int checkDirection(snake_t *snake, const int32_t key);
_Bool isCrush(snake_t *snake);
void initFood(food_t *food, size_t nfood);
void putFood(food_t *food, size_t nfood);
void putFoodSeed(food_t *food);
void refreshFood( food_t *food, size_t nfood);
_Bool haveEat(snake_t *snake, food_t *food);
void addTail(snake_t *snake);
void repairSeed(snake_t *snake, food_t *food, size_t nfood);
void setColor(int color_pair);
void startMenu();
int distance(snake_t *snake, food_t *food);
void autoChangeDirection(snake_t *snake, food_t *food, size_t nfood);
void printLevel(snake_t *snake, int player);
void gameOver(snake_t *snake, int player);

enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=10, FOOD_EXPIRE_SECONDS=90};

int main(int argc, char **argv)
{	
	control_buttons default_controls[PLAYERS][CONTROLS] = {{{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT}, {0, 0, 0, 0}}, {{'S', 'W', 'A', 'D'}, {'s', 'w', 'a', 'd'}}};
	
	initscr();
	keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
	raw();
	noecho();
	curs_set(FALSE);
	
	srand(time(NULL));
	if (!has_colors()){
		endwin();
		printf("Your terminal does not support colors\n");
		return 1;
    }
	
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
	
	startMenu();
	if (!play_game) return 0;
	food_t *food = malloc(MAX_FOOD_SIZE*sizeof(food_t));
	snake_t *snakes[PLAYERS];
	for (int i=0; i < PLAYERS; i++)
		initSnake(&snakes[i], START_TAIL_SIZE, 10+i*5, 10+i*5, default_controls[i]);
	initFood(food, MAX_FOOD_SIZE);
	timeout(0);
	mvprintw(0, 0,"Use Arrows/WASD for control. Press 'F10' for EXIT");
	mvprintw(0, 72, "0 : 0");
	setColor(sel_color_of_objects[0]);
	mvprintw(0, 59, "(Player 1) ");
	setColor(sel_color_of_objects[1]);
	mvprintw(0, 80, "(Player 2)");
	setColor(sel_color_of_objects[2]);
	putFood(food, MAX_FOOD_SIZE);
	int32_t key_pressed=0;
	while (key_pressed != STOP_GAME) {
		for (int i=0; i < PLAYERS; i++){
			setColor(sel_color_of_objects[i]);
			if (update(snakes[i], food, &key_pressed, i)) break;
			if (isCrush(snakes[i])) break;
		}
	}
	for (int i=0; i < PLAYERS; i++){
		free(snakes[i]->tail);
		free(snakes[i]);
	}
	endwin(); 
return 0;
}

static inline int update(snake_t *snake, food_t *food, int32_t *key_pressed, int player)
{
	clock_t begin=clock();
	int c; //с дополнительной переменной змейки почему-то управляются точнее
	while((double)(clock() - begin)/CLOCKS_PER_SEC < delay){
		c = getch(); // Считываем клавишу
		if (c > 0){
			*key_pressed = c;
			break;
		}
	}
	if (autopilot && player) autoChangeDirection(snake, food, MAX_FOOD_SIZE);
	if (*key_pressed > 0 && checkDirection(snake, *key_pressed))
		changeDirection(snake, *key_pressed);
	go(snake);
	goTail(snake);
	if (haveEat(snake, food)){
		printLevel(snake, player);
		if (level == 20){
			gameOver(snake, player);
			*key_pressed = STOP_GAME;
			return 1;
		}
		addTail(snake);
	}
	setColor(sel_color_of_objects[2]);
	refreshFood(food, MAX_FOOD_SIZE);
	repairSeed(snake, food, MAX_FOOD_SIZE);
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

void initHead(snake_t *snake, int x, int y)
{
	snake->x = x;
	snake->y = y;
	snake->direction = RIGHT;
	snake->score = 0;
}

void initSnake(snake_t **snake, size_t size, int x, int y, control_buttons *default_controls)
{
	*snake = (snake_t*)malloc(sizeof(snake_t));
	tail_t *tail = (tail_t*)malloc(MAX_TAIL_SIZE*sizeof(tail_t));
	initTail(tail, MAX_TAIL_SIZE);
	initHead(*snake, x, y);
	(*snake)->tail = tail;
	(*snake)->tsize = size+1;
	(*snake)->controls = default_controls;
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
	if (snake->tail[snake->tsize-1].y)
		mvprintw(snake->tail[snake->tsize-1].y, snake->tail[snake->tsize-1].x," ");
	for(size_t i=snake->tsize-1; i>0; i--){
		snake->tail[i] = snake->tail[i-1];
		if (snake->tail[i].y) mvprintw(snake->tail[i].y, snake->tail[i].x, "%c", ch);
	}
	snake->tail->x = snake->x;
	snake->tail->y = snake->y;
}

void changeDirection(snake_t* snake, const int32_t key)
{
	for (int i=0; i < CONTROLS; i++){
		if (key == snake->controls[i].down)
			{snake->direction = DOWN; break;}
		else if (key == snake->controls[i].up)
			{snake->direction = UP; break;}
		else if (key == snake->controls[i].left)
			{snake->direction = LEFT; break;}
		else if (key == snake->controls[i].right)
			{snake->direction = RIGHT; break;}
	}
}

int checkDirection(snake_t* snake, const int32_t key)
{
	int result=1;
	switch (key)
	{
		case 'S': case 's':
		case KEY_DOWN: result = snake->direction != UP; break;
		case 'W': case 'w':
		case KEY_UP: result = snake->direction != DOWN; break;
		case 'A': case 'a':
		case KEY_LEFT: result = snake->direction != RIGHT; break;
		case 'D': case 'd':
		case KEY_RIGHT: result = snake->direction != LEFT; break;
	}
	return result;
}

_Bool isCrush(snake_t *snake)
{
	for (size_t i=2; i < snake->tsize; i++){
		if (snake->tail[i].x == snake->x && snake->tail[i].y == snake->y){
		/*	double delay1=0.5/snake->tsize;
			clock_t begin;
			timeout(0);
			for (size_t j=0; j < snake->tsize; j++){
				begin=clock();
				while((double)(clock() - begin)/CLOCKS_PER_SEC < delay1);
				getch();
				mvprintw(snake->tail[j].y, snake->tail[j].x, " ");
			}
		*/	return 0;
		}
	}
	return 0;
}

void initFood(food_t *food, size_t nfood)
{
	food_t init = {0,0,0,0,0};
	for(size_t i=0; i < nfood; i++)
		food[i] = init;
}

/*  Разместить еду на поле  */
void putFood(food_t *food, size_t nfood)
{
	for (size_t i=0; i < nfood; i++)
		putFoodSeed(&food[i]);
}

/*  Обновить/разместить текущее зерно на поле  */
void putFoodSeed(food_t *food)
{
	int max_x=0, max_y=0;
	getmaxyx(stdscr, max_y, max_x);
	food->x = rand() % (max_x - 1);
	food->y = rand() % (max_y - 2) + 1; //Не занимаем верхнюю строку
	food->put_time = time(NULL);	//Устанавливаем текущее время
	max_x = rand() % 100;
	if (max_x < 91)
		food->point = '$';
	else if (max_x < 97)
		food->point = '&';
	else
		food->point = '#';
	food->enable = 1;
	mvprintw(food->y, food->x, "%c", food->point);
}

/* Обновление еды */
void refreshFood( food_t *food, size_t nfood)
{
	for (size_t i=0; i < nfood; i++){
		if (food[i].put_time){
			if(!food[i].enable)
				putFoodSeed(&food[i]);
			else if ((time(NULL) - food[i].put_time) > FOOD_EXPIRE_SECONDS){
				mvprintw(food[i].y, food[i].x, " ");
				putFoodSeed(&food[i]);
			}
		}
	}
}
/* Съесть зерно */
_Bool haveEat(snake_t *snake, food_t *food)
{
	for (int i=0; i < MAX_FOOD_SIZE; i++){
		if (food[i].enable && snake->x == food[i].x && snake->y == food[i].y){
			food[i].enable = 0;
			if (food[i].point == '$')
				snake->score += 10;
			else if (food[i].point == '&')
				snake->score += 30;
			else
				snake->score += 100;
			return 1;
		}
	}
	return 0;
}

void addTail(snake_t *snake)
{
	if (snake->tsize < MAX_TAIL_SIZE)
		snake->tsize++;
}

void repairSeed(snake_t *snake, food_t *food, size_t nfood)
{
	for (size_t i=0; i < snake->tsize; i++)
		for (size_t j=0; j < nfood; j++){
			if (food[j].enable && snake->tail[i].x == food[j].x && snake->tail[i].y == food[j].y){
				food[j].enable=0;
			}
		}
	for (size_t i=0; i < nfood-1; i++)
		for (size_t j=i+1; j < nfood; j++)
			if (food[i].enable && food[j].enable && food[i].x == food[j].x && food[i].y == food[j].y)
				food[j].enable=0;
}

void setColor(int color_pair)
{
	attroff(COLOR_PAIR(1));
	attroff(COLOR_PAIR(2));
	attroff(COLOR_PAIR(3));
	attroff(COLOR_PAIR(4));
	attroff(COLOR_PAIR(5));
	attroff(COLOR_PAIR(6));
	attroff(COLOR_PAIR(7));
	switch (color_pair){
		case 1:	attron(COLOR_PAIR(1)); break;	// snake1 default
		case 2:	attron(COLOR_PAIR(2)); break;	// snake2 default
		case 3:	attron(COLOR_PAIR(3)); break;	// food default
		case 4: attron(COLOR_PAIR(4)); break;
		case 5: attron(COLOR_PAIR(5)); break;
		case 6: attron(COLOR_PAIR(6)); break;
		case 7:	attron(COLOR_PAIR(7)); break;
	}
}

void startMenu()
{
	int num_objects = 3;
	char *object_names[3] = {"Snake 1", "Snake 2", "Food"};
	int sel_object = 0;
	int num_colors = 7;
	char *color_names[7] = {"Red", "Blue", "Green", "Yellow", "Magenta", "Cyan", "White"};
	int num_option = 3;
	char *option_names[3] = {"Start Game", "Player vs Autopilot", "Exit"};
	int sel_option = 0;
	int32_t key_pressed=0;
	clear();
	attron(A_BOLD);
	mvprintw(2, 10, "=== DOUBLE SNAKE GAME ===");
	attroff(A_BOLD);
	mvprintw(4, 7, "Welcome to 'Double Snake' game!");
	while(1)
	{	//Выбор цвета для змеек и еды
		mvprintw(6, 5, "Select color for snakes and food:");
		for (int i=0; i < num_objects; i++){
			if (sel_object == i) {
				for (int j=0; j < num_colors; j++){
					if (sel_color_of_objects[i] == (j+1)) attron(A_REVERSE);
					setColor(j+1);
					mvprintw(10, 5 + j*12, "[%s]", color_names[j]);
					attroff(A_REVERSE);
				}
				attron(A_REVERSE);
			}
			mvprintw(8, 5 + i*20, "%s", object_names[i]);
			attroff(A_REVERSE);
		}
		// Current control settings
		mvprintw(12, 5, "Game controls:");
		mvprintw(13, 8, "Snake 1: Arrow keys");
		mvprintw(14, 8, "Snake 2: WASD keys");
		
		// Menu options
		mvprintw(16, 5, "Options:");
		for (int i=0; i < num_option; i++){
			if (sel_option == i) attron(A_REVERSE);
			mvprintw(18 + i, 8, "%s", option_names[i]);
			attroff(A_REVERSE);
		}
        // Menu control instructions
        mvprintw(26, 5, "Menu controls:");
        mvprintw(27, 8, "Arrow keys - navigation, ENTER - select, TAB - switch snakes and food");
        
		key_pressed = getch();
		switch (key_pressed)
		{
			case '\t':
				sel_object = (sel_object + 1) % num_objects;
				break;
			case KEY_RIGHT:
				sel_color_of_objects[sel_object] = sel_color_of_objects[sel_object] % num_colors + 1;
				break;
			case KEY_LEFT:
				sel_color_of_objects[sel_object] = (sel_color_of_objects[sel_object] - 2 + num_colors) % num_colors + 1;
				break;
			case KEY_UP:
				sel_option = (sel_option - 1 + num_option) % num_option;
				break;
			case KEY_DOWN:
				sel_option = (sel_option + 1) % num_option;
				break;
			case '\n':
				if (sel_option < 2){
					clear();
					autopilot = sel_option ? 1: 0;
					return;
				}
			case STOP_GAME:
				play_game = 0;
				return;
		}
	}
}

int distance(snake_t *snake, food_t *food)
{
	return (abs(snake->x - food->x) + abs(snake->y - food->y));
}

void autoChangeDirection(snake_t *snake, food_t *food, size_t nfood)
{
	int pointer = 0;
	for (size_t i = 0; i < nfood; i++) {   // ищем ближайшую еду
		pointer = (distance(snake, &food[i]) < distance(snake, &food[pointer])) ? i : pointer;
	}
	if ((snake->direction == RIGHT || snake->direction == LEFT) && (snake->y != food[pointer].y)) {  // горизонтальное движение
		snake->direction = (food[pointer].y > snake->y) ? DOWN : UP;
	}
	else if ((snake->direction == DOWN || snake->direction == UP) && (snake->x != food[pointer].x)) {  // вертикальное движение
		snake->direction = (food[pointer].x > snake->x) ? RIGHT : LEFT;
	}
}

void printLevel(snake_t *snake, int player)
{
	int max_x = getmaxx(stdscr);
	setColor(0);
	if (player)
		mvprintw(0, 76, "%-5d", snake->score);
	else
		mvprintw(0, 68, "%5d", snake->score);
	if (snake->score >= level*200){
		if (level < 19) delay -= 0.01;
		level++;
	}
	mvprintw(0, max_x - 10, "LEVEL: %-2d", level);
}

void gameOver(snake_t *snake, int player)
{
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	clear();
	attron(A_BOLD);
	if ((autopilot && !player) || !autopilot) {
		mvprintw(max_y/2-3, max_x/2-5, "PLAYER %d WIN!!!", player + 1);
		mvprintw(max_y/2-2, max_x/2-13, "Your score: %d, your level - %d", snake->score, level);
		mvprintw(max_y/2-1, max_x/2-12, "C O N G R A T U L A T I O N S !");
	}
	else {
		mvprintw(max_y/2-2, max_x/2-5, "Player 1 lost.");
		mvprintw(max_y/2-1, max_x/2-8, "Good luck next time!");
	}
	timeout(100000);
	getch();
	clear();
	mvprintw(max_y/2-2, max_x/2-7, "GAME OVER");
	getch();
}
