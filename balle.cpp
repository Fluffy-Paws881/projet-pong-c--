#include "balle.h"

balle::balle(int x, int y, int w, int h, int vx, int vy)
{
	rectBalle.x = x;
	rectBalle.y = y;
	rectBalle.w = w;
	rectBalle.h = h;
	vX = vx;
	vY = vy;
	paddleCenter = 0;
	d = 0;
}

balle::~balle()
{
}

SDL_Rect balle::getRectBalle()
{
	return rectBalle;
}

void balle::setRectBalle(int x, int y, int w, int h)
{
	rectBalle.x = x;
	rectBalle.y = y;
	rectBalle.w = w;
	rectBalle.h = h;
}

void balle::deplacementBalle(int h)
{
	if ((rectBalle.y + vY < 30) || (rectBalle.y + vY > h - 30))
	{
		vY *= -1;
		vY += 1;
	}
	else {
		rectBalle.y += vY;
	}
	rectBalle.x += vX;
}

void balle::rebondPlayer(player p1, player p2)
{
	//calcul permetant le rebond de la balle pour le joueur 1
	if ((rectBalle.x >= p1.rectPosPlayer().x) && (rectBalle.x <= p1.rectPosPlayer().x + p1.rectPosPlayer().w) && (rectBalle.y >= p1.rectPosPlayer().y) && (rectBalle.y <= p1.rectPosPlayer().y + p1.rectPosPlayer().h))
	{
		paddleCenter = p1.rectPosPlayer().y + (p1.rectPosPlayer().h / 2);
		d = paddleCenter - rectBalle.y;
		vY += d * -0.1;
		vX *= -1;
	}
	//calcul permetant le rebond de la balle pour le joueur 2
	if ((rectBalle.x >= p2.rectPosPlayer().x) && (rectBalle.x <= p2.rectPosPlayer().x + p2.rectPosPlayer().w) && (rectBalle.y >= p2.rectPosPlayer().y) && (rectBalle.y <= p2.rectPosPlayer().y + p2.rectPosPlayer().h))
	{
		paddleCenter = p2.rectPosPlayer().y + (p2.rectPosPlayer().h / 2);
		d = paddleCenter - rectBalle.y;
		vY += d * -0.1;
		vX *= -1;
	}
}

void balle::rebondMural(int h)
{
	if ((rectBalle.y < 30) || (rectBalle.y > h - 30))
	{
		vY *= -1;
	}
}

void balle::verifMarquagePoint(player* p1, player* p2, score* scr, int h, int w)
{
	if (rectBalle.x < 0)
	{
		scr->addScoreP2();
		vX = 15;
		vY = 0;
		rectBalle.y = h / 2;
		rectBalle.x = 35;
		p1->setPlayerPoseY(320);
		p1->setPlayerPoseX(0);

		p2->setPlayerPoseY(320);
		p2->setPlayerPoseX(w - 20);
	}
	else if (rectBalle.x > w) {
		scr->addScoreP1();
		vX = -15;
		vY = 0;
		rectBalle.x = w - 35;
		rectBalle.y = h / 2;
		p1->setPlayerPoseY(320);
		p1->setPlayerPoseX(0);

		p2->setPlayerPoseY(320);
		p2->setPlayerPoseX(w - 20);
	}
}
