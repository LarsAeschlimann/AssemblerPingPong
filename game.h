/*
 * game.h
 *
 *  Created on: Dec 21, 2016
 *      Author: Chris
 */

#ifndef GAME_H_
#define GAME_H_

	//Player Einstellungen
	#define PLAYER_HEIGHT	10
	#define PLAYER_WIDTH	10

	#define PLAYER1_POSX	10
	#define PLAYER1_POSY	10
	#define PLAYER1_COLOR	GUI_COLOR_BLUE
	#define PLAYER2_POSX	10
	#define PLAYER2_POSY	10
	#define PLAYER2_COLOR	GUI_COLOR_RED

	//Ball Einstellungen
	#define BALL_HEIGHT		10
	#define	BALL_WIDTH		10
	#define BALL_POSX		10
	#define BALL_POSY		10
	#define BALL_COLOR		GUI_COLOR_YELLOW

	//Prototypen
	void initGame(void);

#endif /* GAME_H_ */
