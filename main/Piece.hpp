#ifndef DEF_PIECE
#define DEF_PIECE

class Piece {
protected:
  int posXPiece;
  int posYPiece;
public:
  Piece();
  virtual ~Piece();
  int getPosXPiece();
  int getPosYPiece();
  virtual char representationPiece()=0;
};

#endif
