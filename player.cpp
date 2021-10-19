#include "player.h"



player::player(SDL_Rect rect)
{
	rectPlayer = rect;
	 stPlayer = state::idle;
}

player::player(int x, int y, int w, int h)
{
    rectPlayer.x = x;
    rectPlayer.y = y;
    rectPlayer.w = w;
    rectPlayer.h = h;
    stPlayer = state::idle;
}

player::~player()
{

}

SDL_Rect player::rectPosPlayer()
{
	return rectPlayer;
}


state player::etatPlayer()
{
	return stPlayer;
}


void player::setPlayerPoseX(int x)
{
	rectPlayer.x = x;
}

void player::setPlayerPoseY(int y)
{
	rectPlayer.y = y;
}

void player::setPlayerState(state etat)
{
    stPlayer = etat;
}

void player::addPlayerPose()
{
    switch (stPlayer)
    {
    case state::up:
        if (rectPlayer.y - 15 > 30)
        {
            rectPlayer.y -= 15;
        }
        break;
    case state::down:
        if (rectPlayer.y + 15 < 670)
        {
            rectPlayer.y += 15;
        }
        break;
    case state::idle:
        break;
    }
}



