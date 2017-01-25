
#include <lcd.h>
#include "game.h"

struct struct_GraphicRectangle
{
	unsigned int width;
	unsigned int height;
	unsigned int color;
	unsigned int x, y;

} player1, player2;

struct struct_GraphicCircle
{
    unsigned int radius;
    unsigned int color;
    unsigned int x, y;
    unsigned int x_old, y_old;
} ball;
/*
 
 0,0
    ************
  Y *          *
    *          *
    ************
          X
 */


void initGame(void)
{
    //Koordinatenursprung oben links bei Display und Formen
	player1.height 	= PLAYER_HEIGHT;
	player1.width   = PLAYER_WIDTH;
	player1.x		= PLAYER1_POSX;
	player1.y		= PLAYER1_POSY;
	player1.color  	= PLAYER1_COLOR;

	player2.height 	= PLAYER_HEIGHT;
	player2.width   = PLAYER_WIDTH;
	player2.x		= PLAYER2_POSX;
	player2.y		= PLAYER2_POSY;
	player2.color  	= PLAYER2_COLOR;

    ball.radius     = BALL_RADIUS;
	ball.x			= BALL_POSX;
	ball.y			= BALL_POSY;
	ball.color  	= BALL_COLOR;
}

void DrawShapesRectangle(struct_GraphicRectangle &player)
{
    /*LCD_DrawRectF(LEFT,0,WIDTH,position,GUI_COLOR_BLACK);
    LCD_DrawRectF(LEFT,position,WIDTH,HEIGHT,GUI_COLOR_RED);
    LCD_DrawRectF(LEFT,position + HEIGHT,WIDTH,240,GUI_COLOR_BLACK);*/
    
    LCD_DrawRectF(player1.x,0,player1.width,player1.y,GUI_COLOR_BLACK);
    LCD_DrawRectF(player1.x,player1.y,player1.width,player1.height,player1.color);
    LCD_DrawRectF(player1.x,player1.y + player1.height,player1.width,SCREEN_HEIGHT,GUI_COLOR_BLACK);
    
    LCD_DrawRectF(player2.x,0,player2.width,player2.y,GUI_COLOR_BLACK);
    LCD_DrawRectF(player2.x,player2.y,player2.width,player2.height,player2.color);
    LCD_DrawRectF(player2.x,player2.y + player2.height,player2.width,SCREEN_HEIGHT,GUI_COLOR_BLACK);
}

void DrawShapesCircle(struct_GraphicCircle &ball)
{
    LCD_DrawCircle(ball.x,ball.y,ball.radius,ball.color);
}
