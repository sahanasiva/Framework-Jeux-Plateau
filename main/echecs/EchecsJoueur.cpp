#include <iostream>
#include "EchecsJoueur.hpp"
using namespace std;

EchecsJoueur::EchecsJoueur(): Joueur() {}

EchecsJoueur::~EchecsJoueur() {}

EchecsJoueur::EchecsJoueur(bool pieceBlanche) { //creation joueur blanc ou noir
  int indice = 0;
  int y = pieceBlanche ? 1 : 8;
  for (int x = 1; x <= 8; ++x){
    piecesJoueur[indice++].init(x, y, pieceBlanche);
  }
  y = pieceBlanche ? 2 : 7;
  for (int x = 1; x <= 8; ++x){
    piecesJoueur[indice++].init(x, y, pieceBlanche);
  }
}

void EchecsJoueur::affiche() { //test
  // for (int i=0; i<16; i++){
  //   piecesJoueur[i].affiche();
  // }
}

void EchecsJoueur::initPositionPieceJoueur(EchecsPlateau &plateauJeuEchecs) {
  for (int i=0; i<16; i++)
    plateauJeuEchecs.initPositionPiece(&(piecesJoueur[i]));
}

JoueurBlanc::JoueurBlanc() : EchecsJoueur(true) {}

JoueurNoir::JoueurNoir() : EchecsJoueur(false) {}

bool JoueurBlanc::getIsPieceBlanche() {
  return true;
}

bool JoueurNoir::getIsPieceBlanche() {
  return false;
}
