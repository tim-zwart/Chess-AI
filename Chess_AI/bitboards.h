#ifndef BITBOARDS_H_INCLUDED
#define BITBOARDS_H_INCLUDED

#include "libraries.h"

enum pieceType {king = 0, queen = 1, rook = 2, bishop = 3, knight = 4, pawn = 5};
enum moveType {normal = 0, kingsideCastle = 1, queensideCastle = 2, promote = 3, enpassant = 4};
enum side {white = 0, black = 1};

struct coord
{
    int x;
    int y;
};

struct Move
{
    coord startLoc;
    coord endLoc;
    moveType type;
};

coord convert(int x, int y);

struct storeMove
{
    Move move;
    storeMove *branch;
    storeMove *trunk;
    void destroy();
    void erase();
};

class Board;

class Piece
{
    friend class Board;
protected:
    void initialize(side whatSide, coord position);
    coord loc;
    side colour;
    pieceType whatPiece;
    virtual ~Piece(){};

public:
    side getColour(){ return colour; };
    pieceType gettType(){ return whatPiece; };
    virtual inline void Move(Board &b) = 0;
};

class King: public Piece
{
    private:
    inline void Move(Board &b);
    bool castle;

    public:
    King(side whatSide, coord position);
};

class Queen: public Piece
{
    private:
    inline void Move(Board &b);

    public:
    Queen(side whatSide, coord position);
};

class Rook: public Piece
{
    private:
    inline void Move(Board &b);
    bool castle;

    public:
    Rook(side whatSide, coord position);
};

class Bishop: public Piece
{
    private:
    inline void Move(Board &b);

    public:
    Bishop(side whatSide, coord position);
};

class Knight: public Piece
{
    private:
    inline void Move(Board &b);

    public:
    Knight(side whatSide, coord position);
};

class Pawn: public Piece
{
    private:
    inline void Move(Board &b);
    int dir;

    public:
    Pawn(side whatSide, coord position);
};

class Board
{
public:
    friend class Piece;
    friend class King;
    friend class Queen;
    friend class Pawn;

    Board();
    Board(const Board &b);
    ~Board();
    int pieceCount[2][6];
    void reset();
    void calcMoves();
    void output();
    vector <Piece*> pieces[2];
    coord *enpassant;

private:
public:

    Piece *board[8][8];

};

#endif // BITBOARDS_H_INCLUDED
