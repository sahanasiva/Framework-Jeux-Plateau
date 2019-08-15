#ifndef DEF_ECHECS_PLATEAU
#define DEF_ECHECS_PLATEAU

#include "../Plateau.hpp"
#include "EchecsPiece.hpp"

class EchecsPlateau : Plateau {
private:
  EchecsPiece* casesPlateauJeuEchecs[64];
public:
  EchecsPlateau();
  EchecsPiece* getPiece(int x, int y);
  bool initPositionPiece(EchecsPiece* p);
  bool changerPositionPiece(EchecsPiece* p, int x, int y);
  EchecsPiece* detruirePiece(int x, int y);
  void affiche();
};

#endif
