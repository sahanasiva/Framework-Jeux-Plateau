#include "EchecsPiece.hpp"
#include "EchecsPlateau.hpp"
#include <iostream>
#include <cmath>
using namespace std;

EchecsPiece::EchecsPiece(): Piece() {}

EchecsPiece::EchecsPiece(const EchecsPiece & autre){
  posXPiece = autre.posXPiece;
  posYPiece = autre.posYPiece;
  isPieceBlanche = autre.isPieceBlanche;
}

EchecsPiece & EchecsPiece::operator=(const EchecsPiece & autre) {
  posXPiece = autre.posXPiece;
  posYPiece = autre.posYPiece;
  isPieceBlanche = autre.isPieceBlanche;
  return *this;
}

EchecsPiece::~EchecsPiece(){}

EchecsPiece::EchecsPiece(int x, int y, bool pieceBlanche){
  posXPiece = x;
  posYPiece = y;
  isPieceBlanche = pieceBlanche;
}

void EchecsPiece::init(int x, int y, bool pieceBlanche) {
  posXPiece = x;
  posYPiece = y;
  isPieceBlanche = pieceBlanche;
}

void EchecsPiece::move(int x, int y) {
  posXPiece = x;
  posYPiece = y;
}

bool EchecsPiece::getIsPieceBlanche() {
  return isPieceBlanche;
}

bool EchecsPiece::getIsPieceNoire() {
  return !isPieceBlanche;
}

void EchecsPiece::affiche() {} //test

bool EchecsPiece::mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y) {
  return 0;
}

char EchecsPiece::representationPiece() {
  return (isPieceBlanche)? 'B' : 'N'; //test
}

Roi::Roi(bool pieceBlanche) {
  posXPiece = 5;
  posYPiece = pieceBlanche ? 1 : 8;
  isPieceBlanche = pieceBlanche;
}

bool Roi::mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y) {
        bool mouvementOK = false;
        if ((abs(x - posXPiece) <= 1) && (abs(y - posYPiece) <= 1)) {
            if (plateauJeuEchecs.getPiece(x,y) != NULL) { //test si case destination non vide
                if (plateauJeuEchecs.getPiece(x,y)->getIsPieceBlanche() != isPieceBlanche) {  //Si case avec piece adversaire : manger la piece
                    plateauJeuEchecs.detruirePiece(x,y);
                    mouvementOK = true;
                }
            }
            else {
                mouvementOK = true;
            }
        }
    return mouvementOK;
}

char Roi::representationPiece() {
  return (isPieceBlanche)? 'K' : 'k';
}

Reine::Reine(bool pieceBlanche) : EchecsPiece(4,pieceBlanche?1:8,pieceBlanche), Fou(pieceBlanche,true), Tour(pieceBlanche, true) {}

bool Reine::mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y) {
  bool mouvementOk = false;
  if (Tour::mouvementValide(plateauJeuEchecs,x,y) || Fou::mouvementValide(plateauJeuEchecs,x,y)) {
      mouvementOk = true;
  }
  return (mouvementOk);
}

char Reine::representationPiece() {
  return (isPieceBlanche)? 'R' : 'r';
}

Fou::Fou(bool pieceBlanche, bool pieceGauche) : EchecsPiece(pieceGauche?3:6,pieceBlanche?1:8,pieceBlanche) {}

bool Fou::mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y) {
    int posXDepartPieceJouer = this->getPosXPiece(); //PosX de la Case depart de la piece en jeu
    int posYDepartPieceJouer = this->getPosYPiece(); //PosY de la Case depart de la piece en jeu
    bool estBlanche = this->getIsPieceBlanche();
    bool mouvementOK = false;
    int ecartX = x - posXDepartPieceJouer;
    int ecartY = y - posYDepartPieceJouer;
    //diagonales
    if (ecartX == ecartY || ecartX == -ecartY) {
        if (ecartX > 0 && ecartY < 0) {    //haut-droite
            while (posXDepartPieceJouer != x && posYDepartPieceJouer != y) {
                posYDepartPieceJouer++;
                posYDepartPieceJouer--;
                if (plateauJeuEchecs.getPiece(posYDepartPieceJouer,posYDepartPieceJouer) != NULL) {
                    if (posXDepartPieceJouer == x && posYDepartPieceJouer == y && plateauJeuEchecs.getPiece(x,y)->getIsPieceBlanche() != estBlanche) {
                        plateauJeuEchecs.detruirePiece(x,y);
                        mouvementOK = true;
                    }
                }
                else {
                    if(posXDepartPieceJouer == x && posYDepartPieceJouer == y && mouvementOK == false) {
                        mouvementOK = true;
                    }
                }
            }
        }
        else {
            if (ecartX < 0 && ecartY > 0) {  //bas-gauche
                while (posXDepartPieceJouer != x && posYDepartPieceJouer != y) {
                    posXDepartPieceJouer--;
                    posYDepartPieceJouer++;
                    if (plateauJeuEchecs.getPiece(posYDepartPieceJouer, posYDepartPieceJouer) != NULL) {
                        if (posXDepartPieceJouer == x && posYDepartPieceJouer == y && plateauJeuEchecs.getPiece(x,y)->getIsPieceBlanche() != estBlanche) {
                            plateauJeuEchecs.detruirePiece(x,y);
                            mouvementOK = true;
                        }
                    }
                    else {
                        if(posXDepartPieceJouer == x && posYDepartPieceJouer == y && mouvementOK == false) {
                            mouvementOK = true;
                        }
                    }
                }
            }
            else {
                if(ecartX < 0 || ecartY < 0) {   //haut-gauche
                    while (posXDepartPieceJouer != x || posYDepartPieceJouer != y) {
                        posXDepartPieceJouer--;
                        posYDepartPieceJouer--;
                        if (plateauJeuEchecs.getPiece(posXDepartPieceJouer, posYDepartPieceJouer) != NULL) {
                            if (posXDepartPieceJouer == x && posYDepartPieceJouer == y && plateauJeuEchecs.getPiece(x,y)->getIsPieceBlanche() != estBlanche) {
                                plateauJeuEchecs.detruirePiece(x,y);
                                mouvementOK = true;
                            }
                        }
                        else {
                            if(posXDepartPieceJouer == x && posYDepartPieceJouer == y && mouvementOK == false) {
                                mouvementOK = true;
                            }
                        }
                    }
                }
                else { //bas-droite
                    while (ecartX != x && ecartY != y) {
                        posXDepartPieceJouer++;
                        posYDepartPieceJouer++;
                        if (plateauJeuEchecs.getPiece(posXDepartPieceJouer, posYDepartPieceJouer) != NULL) {
                            if (posXDepartPieceJouer == x && posYDepartPieceJouer == y && plateauJeuEchecs.getPiece(x,y)->getIsPieceBlanche() != estBlanche) {
                                plateauJeuEchecs.detruirePiece(x,y);
                                mouvementOK = true;
                            }
                        }
                        else {
                            if(posXDepartPieceJouer == x && posYDepartPieceJouer == y && mouvementOK == false) {
                                mouvementOK = true;
                            }
                        }
                    }
                }
            }
        }
    }
  return mouvementOK;
}

char Fou::representationPiece() {
  return (isPieceBlanche)? 'F' : 'f';
}

Tour::Tour(bool pieceBlanche, bool pieceGauche) : EchecsPiece(pieceGauche?1:8,pieceBlanche?1:8,pieceBlanche) {}

bool Tour::mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y) {
    bool mouvementOK = false;
    int i = 0;
    if ((x == posXPiece && y>=1 && y <=8) || (y == posYPiece && x>=1 && x<=8)) { //test si piece de l adversaire sur deplacement
        if (posXPiece < x) {   //direction droite
            for (i = posXPiece; i <= x; i++) {
                if (plateauJeuEchecs.getPiece(i,y) != NULL) {
                    if (i == x && plateauJeuEchecs.getPiece(i,y)->getIsPieceBlanche() != isPieceBlanche) {
                        plateauJeuEchecs.detruirePiece(x,y);
                        mouvementOK = true;
                    }
                }
                else {
                    if(i == x && mouvementOK == false) {
                        mouvementOK = true;
                    }
                }
            }
        }
        else {
            if (posXPiece > x) {   //direction gauche
                for (i = posXPiece; i <= x; i--) {
                    if (plateauJeuEchecs.getPiece(i,y) != NULL) {
                        if (i == x && plateauJeuEchecs.getPiece(i,y)->getIsPieceBlanche() != isPieceBlanche) {
                            plateauJeuEchecs.detruirePiece(x,y);
                            mouvementOK = true;
                        }
                    }
                    else {
                        if(i == x && mouvementOK == false) {
                            mouvementOK = true;
                        }
                    }
                }
            }
            else {
                if(posYPiece < y) {   //direction bas
                    for (i = posYPiece; i <= y; i++) {
                        if (plateauJeuEchecs.getPiece(x,i) != NULL) {
                            if (i == y && plateauJeuEchecs.getPiece(x,i)->getIsPieceBlanche() != isPieceBlanche) {
                                plateauJeuEchecs.detruirePiece(x,y);
                                mouvementOK = true;
                            }
                        }
                        else {
                            if(i == y && mouvementOK == false) {
                                mouvementOK = true;
                            }
                        }
                    }
                }
                else {           //direction haut
                    for (i = posYPiece; i <= y; i--) {
                        if (plateauJeuEchecs.getPiece(x,i) != NULL) {
                            if (i == y && plateauJeuEchecs.getPiece(x,i)->getIsPieceBlanche() != isPieceBlanche) {
                                plateauJeuEchecs.detruirePiece(x,y);
                                mouvementOK = true;
                            }
                        }
                        else {
                            if(i == y && mouvementOK == false) {
                                mouvementOK = true;
                            }
                        }
                    }
                }
            }
        }
    }

  return mouvementOK;
}

char Tour::representationPiece() {
  return (isPieceBlanche)? 'T' : 't';
}

Cavalier::Cavalier(bool pieceBlanche, bool pieceGauche) : EchecsPiece(pieceGauche?2:7,pieceBlanche?1:8,pieceBlanche) {}

bool Cavalier::mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y) {
    bool mouvementOK = false;
    if ((abs(x-posXPiece) == 2 && abs(y-posYPiece) == 1) || (abs(x-posXPiece) == 1 && abs(y-posYPiece) == 2)) {
        if (plateauJeuEchecs.getPiece(x, y) != NULL) {
            if (plateauJeuEchecs.getPiece(x, y)->getIsPieceBlanche() != isPieceBlanche) {
                plateauJeuEchecs.detruirePiece(x,y);
                mouvementOK = true;
            }
        }
        else {
                mouvementOK = true;
        }
    }
    return mouvementOK;
}

char Cavalier::representationPiece() {
  return (isPieceBlanche)? 'C' : 'c';
}

Pion::Pion(int x, bool pieceBlanche) : EchecsPiece(x,pieceBlanche?2:7,pieceBlanche) {}

bool Pion::mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y) {
    bool mouvementOK = false;
    if((posYPiece == 2 && isPieceBlanche) || (posYPiece == 7 && !isPieceBlanche)) {
        if ((x == posXPiece && y == posYPiece+2 && isPieceBlanche) || (x == posXPiece && y == posYPiece-2 && !isPieceBlanche)) { //avancer de 2 cases
            if (isPieceBlanche && plateauJeuEchecs.getPiece(posXPiece, posYPiece+1) == NULL && plateauJeuEchecs.getPiece(posXPiece, posYPiece+2) == NULL) {
                mouvementOK = true;
            }
            else {
                if (!isPieceBlanche && plateauJeuEchecs.getPiece(posXPiece, posYPiece-1) == NULL && plateauJeuEchecs.getPiece(posXPiece, posYPiece-2) == NULL) {
                    mouvementOK = true;
                }
            }
        }
        else {
            if ((x == posXPiece && y == posYPiece+1 && isPieceBlanche) || (x == posXPiece && y == posYPiece-1 && !isPieceBlanche)) {   // Avancer de 1 case
                if(plateauJeuEchecs.getPiece(x,y) == NULL) {
                    mouvementOK = true;
                }
            }
            else {
                if((1 == abs(x-posXPiece) && y == posYPiece+1 && isPieceBlanche) || (1 == abs(x-posXPiece) && y == posYPiece-1 && !isPieceBlanche)) {
                    if (plateauJeuEchecs.getPiece(x,y) != NULL && plateauJeuEchecs.getPiece(x, y)->getIsPieceBlanche() != isPieceBlanche) {
                        plateauJeuEchecs.detruirePiece(x,y);
                        mouvementOK = true;
                    }
                }
            }
        }
    }
    else {
        if ((x == posXPiece && y == posYPiece+1 && isPieceBlanche) || (x == posXPiece && y == posYPiece-1 && !isPieceBlanche)) {
                if(plateauJeuEchecs.getPiece(x,y) == NULL) {
                    mouvementOK = true;
                }
            }
            else {
                if((1 == abs(x-posXPiece) && y == posYPiece+1 && isPieceBlanche) || (1 == abs(x-posXPiece) && y == posYPiece-1 && !isPieceBlanche)) {
                    if (plateauJeuEchecs.getPiece(x,y) != NULL && plateauJeuEchecs.getPiece(x, y)->getIsPieceBlanche() != isPieceBlanche) {
                        plateauJeuEchecs.detruirePiece(x,y);
                        mouvementOK = true;
                    }
                }
            }
    }
  return mouvementOK;
}

char Pion::representationPiece() {
  return (isPieceBlanche)? 'P' : 'p';
}
