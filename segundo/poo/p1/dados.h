//dados.h
//this file is the declaration of de class Dados.
//we set de private and public data.
//the class represent 2 dices


class Dados{
  private:
      int d1_;
      int d2_;

  public:
    Dados();                    //this is the constructor
    int getDado1();             //return a number
    int getDado2();             //return a number
    void lanzamiento();         //return the value of the dice
    bool setDado1(int num);     //set a value in the dice 1
    bool setDado2(int num);     //set a value in the dice 2
    int getSuma();              //return the add of the dice 1 and 2
    int getDiferencia();        //return the diference of both dice 
};
