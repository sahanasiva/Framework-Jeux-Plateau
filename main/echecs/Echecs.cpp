#include <iostream>
#include <string>
#include "Echecs.hpp"
#include "EchecsPiece.hpp"
#include "EchecsJoueur.hpp"
#include "EchecsPlateau.hpp"
using namespace std;

Echecs::Echecs() : Partie() {}

Echecs::~Echecs() {}

void Echecs::verifCasesExistantes(){
    while(true) {
        cout << "\nX = ";
        cin >> posXJoueurCourant;
        cout << "\nY = ";
        cin >> posYJoueurCourant;
        if((posXJoueurCourant>=1) && (posXJoueurCourant<=8) && (posYJoueurCourant>=1) && (posYJoueurCourant<=8)){
            break;
        }
        else {
            cout << "\nPositions incorrectes. Rejouer !";
        }
    }
}

int Echecs::isEchecMat() {
    int echec = -1;
    //a implementer
    return (echec);
}

void Echecs::lancerPartie(){
    joueurCourant = true; //init : joueurBlanc
    bool finDePartie = false;
    int posXDepart;
    int posYDepart;

    joueurB.initPositionPieceJoueur(plateauJeuEchecs);
    joueurN.initPositionPieceJoueur(plateauJeuEchecs);

   //construction PieceJoueur
   Roi roiBlanc(true);
   Roi roiNoir(false);
   Reine reineBlanc(true);
   Reine reineNoir(false);
   Tour tourBlanc1(true, true);
   Tour tourNoir1(false, true);
   Tour tourBlanc2(true, false);
   Tour tourNoir2(false, false);
   Fou fouBlanc1(true, true);
   Fou fouNoir1(false, true);
   Fou fouBlanc2(true, false);
   Fou fouNoir2(false, false);
   Cavalier cavalierBlanc1(true, true);
   Cavalier cavalierNoir1(false, true);
   Cavalier cavalierBlanc2(true, false);
   Cavalier cavalierNoir2(false, false);
   Pion pionBlanc1(1, true);
   Pion pionNoir1(1, false);
   Pion pionBlanc2(2, true);
   Pion pionNoir2(2, false);
   Pion pionBlanc3(3, true);
   Pion pionNoir3(3, false);
   Pion pionBlanc4(4, true);
   Pion pionNoir4(4, false);
   Pion pionBlanc5(5, true);
   Pion pionNoir5(5, false);
   Pion pionBlanc6(6, true);
   Pion pionNoir6(6, false);
   Pion pionBlanc7(7, true);
   Pion pionNoir7(7, false);
   Pion pionBlanc8(8, true);
   Pion pionNoir8(8, false);

   //init Position depart Piece Joueur
   plateauJeuEchecs.detruirePiece(5,1);
   plateauJeuEchecs.initPositionPiece(&roiBlanc);
   plateauJeuEchecs.detruirePiece(5,8);
   plateauJeuEchecs.initPositionPiece(&roiNoir);
   plateauJeuEchecs.detruirePiece(4,1);
   plateauJeuEchecs.initPositionPiece(&reineBlanc);
   plateauJeuEchecs.detruirePiece(4,8);
   plateauJeuEchecs.initPositionPiece(&reineNoir);
   plateauJeuEchecs.detruirePiece(1,1);
   plateauJeuEchecs.initPositionPiece(&tourBlanc1);
   plateauJeuEchecs.detruirePiece(1,8);
   plateauJeuEchecs.initPositionPiece(&tourNoir1);
   plateauJeuEchecs.detruirePiece(8,1);
   plateauJeuEchecs.initPositionPiece(&tourBlanc2);
   plateauJeuEchecs.detruirePiece(8,8);
   plateauJeuEchecs.initPositionPiece(&tourNoir2);
   plateauJeuEchecs.detruirePiece(3,1);
   plateauJeuEchecs.initPositionPiece(&fouBlanc1);
   plateauJeuEchecs.detruirePiece(3,8);
   plateauJeuEchecs.initPositionPiece(&fouNoir1);
   plateauJeuEchecs.detruirePiece(6,1);
   plateauJeuEchecs.initPositionPiece(&fouBlanc2);
   plateauJeuEchecs.detruirePiece(6,8);
   plateauJeuEchecs.initPositionPiece(&fouNoir2);
   plateauJeuEchecs.detruirePiece(2,1);
   plateauJeuEchecs.initPositionPiece(&cavalierBlanc1);
   plateauJeuEchecs.detruirePiece(2,8);
   plateauJeuEchecs.initPositionPiece(&cavalierNoir1);
   plateauJeuEchecs.detruirePiece(7,1);
   plateauJeuEchecs.initPositionPiece(&cavalierBlanc2);
   plateauJeuEchecs.detruirePiece(7,8);
   plateauJeuEchecs.initPositionPiece(&cavalierNoir2);
   plateauJeuEchecs.detruirePiece(1,2);
   plateauJeuEchecs.initPositionPiece(&pionBlanc1);
   plateauJeuEchecs.detruirePiece(1,7);
   plateauJeuEchecs.initPositionPiece(&pionNoir1);
   plateauJeuEchecs.detruirePiece(2,2);
   plateauJeuEchecs.initPositionPiece(&pionBlanc2);
   plateauJeuEchecs.detruirePiece(2,7);
   plateauJeuEchecs.initPositionPiece(&pionNoir2);
   plateauJeuEchecs.detruirePiece(3,2);
   plateauJeuEchecs.initPositionPiece(&pionBlanc3);
   plateauJeuEchecs.detruirePiece(3,7);
   plateauJeuEchecs.initPositionPiece(&pionNoir3);
   plateauJeuEchecs.detruirePiece(4,2);
   plateauJeuEchecs.initPositionPiece(&pionBlanc4);
   plateauJeuEchecs.detruirePiece(4,7);
   plateauJeuEchecs.initPositionPiece(&pionNoir4);
   plateauJeuEchecs.detruirePiece(5,2);
   plateauJeuEchecs.initPositionPiece(&pionBlanc5);
   plateauJeuEchecs.detruirePiece(5,7);
   plateauJeuEchecs.initPositionPiece(&pionNoir5);
   plateauJeuEchecs.detruirePiece(6,2);
   plateauJeuEchecs.initPositionPiece(&pionBlanc6);
   plateauJeuEchecs.detruirePiece(6,7);
   plateauJeuEchecs.initPositionPiece(&pionNoir6);
   plateauJeuEchecs.detruirePiece(7,2);
   plateauJeuEchecs.initPositionPiece(&pionBlanc7);
   plateauJeuEchecs.detruirePiece(7,7);
   plateauJeuEchecs.initPositionPiece(&pionNoir7);
   plateauJeuEchecs.detruirePiece(8,2);
   plateauJeuEchecs.initPositionPiece(&pionBlanc8);
   plateauJeuEchecs.detruirePiece(8,7);
   plateauJeuEchecs.initPositionPiece(&pionNoir8);

   //partie
    while(finDePartie == false) {
        bool mouvementValide = false;
        int echec = -1;
        plateauJeuEchecs.affiche();

        //piece a jouer
        if (joueurCourant) {
            cout << "\nAu tour du joueur blanc." << endl << "Saisir la piece a jouer : ";
        } else {
            cout << "\nAu tour du joueur noir." << endl << "Saisir la piece a jouer : ";
        }

        while(!mouvementValide) {
            this->verifCasesExistantes();
            posXDepart = this->posXJoueurCourant;
            posYDepart = this->posYJoueurCourant;

                if (plateauJeuEchecs.getPiece(posXDepart, posYDepart) != NULL) { //verifier si piece valide
                    if ((joueurCourant && plateauJeuEchecs.getPiece(posXDepart, posYDepart)->getIsPieceBlanche()) || (!joueurCourant && plateauJeuEchecs.getPiece(posXDepart, posYDepart)->getIsPieceNoire())) { //verif si piece joueurCourant
                        while(!mouvementValide) {
                            cout << "\nSaisir le coup a jouer : ";
                            verifCasesExistantes();
                            if(plateauJeuEchecs.getPiece(posXDepart,posYDepart)->mouvementValide(plateauJeuEchecs, posXJoueurCourant, posYJoueurCourant)){
                                switch(echec) {
                                    case 1 :
                                        //Echec si deplacement
                                        break;
                                    case 2 :
                                        //Echec Roi
                                        break;
                                    case 3 :
                                        //Echec et Mat Roi
                                        break;
                                    default:
                                        plateauJeuEchecs.changerPositionPiece(plateauJeuEchecs.getPiece(posXDepart, posYDepart), posXJoueurCourant, posYJoueurCourant);
                                        mouvementValide = true;
                                        break;
                                }
                            } else {
                                cout << "\nCoup invalide.";
                            }
                        }
                    }
                    else {
                        cout << "\nCette piece ne vous appartient pas. Rejouer !";
                    }
                }
                else {
                    cout << "\nPiece invalide." << endl << "Rejouer !";
                }
        }
        joueurCourant = !joueurCourant;   //tour terminer - changer joueur
      }
}
