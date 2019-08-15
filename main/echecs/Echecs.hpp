#ifndef DEF_ECHECS
#define DEF_ECHECS

#include "../Partie.hpp"
#include "EchecsPiece.hpp"
#include "EchecsPlateau.hpp"
#include "EchecsJoueur.hpp"
#include <string>

using namespace std;

class Echecs : public Partie {
 protected:
    EchecsPlateau plateauJeuEchecs;
    JoueurBlanc joueurB;
    JoueurNoir joueurN;
    bool joueurCourant;
    int posXJoueurCourant;
    int posYJoueurCourant;
 public:
  Echecs();
  ~Echecs();
  void lancerPartie();
  void verifCasesExistantes();
  int isEchecMat();
};

#endif
