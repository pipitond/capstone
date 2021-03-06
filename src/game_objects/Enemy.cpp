/* ..............................................
  @ file Enemy.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019
  
  
.............................................. */
#include "Enemy.hpp"

/* ..............................................
  CONSTRUCTORS / DESTRUCTORS
  
.............................................. */

Enemy::Enemy() : Player()
{
	setIsMoved(false);
    gettimeofday(&lastTimeMoved, NULL);
    setDamage(2);
}

Enemy::Enemy(int yPos, int xPos) : Player()
{
	setIsMoved(false);
    gettimeofday(&lastTimeMoved, NULL);
    setYPos(yPos);
    setXPos(xPos);
    setDamage(2);
}

Enemy::~Enemy()
{
}

/* ..............................................
  SETTERS
  
.............................................. */

void Enemy::setDamage(int damage)
{
    this->damage = damage;
}

/* ..............................................
  GETTERS
  
.............................................. */

int Enemy::getDamage()
{
    return damage;
}

/* ..............................................
  ACTIONS
  
.............................................. */

unsigned int Enemy::processMove()
{
    struct timeval timeNow;
    gettimeofday(&timeNow, NULL);
    if (((timeNow.tv_sec - lastTimeMoved.tv_sec) > 0) || ((timeNow.tv_usec - lastTimeMoved.tv_usec) > 500000))
    {
        int temp = (rand() % 4);
        if (temp == 0)
        {
            return 'w';
        }
        else if (temp == 1)
        {
            return 's';
        }
        else if (temp == 2)
        {
            return 'a';
        }
        else if (temp == 3)
        {
            return 'd';
        }
    }
    return '?';
}

void Enemy::move(char direction)
{
	if (direction == 'w')
	{
		setYPos(getYPos() - 1);
	}
	else if (direction == 's')
	{
		setYPos(getYPos() + 1);
	}
	else if (direction == 'a')
	{
		setXPos(getXPos() - 1);
	}
	else if (direction == 'd')
	{
		setXPos(getXPos() + 1);
	}
	else
	{
		// fail
	}
	setIsMoved(true);
    gettimeofday(&lastTimeMoved, NULL);
} 