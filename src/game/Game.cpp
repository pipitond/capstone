/* ..............................................
  @file Game.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
.............................................. */
#include "Game.h"

/* ..............................................
  CONSTRUCTORS / DESTRUCTORS
  
.............................................. */

Game::Game()
{
  /* initialize ncurses */
  setlocale(LC_ALL, "");
  initscr();
  cbreak();
  noecho();
  nonl();
  intrflush(stdscr, FALSE);
  keypad(stdscr, TRUE);
  curs_set(0);

  /* initialize windows */
  this->statusWindow = newwin(5, 150, 0, 0);
  this->worldWindow = newwin(30, 150, 5, 0);
  this->narrativeWindow = newwin(5, 150, 35, 0);
  refresh();

  /* initialize colors */
  start_color();
  init_pair(GRASS_PAIR, COLOR_YELLOW, COLOR_GREEN);
  init_pair(PLAYER_PAIR, COLOR_BLACK, COLOR_GREEN);
  init_pair(MENU_PAIR, COLOR_BLACK, COLOR_BLUE);

  /* clear the screen */
  clear();

  /* initialize player object */
  this->player.setXPos(2);
  this->player.setYPos(2);

  /* initialize spaces */

}

Game::~Game()
{
  /* Destroy ncurses */
  endwin();

  /* Destroy player */
  player.~Player();
}

/* ..............................................
  ACTIONS
  
.............................................. */

void Game::run()
{
  do
  {
    render();  // render the game state
    process(); // process player input
    update();  // update the game state
  } while (getIsComplete() != true);
}