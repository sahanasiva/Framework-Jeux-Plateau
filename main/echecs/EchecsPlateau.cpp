#include <iostream>
#include "EchecsPlateau.hpp"
#include "EchecsPiece.hpp"
using namespace std;

EchecsPlateau::EchecsPlateau() { //init Plateau vide
    for(int i=0; i<64; i++){
        casesPlateauJeuEchecs[i] = NULL;
    }
}

EchecsPiece* EchecsPlateau::getPiece(int x, int y) {
    if ((x>=1) && (x<=8) && (y>=1) && (y<=8))
        return casesPlateauJeuEchecs[(x-1)+8*(y-1)];
    return NULL;
}

bool EchecsPlateau::initPositionPiece(EchecsPiece* p) { // init position Piece en debut de partie
    if(p==NULL) return false;
    int position = (p->getPosXPiece()-1)+8*(p->getPosYPiece()-1);
    if((p->getPosXPiece()>=1) && (p->getPosXPiece()<=8) && (p->getPosYPiece()>=1) && (p->getPosYPiece()<=8) && casesPlateauJeuEchecs[position]==NULL) {
        casesPlateauJeuEchecs[position]=p;
        return true;
    }
    return false;
}

bool EchecsPlateau::changerPositionPiece(EchecsPiece* p, int x, int y) {
    int posXDepartPieceJouer = p->getPosXPiece();
    int posYDepartPieceJouer = p->getPosYPiece();
    detruirePiece(posXDepartPieceJouer, posYDepartPieceJouer);
    p->move(x,y);
    initPositionPiece(p);
    return true;
}

EchecsPiece* EchecsPlateau::detruirePiece( int x, int y ) {
    if((x>=1) && (x<=8) && (y>=1) && (y<=8) && getPiece(x,y)!= NULL) {
        EchecsPiece* tmp = casesPlateauJeuEchecs[(x-1)+8*(y-1)];
        casesPlateauJeuEchecs[(x-1)+8*(y-1)] = NULL;
        return tmp;
    }
    return NULL;
}

void EchecsPlateau::affiche() {
    cout << "   1  2  3  4  5  6  7  8\n";
    for (int y = 1; y <= 8; ++y) {
        cout << "   _______________________\n";
        cout << y << " |";
        for (int x = 1; x <= 8; ++x){
            EchecsPiece* p = getPiece(x, y);
            if (p == 0){
                cout<<"  |";
            }
            else{
                cout << p->representationPiece() <<" |";
            }
        }
        cout << " " << y << endl;
    }
    cout << "   _______________________\n";
    cout << "   1  2  3  4  5  6  7  8\n";
}
