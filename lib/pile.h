#ifndef PILE_H
#define PILE_H
class coor
{
  public:
    int x;
    int y;
    color col;
    coor* suiv;// regarder si la tete ou la queue est plus interessant
    coor(int a, int b, color c);
    ~coor();
};

class pile
{
  public:
    int n;
    coor* tete;
    coor* fin;
    coor* debut;
    pile();
    ~pile();
    void insercoo(int,int, color);
};
#endif