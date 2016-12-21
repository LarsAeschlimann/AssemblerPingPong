
#include <lcd.h>
#include "game.h"

struct struct_GraphicItem
{
	unsigned char form;
	unsigned int width;
	unsigned int height;
	unsigned int color;
	unsigned int x, y;

} player1, player2, ball;

enum FORM {FORM_RECTANGLE, FORM_CIRCLE};


void initGame(void)
{
	player1.form   	= FORM_RECTANGLE;
	player1.height 	= PLAYER_HEIGHT;
	player1.width   = PLAYER_WIDTH;
	player1.x		= PLAYER1_POSX;
	player1.y		= PLAYER1_POSY;
	player1.color  	= PLAYER1_COLOR;

	player2.form   	= FORM_RECTANGLE;
	player2.height 	= PLAYER_HEIGHT;
	player2.width   = PLAYER_WIDTH;
	player2.x		= PLAYER2_POSX;
	player2.y		= PLAYER2_POSY;
	player2.color  	= PLAYER2_COLOR;

	ball.form   	= FORM_CIRCLE;
	ball.height 	= BALL_HEIGHT;
	ball.width   	= BALL_WIDTH;
	ball.x			= BALL_POSX;
	ball.y			= BALL_POSY;
	ball.color  	= BALL_COLOR;
}
