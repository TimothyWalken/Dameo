#include "pile.h"
class plateau
{
public:
	int l;
	pion ***tab;
	plateau();
	void affichage();
	~plateau();
	void deplacement(color);
	void move(int,int,color);
	void mup(int,int,color);
	void mdown(int,int,color);
	void mleft(int,int,color);
	void mright(int,int,color);
	bool isfree(int, int);
	bool isanenemy(int,int,color);
	void eat(int,int);
	void place(int,int,color);
	void mdiagod(int,int,color);
	void mdiagog(int,int,color);
	void partie();
	bool noeat(int,int,color);
	bool win();
	void beginia(color col);
	void initmoveia(int,int,color);
	pile* eatia(int,int,color,pile*);
	void lectureia(pile*);
	void jouer(color);
	int eval(plateau*, int, color);
	int evalb(plateau*, int, color);
	int evaln(plateau*, int, color);
	int min(int,plateau*,color);
	int max(int,plateau*,color);
	bool upeat(int, int , color);
	bool downeat(int, int , color);
	bool lefteat(int, int , color);
	bool righteat(int, int , color);
	bool poss(int, int, pile*);
	pile* maxia(pile*, pile*, pile*,pile*);
	plateau* copie(plateau*);
	int lecture(plateau*,color);
	void mdownia(int,int,color);
	void mupia(int,int,color);
};
