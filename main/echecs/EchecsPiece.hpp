#ifndef DEF_ECHECS_PIECE
#define DEF_ECHECS_PIECE

#include "../Piece.hpp"

class EchecsPlateau;

class EchecsPiece : public Piece {
protected:
  bool isPieceBlanche;
public:
  EchecsPiece();
  virtual ~EchecsPiece();
  EchecsPiece(const EchecsPiece & autre);
  EchecsPiece & operator=(const EchecsPiece & autre);
  EchecsPiece(int x, int y, bool pieceBlanche);
  void init(int x, int y, bool pieceBlanche);
  void move(int x, int y);
  bool getIsPieceBlanche();
  bool getIsPieceNoire();
  void affiche();
  virtual bool mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y);
  virtual char representationPiece();
};

class Roi : public EchecsPiece {
public:
  Roi(bool pieceBlanche);
  bool mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y);
  char representationPiece();
};

class Fou : virtual public EchecsPiece {
public:
  Fou(bool pieceBlanche, bool pieceGauche);
  bool mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y);
  char representationPiece();
};

class Tour : virtual public EchecsPiece {
public:
  Tour(bool pieceBlanche, bool pieceGauche);
  bool mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y);
  char representationPiece();
};

class Reine : public Fou, public Tour {
public:
  Reine(bool pieceBlanche);
  bool mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y);
  char representationPiece();
};

class Cavalier : virtual public EchecsPiece {
public:
  Cavalier(bool pieceBlanche, bool pieceGauche);
  bool mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y);
  char representationPiece();
};

class Pion :  virtual public EchecsPiece {
public:
  Pion(int x, bool pieceBlanche);
  bool mouvementValide(EchecsPlateau &plateauJeuEchecs, int x, int y);
  char representationPiece();
};

#endif
