#include "bitboards.h"

// Convert two integers to a coordinate
inline coord convert(int x, int y)
{
    coord c;
    c.x = x;
    c.y = y;
    return c;
}

// Default piece initializer
void Piece::initialize(side whatSide, coord position)
{
    colour = whatSide;
    loc = position;
}

// Specific piece initializations
King::King(side whatSide, coord position)
{
    whatPiece = king;
    initialize(whatSide, position);
}

Queen::Queen(side whatSide, coord position)
{
    whatPiece = queen;
    initialize(whatSide, position);
}

Rook::Rook(side whatSide, coord position)
{
    whatPiece = rook;
    initialize(whatSide, position);
}

Bishop::Bishop(side whatSide, coord position)
{
    whatPiece = bishop;
    initialize(whatSide, position);
}

Knight::Knight(side whatSide, coord position)
{
    whatPiece = knight;
    initialize(whatSide, position);
}

Pawn::Pawn(side whatSide, coord position)
{
    whatPiece = pawn;
    initialize(whatSide, position);
    dir = (colour-0.5) * -2;
}

// Calculate possible piece movements
inline void King::Move(Board &b)
{

}

inline void Queen::Move(Board &b)
{
    bool u, d, l, r, ul, ur, dl, dr = true;

    for(int i=1; i<8; i++)
    {
        // If moving up is off the board
        if((u || ul || ur) && loc.y + i>7)
        {
            u = false;
            ul = false;
            ur = false;
        }

        // If moving down is off the board
        if((d || dl || dr) && loc.y - i<0)
        {
            d = false;
            dl = false;
            dr = false;
        }

        // If moving right is off the board
        if((r || ur || dr) && loc.x + i>7)
        {
            r = false;
            ur = false;
            dr = false;
        }

        // If moving left is off the board
        if((l || ul || dl) && loc.x - i<0)
        {
            l = false;
            ul = false;
            dl = false;
        }

        // Up
        if(u)
        {
            if(b.board[loc.x][loc.y + i] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x][loc.y + i]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                u = false;
            }
        }

        // Down
        if(d)
        {
            if(b.board[loc.x][loc.y - i] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x][loc.y - i]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                d = false;
            }
        }

        // Left
        if(l)
        {
            if(b.board[loc.x - i][loc.y] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x - i][loc.y]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                l = false;
            }
        }

        // Right
        if(r)
        {
            if(b.board[loc.x + i][loc.y] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x + i][loc.y]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                r = false;
            }
        }

        // Up left
        if(ul)
        {
            if(b.board[loc.x][loc.y + i] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x][loc.y + i]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                ul = false;
            }
        }

        // Up right
        if(ur)
        {
            if(b.board[loc.x][loc.y - i] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x][loc.y - i]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                ur = false;
            }
        }

        // Down left
        if(dl)
        {
            if(b.board[loc.x - i][loc.y] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x - i][loc.y]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                dl = false;
            }
        }

        // Down right
        if(dr)
        {
            if(b.board[loc.x + i][loc.y] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x + i][loc.y]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                dr = false;
            }
        }

        if(!ul && !ur && !dl && !dr)
        {
            break;
        }

        if(!u && !d && !l && !r)
        {
            break;
        }
    }
}

inline void Rook::Move(Board &b)
{
    bool u, d, l, r = true;
    for(int i=1; i<8; i++)
    {
        // Up
        if(u)
        {
            if(loc.y + i>7)
            {
                u = false;
            }
            else if(b.board[loc.x][loc.y + i] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x][loc.y + i]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                u = false;
            }
        }

        // Down
        if(d)
        {
            if(loc.y - i<0)
            {
                d = false;
            }
            else if(b.board[loc.x][loc.y - i] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x][loc.y - i]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                d = false;
            }
        }

        // Left
        if(l)
        {
            if(loc.x - i<0)
            {
                l = false;
            }
            else if(b.board[loc.x - i][loc.y] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x - i][loc.y]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                l = false;
            }
        }

        // Right
        if(r)
        {
            if(loc.y+i>7)
            {
                r = false;
            }
            else if(b.board[loc.x + i][loc.y] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x + i][loc.y]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                r = false;
            }
        }

        if(!u && !d && !l && !r)
        {
            break;
        }
    }
}

inline void Bishop::Move(Board &b)
{
    bool ul, ur, dl, dr = true;
    for(int i=1; i<8; i++)
    {
        // Moving up too high
        if((ul || ur) && loc.y + i > 7)
        {
            ul = false;
            ur = false;
        }

        // Moving down too low
        if((dl || dr) && loc.y - i < 0)
        {
            dl = false;
            dr = false;
        }

        // Moving too far to the right
        if((ur || dr) && loc.x + i > 7)
        {
            ur = false;
            dr = false;
        }

        // Moving too far to the right
        if((ul || dl) && loc.x - i < 0)
        {
            ul = false;
            dl = false;
        }

        // Up left
        if(ul)
        {
            if(b.board[loc.x][loc.y + i] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x][loc.y + i]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                ul = false;
            }
        }

        // Up right
        if(ur)
        {
            if(b.board[loc.x][loc.y - i] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x][loc.y - i]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                ur = false;
            }
        }

        // Down left
        if(dl)
        {
            if(b.board[loc.x - i][loc.y] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x - i][loc.y]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                dl = false;
            }
        }

        // Down right
        if(dr)
        {
            if(b.board[loc.x + i][loc.y] == 0)
            {
                // Save move
            }
            else if(b.board[loc.x + i][loc.y]->getColour() == !colour)
            {
                // Save move
            }
            else
            {
                dr = false;
            }
        }

        if(!ul && !ur && !dl && !dr)
        {
            break;
        }
    }
}

inline void Knight::Move(Board &b)
{

}

inline void Pawn::Move(Board &b)
{
    // Move Forward
    if(b.board[loc.x][loc.y+dir] == 0)
    {
        // Store moving forward 1

        if(loc.y == 3.5 - 2.5*dir && b.board[loc.x][(int)(3.5 - dir/2)] == 0)
        {
            // Store moving forward 2
        }
    }

    if(loc.x<7 && b.board[loc.x+1][loc.y+dir] != 0 && b.board[loc.x+1][loc.y+dir]->getColour() != colour)
    {
        // Store taking to the right
    }

    if(loc.x>0 && b.board[loc.x-1][loc.y+dir] != 0 && b.board[loc.x-1][loc.y+dir]->getColour() != colour)
    {
        // Store taking to the left
    }

    // En Passant
    if(enpassant != 0 && loc.y == 3.5 + 0.5*dir && abs(b.enpassant->x - loc.x) == 1)
    {
        // Store taking pawn from loc to enpassant
    }
}

// Board constructor
Board::Board()
{
    for(int x=0; x<8; x++)
    {
        for(int y=0; y<8; y++)
        {
            board[x][y] = 0;
        }
    }
    enpassant = 0;
}

// Board copy constructor (passing into a function)
Board::Board(const Board &b)
{

}

// Board destructor
Board::~Board()
{

}

// Reset board to starting position
void Board::reset()
{
    for(int x=0; x<8; x++)
    {
        for(int y=0; y<8; y++)
        {
            if(board[x][y]!=0)
            {
                delete board[x][y];
                board[x][y] = 0;
            }
        }
    }

    pieces[0].clear();
    pieces[1].clear();

    for(int i=0; i<8; i++)
    {
        // White pawns
        board[i][1] = new Pawn(white, convert(i, 1));
        pieces[0].push_back(board[i][1]);

        // Black pawns
        board[i][6] = new Pawn(black, convert(i, 6));
        pieces[1].push_back(board[i][6]);
    }

    // White Rooks
    board[0][0] = new Rook(white, convert(0, 0));
    board[7][0] = new Rook(white, convert(7, 0));

    pieces[0].push_back(board[0][0]);
    pieces[0].push_back(board[7][0]);

    // Black Rooks
    board[0][7] = new Rook(black, convert(0, 7));
    board[7][7] = new Rook(black, convert(7, 7));

    pieces[1].push_back(board[0][7]);
    pieces[1].push_back(board[7][7]);


    // White Knights
    board[1][0] = new Knight(white, convert(1, 0));
    board[6][0] = new Knight(white, convert(6, 0));

    pieces[0].push_back(board[1][0]);
    pieces[0].push_back(board[6][0]);

    // Black Knights
    board[1][7] = new Knight(black, convert(1, 7));
    board[6][7] = new Knight(black, convert(6, 7));

    pieces[1].push_back(board[1][7]);
    pieces[1].push_back(board[6][7]);


    // White Bishops
    board[2][0] = new Bishop(white, convert(2, 0));
    board[5][0] = new Bishop(white, convert(5, 0));

    pieces[0].push_back(board[2][0]);
    pieces[0].push_back(board[5][0]);

    // Black Bishop
    board[2][7] = new Bishop(black, convert(2, 7));
    board[5][7] = new Bishop(black, convert(5, 7));

    pieces[1].push_back(board[2][7]);
    pieces[1].push_back(board[5][7]);


    // White Queen
    board[3][0] = new Queen(white, convert(3, 0));
    pieces[0].push_back(board[3][0]);

    // Black Queen
    board[3][7] = new Queen(black, convert(3, 7));
    pieces[1].push_back(board[3][7]);


    // White King
    board[4][0] = new King(white, convert(4, 0));
    pieces[0].push_back(board[4][0]);

    // Black King
    board[4][7] = new King(black, convert(4, 7));
    pieces[1].push_back(board[4][7]);
}

void Board::output()
{
    for(int y=7; y>=0; y--)
    {
        for(int x=0; x<8; x++)
        {
            if(board[x][y] == 0)
            {
                cout << ". ";
                continue;
            }
            char c;
            switch(board[x][y]->whatPiece)
            {
            case king:
                c = 'K';
                break;

            case queen:
                c = 'Q';
                break;

            case rook:
                c = 'R';
                break;

            case bishop:
                c = 'B';
                break;

            case knight:
                c = 'N';
                break;

            case pawn:
                c = 'P';
                break;
            default:
                c = ' ';
                break;
            }
            c += ('a'-'A') * board[x][y]->colour;
            cout << c << " ";
        }
        cout << endl;
    }
}
