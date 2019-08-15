#ifndef DEF_ECHECS_JOUEUR
#define DEF_ECHECS_JOUEUR

#include "../Joueur.hpp"
#include "EchecsPiece.hpp"
#include "EchecsPlateau.hpp"

class EchecsJoueur : Joueur {
 protected:
  EchecsPiece piecesJoueur[16];
 public:
  EchecsJoueur();
  EchecsJoueur(bool pieceBlanche);
  ~EchecsJoueur();
  void affiche();
  virtual bool getIsPieceBlanche()=0;
  void initPositionPieceJoueur(EchecsPlateau &plateauJeuEchecs);
};


class JoueurBlanc : public EchecsJoueur {
  public:
   JoueurBlanc();
   bool getIsPieceBlanche();
};


class JoueurNoir : public EchecsJoueur {
  public:
   JoueurNoir();
   bool getIsPieceBlanche();
};

#endif
