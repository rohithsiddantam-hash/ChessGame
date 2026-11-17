#include <iostream>
#include <string>
using namespace std;

class cord
{
public:
    int x, y;
};

class piece
{
public:
    int color; // 0 black 1 white
    string name;
    int isking;
    piece(int color, string name, int isking)
    {
        this->color = color;
        this->name = name;
        this->isking = isking;
    }
};

class pawn : public piece
{
public:
    int firstmove;
    pawn(int color, string name) : piece(color, name, 0)
    {
        firstmove = 1;
    }

    int pawnoperation(cord start, cord end, piece *board[8][8])

    {
        if (!board[start.x][start.y])
            return 0;
        if (board[end.x][end.y] && color == board[end.x][end.y]->color)
            return 0;
        if (color == 1)
        {
            if (start.x - 1 == end.x && start.y == end.y && !board[end.x][end.y])
            {
                firstmove = 0;
                return 1;
            }
            if (start.x - 2 == end.x && start.y == end.y && !board[start.x - 1][start.y] && firstmove && !board[end.x][end.y])
            {
                firstmove = 0;
                return 1;
            }
            if (board[end.x][end.y] && start.x - 1 == end.x)
            {
                if (start.y - 1 == end.y || start.y + 1 == end.y)
                    return 1;
            }
            return 0;
        }
        else
        {
            if (start.x + 1 == end.x && start.y == end.y && !board[end.x][end.y])
            {
                firstmove = 0;
                return 1;
            }
            if (start.x + 2 == end.x && start.y == end.y && !board[start.x + 1][start.y] && firstmove && !board[end.x][end.y])
            {
                firstmove = 0;
                return 1;
            }
            if (board[end.x][end.y] && start.x + 1 == end.x)
            {
                if (start.y + 1 == end.y || start.y - 1 == end.y)
                    return 1;
            }
            return 0;
        }

        return 0;
    }
};

class bishop : public piece
{
public:
    bishop(int color, string name) : piece(color, name, 0) {}
    int bishopoperation(cord start, cord end, piece *board[8][8])
    {
        cord a;
        cord b;
        int found;
        found = 0;
        if (start.x == end.x && start.y == end.y)
        {

            return 0;
        }

        for (a.x = start.x + 1, a.y = start.y + 1; a.x < 8 && a.y < 8 && a.x >= 0 && a.y >= 0; a.x++, a.y++)
        {

            if (a.x == end.x && a.y == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            {

                return 1;
            }
            else if (a.x == end.x && a.y == end.y && ((board[end.x][end.y] && color == board[end.x][end.y]->color)))
            {

                return 0;
            }
            else if (board[a.x][a.y])
            {
                found = 0;
                break;
            }
        }

        for (a.x = start.x + 1, a.y = start.y - 1; a.x < 8 && a.y < 8 && a.x >= 0 && a.y >= 0; a.x++, a.y--)
        {
            if (a.x == end.x && a.y == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            {

                return 1;
            }
            else if (a.x == end.x && a.y == end.y && ((board[end.x][end.y] && color == board[end.x][end.y]->color)))
            {

                return 0;
            }
            else if (board[a.x][a.y])
            {
                found = 0;
                break;
            }
        }
        if (found)
            return found;
        for (a.x = start.x - 1, a.y = start.y + 1; a.x < 8 && a.y < 8 && a.x >= 0 && a.y >= 0; a.x--, a.y++)
        {
            if (a.x == end.x && a.y == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            {

                return 1;
            }
            else if (a.x == end.x && a.y == end.y && ((board[end.x][end.y] && color == board[end.x][end.y]->color)))
            {

                return 0;
            }
            else if (board[a.x][a.y])
            {
                found = 0;
                break;
            }
        }
        if (found)
            return found;
        for (a.x = start.x - 1, a.y = start.y - 1; a.x < 8 && a.y < 8 && a.x >= 0 && a.y >= 0; a.x--, a.y--)
        {
            if (a.x == end.x && a.y == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            {

                return 1;
            }
            else if (a.x == end.x && a.y == end.y && (board[end.x][end.y] && color == board[end.x][end.y]->color))
            {

                return 0;
            }
            else if (board[a.x][a.y])
            {
                found = 0;
                break;
            }
        }

        return 0;
    }
};

class knight : public piece
{
public:
    knight(int color, string name) : piece(color, name, 0) {}
    int knightoperation(cord start, cord end, piece *board[8][8])
    {
        if (start.x + 1 == end.x && start.y + 2 == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            return 1;
        if (start.x + 1 == end.x && start.y - 2 == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            return 1;
        if (start.x - 1 == end.x && start.y + 2 == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            return 1;
        if (start.x - 1 == end.x && start.y - 2 == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            return 1;
        if (start.x + 2 == end.x && start.y + 1 == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            return 1;
        if (start.x + 2 == end.x && start.y - 1 == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            return 1;
        if (start.x - 2 == end.x && start.y + 1 == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            return 1;
        if (start.x - 2 == end.x && start.y - 1 == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            return 1;
        return 0;
    }
};

class rook : public piece
{
public:
    rook(int color, string name) : piece(color, name, 0) {}
    int rookoperation(cord start, cord end, piece *board[8][8])
    {
        int a;
        if (start.x == end.x && start.y == end.y)
            return 0;

        for (a = start.x + 1; a < 8 && a >= 0; a++)
        {
            if (a == end.x && start.y == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            {
                return 1;
            }
            else if (a == end.x && start.y == end.y && (board[end.x][end.y] && color == board[end.x][end.y]->color))
                return 0;
            else if (board[a][start.y])
                break;
        }
        for (a = start.x - 1; a < 8 && a >= 0; a--)
        {
            if (a == end.x && start.y == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            {
                return 1;
            }
            else if (a == end.x && start.y == end.y && (board[end.x][end.y] && color == board[end.x][end.y]->color))
                return 0;
            else if (board[a][start.y])
                break;
        }
        for (a = start.y + 1; a < 8 && a >= 0; a++)
        {
            if (start.x == end.x && a == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            {
                return 1;
            }
            else if (start.x == end.x && a == end.y && (board[end.x][end.y] && color == board[end.x][end.y]->color))
                return 0;
            else if (board[start.x][a])
                break;
        }
        for (a = start.y - 1; a < 8 && a >= 0; a--)
        {
            if (start.x == end.x && a == end.y && (!board[end.x][end.y] || color != board[end.x][end.y]->color))
            {
                return 1;
            }
            else if (start.x == end.x && a == end.y && (board[end.x][end.y] && color == board[end.x][end.y]->color))
                return 0;
            else if (board[start.x][a])
                break;
        }
        return 0;
    }
};
class queen : public piece
{
public:
    queen(int color, string name) : piece(color, name, 0) {}
    int queenoperation(cord start, cord end, piece *board[8][8])
    {
        rook r(color, name);
        bishop b(color, name);

        if (r.rookoperation(start, end, board) == 1 ||
            b.bishopoperation(start, end, board) == 1)
            return 1;

        return 0;
    }
};

class king : public piece
{
public:
    king(int color, string name) : piece(color, name, 1) {}
    int incheck(piece *board[8][8], int color)
    {
        cord king_pos;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] && board[i][j]->isking == 1 && board[i][j]->color == color)
                {
                    king_pos.x = i;
                    king_pos.y = j;
                }
            }
        }

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] && board[i][j]->color != color)
                {
                    cord start, end;
                    start.x = i;
                    start.y = j;
                    end = king_pos;

                    string name = board[i][j]->name;

                    if (name == "W_Pawn" || name == "B_Pawn")
                    {
                        pawn *p = (pawn *)board[i][j];
                        if (p->pawnoperation(start, end, board))
                            return 1;
                    }

                    if (name == "W_Bisp" || name == "B_Bisp")
                    {
                        bishop *p = (bishop *)board[i][j];
                        if (p->bishopoperation(start, end, board))
                            return 1;
                    }

                    if (name == "W_Rook" || name == "B_Rook")
                    {
                        rook *p = (rook *)board[i][j];
                        if (p->rookoperation(start, end, board))
                            return 1;
                    }

                    if (name == "W_Quen" || name == "B_Quen")
                    {
                        queen *p = (queen *)board[i][j];
                        if (p->queenoperation(start, end, board))
                            return 1;
                    }

                    if (name == "W_Kngt" || name == "B_Kngt")
                    {
                        knight *p = (knight *)board[i][j];
                        if (p->knightoperation(start, end, board))
                            return 1;
                    }
                }
            }
        }

        return 0;
    }
    int kingoperation(cord start, cord end, piece *board[8][8])
    {

        if (board[end.x][end.y] && board[end.x][end.y]->color == color)
            return 0;

        if (
            (start.x + 1 == end.x && start.y == end.y) ||
            (start.x - 1 == end.x && start.y == end.y) ||
            (start.x == end.x && start.y + 1 == end.y) ||
            (start.x == end.x && start.y - 1 == end.y) ||
            (start.x + 1 == end.x && start.y + 1 == end.y) ||
            (start.x + 1 == end.x && start.y - 1 == end.y) ||
            (start.x - 1 == end.x && start.y + 1 == end.y) ||
            (start.x - 1 == end.x && start.y - 1 == end.y))
        {
            piece *temp = board[end.x][end.y];

            board[end.x][end.y] = board[start.x][start.y];
            board[start.x][start.y] = nullptr;

            if (incheck(board, color))
            {

                board[start.x][start.y] = board[end.x][end.y];
                board[end.x][end.y] = temp;
                return 0;
            }

            board[start.x][start.y] = board[end.x][end.y];
            board[end.x][end.y] = temp;

            return 1;
        }

        return 0;
    }
};

class board
{
public:
    piece *board[8][8];

    void initial()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board[i][j] = nullptr;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            board[1][i] = new pawn(0, "B_Pawn");
        }
        for (int i = 0; i < 8; i++)
        {
            board[6][i] = new pawn(1, "W_Pawn");
        }
        board[0][0] = new rook(0, "B_Rook");
        board[0][7] = new rook(0, "B_Rook");
        board[7][0] = new rook(1, "W_Rook");
        board[7][7] = new rook(1, "W_Rook");

        board[0][1] = new knight(0, "B_Kngt");
        board[0][6] = new knight(0, "B_Kngt");
        board[7][1] = new knight(1, "W_Kngt");
        board[7][6] = new knight(1, "W_Kngt");

        board[0][2] = new bishop(0, "B_Bisp");
        board[0][5] = new bishop(0, "B_Bisp");
        board[7][2] = new bishop(1, "W_Bisp");
        board[7][5] = new bishop(1, "W_Bisp");

        board[0][3] = new queen(0, "B_Quen");
        board[7][3] = new queen(1, "W_Quen");

        board[0][4] = new king(0, "B_King");
        board[7][4] = new king(1, "W_King");
    }
    void displayboard()
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == 0)
                cout << "     a     b      c      d      e      f      g      h  \n";
            cout << "----------------------------------------------------------\n";
            for (int j = 0; j < 8; j++)
            {
                if (j == 0)
                    cout << 8 - i;
                cout << "|";
                if (board[i][j] == nullptr)
                    cout << "      ";

                else
                    cout << board[i][j]->name;
                if (j == 7)
                    cout << "|" << 8 - i;
            }

            cout << endl;
            if (i == 7)
            {

                cout << "----------------------------------------------------------\n";
                cout << "     a     b      c      d      e      f      g      h  \n";
            }
        }
    }
    void move(cord a, cord b)
    {
        board[b.x][b.y] = board[a.x][a.y];
        board[a.x][a.y] = nullptr;
    }
};

class game
{

public:
    string player1;
    string player2;
    cord start;
    cord end;

    cord convert(string name)
    {
        cord k;
        k.y = (int)(name[0] - 97);
        k.x = 8 - (name[1] - '0');
        return k;
    }
    int kingincheck(piece *board[8][8], int my_color)
    {
        cord king_pos;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] && board[i][j]->isking == 1 && board[i][j]->color == my_color)
                {
                    king_pos.x = i;
                    king_pos.y = j;
                }
            }
        }

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] && board[i][j]->color != my_color)
                {
                    cord start, end;
                    start.x = i;
                    start.y = j;
                    end = king_pos;

                    string name = board[i][j]->name;

                    if (name == "W_Pawn" || name == "B_Pawn")
                    {
                        pawn *p = (pawn *)board[i][j];
                        if (p->pawnoperation(start, end, board))
                            return 1;
                    }

                    if (name == "W_Bisp" || name == "B_Bisp")
                    {
                        bishop *p = (bishop *)board[i][j];
                        if (p->bishopoperation(start, end, board))
                            return 1;
                    }

                    if (name == "W_Rook" || name == "B_Rook")
                    {
                        rook *p = (rook *)board[i][j];
                        if (p->rookoperation(start, end, board))
                            return 1;
                    }

                    if (name == "W_Quen" || name == "B_Quen")
                    {
                        queen *p = (queen *)board[i][j];
                        if (p->queenoperation(start, end, board))
                            return 1;
                    }

                    if (name == "W_Kngt" || name == "B_Kngt")
                    {
                        knight *p = (knight *)board[i][j];
                        if (p->knightoperation(start, end, board))
                            return 1;
                    }
                }
            }
        }

        return 0;
    }
    int notover(piece *board[8][8], int color)
    {
        cord start, end;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] && board[i][j]->color == color)
                {
                    start.x = i;
                    start.y = j;

                    for (int x = 0; x < 8; x++)
                    {
                        for (int y = 0; y < 8; y++)
                        {
                            end.x = x;
                            end.y = y;

                            string name = board[i][j]->name;
                            int valid = 0;

                            if (name == "W_Pawn" || name == "B_Pawn")
                            {
                                pawn *p = (pawn *)board[i][j];
                                valid = p->pawnoperation(start, end, board);
                            }
                            if (name == "W_Bisp" || name == "B_Bisp")
                            {
                                bishop *p = (bishop *)board[i][j];
                                valid = p->bishopoperation(start, end, board);
                            }
                            if (name == "W_Rook" || name == "B_Rook")
                            {
                                rook *p = (rook *)board[i][j];
                                valid = p->rookoperation(start, end, board);
                            }
                            if (name == "W_Quen" || name == "B_Quen")
                            {
                                queen *p = (queen *)board[i][j];
                                valid = p->queenoperation(start, end, board);
                            }
                            if (name == "W_Kngt" || name == "B_Kngt")
                            {
                                knight *p = (knight *)board[i][j];
                                valid = p->knightoperation(start, end, board);
                            }
                            if (name == "W_King" || name == "B_King")
                            {
                                king *p = (king *)board[i][j];
                                valid = p->kingoperation(start, end, board);
                            }

                            if (!valid)
                                continue;

                            piece *temp = board[end.x][end.y];

                            board[end.x][end.y] = board[start.x][start.y];
                            board[start.x][start.y] = nullptr;

                            if (!kingincheck(board, color))
                            {

                                board[start.x][start.y] = board[end.x][end.y];
                                board[end.x][end.y] = temp;

                                return 1;
                            }

                            board[start.x][start.y] = board[end.x][end.y];
                            board[end.x][end.y] = temp;
                        }
                    }
                }
            }
        }

        return 0;
    }
    int invalid_move_checker_1()
    {
        if (start.x > 7 || start.x < 0 || start.y > 7 || start.y < 0 || end.x > 7 || end.y > 7 || end.x < 0 || end.y < 0)
            return 0;
        else
            return 1;
    }

    void user_reader()
    {

        cout << "user 1 enter your name :";
        cin >> player1;
        cout << "you are white";
        cout << "\nuser 2 enter your name :";
        cin >> player2;
        cout << "you are black\n";
    }
    void gameconnect(board *b)
    {
        user_reader();
        string piece_name;
        string cur_location;
        string fur_location;
        int inv1;
        int inv2;
        int inv3;
        int main_inv = 0;
        int i = 1;

        while (1)
        {
            if (i % 2 == 0)
                cout << player2 << " it is your turn";
            else
                cout << player1 << " it is your turn";
            cout << endl;
            cout << "enter name of piece to move :";
            cin >> piece_name;
            cout << "\nenter piece current location :";
            cin >> cur_location;
            cout << "\nenter piece destination :";
            cin >> fur_location;
            start = convert(cur_location);
            end = convert(fur_location);
            piece *temp = b->board[end.x][end.y];

            b->board[end.x][end.y] = b->board[start.x][start.y];
            b->board[start.x][start.y] = nullptr;

            int still_check;

            if (i % 2 != 0)
                still_check = kingincheck(b->board, 1);
            else
                still_check = kingincheck(b->board, 0);

            b->board[start.x][start.y] = b->board[end.x][end.y];
            b->board[end.x][end.y] = temp;

            if (still_check)
            {
                cout << "King will still be in check , invalid\n";
                continue;
            }

            inv1 = invalid_move_checker_1();
            if (!inv1)
            {
                cout << "Invalid cant go outside board";
                continue;
            }

            if (i % 2 != 0)
            {
                if (b->board[start.x][start.y] && b->board[start.x][start.y]->color == 1)
                    inv3 = 1;
                else
                    inv3 = 0;
            }
            else
            {
                if (b->board[start.x][start.y] && b->board[start.x][start.y]->color == 0)
                    inv3 = 1;
                else
                    inv3 = 0;
            }
            if (!inv3)
            {
                cout << "You cant move opponents piece \n";
                continue;
            }

            if (b->board[start.x][start.y] && piece_name != b->board[start.x][start.y]->name)
                inv2 = 0;
            else if (b->board[start.x][start.y])
                inv2 = 1;
            else
                inv2 = 0;
            if (!inv2)
            {
                cout << "location mismatch retry\n";
                continue;
            }
            if (b->board[start.x][start.y] && piece_name == b->board[start.x][start.y]->name && (piece_name == "W_Pawn" || piece_name == "B_Pawn"))
            {
                pawn *p = (pawn *)b->board[start.x][start.y];
                main_inv = p->pawnoperation(start, end, b->board);
            }
            if (b->board[start.x][start.y] && piece_name == b->board[start.x][start.y]->name && (piece_name == "W_Bisp" || piece_name == "B_Bisp"))
            {
                bishop *p = (bishop *)b->board[start.x][start.y];
                main_inv = p->bishopoperation(start, end, b->board);
            }
            if (b->board[start.x][start.y] && piece_name == b->board[start.x][start.y]->name && (piece_name == "W_Rook" || piece_name == "B_Rook"))
            {
                rook *p = (rook *)b->board[start.x][start.y];
                main_inv = p->rookoperation(start, end, b->board);
            }
            if (b->board[start.x][start.y] && piece_name == b->board[start.x][start.y]->name && (piece_name == "W_Quen" || piece_name == "B_Quen"))
            {
                queen *p = (queen *)b->board[start.x][start.y];
                main_inv = p->queenoperation(start, end, b->board);
            }
            if (b->board[start.x][start.y] && piece_name == b->board[start.x][start.y]->name && (piece_name == "W_Kngt" || piece_name == "B_Kngt"))
            {
                knight *p = (knight *)b->board[start.x][start.y];
                main_inv = p->knightoperation(start, end, b->board);
            }
            if (b->board[start.x][start.y] && piece_name == b->board[start.x][start.y]->name && (piece_name == "W_King" || piece_name == "B_King"))
            {
                king *p = (king *)b->board[start.x][start.y];
                main_inv = p->kingoperation(start, end, b->board);
            }
            if (inv1 == 1 && inv2 == 1 && main_inv && inv3)
            {

                b->move(start, end);
            }
            else
            {
                cout << "Invalid move retry\n";
                continue;
            }
            b->displayboard();
            int w_check = kingincheck(b->board, 1);
            int b_check = kingincheck(b->board, 0);
            if (w_check)
            {
                cout << "white in check\n";

                if (!notover(b->board, 1))
                {
                    cout << "Checkmate Black wins :)\n";
                    break;
                }
            }

            if (b_check)
            {
                cout << "black in check\n";

                if (!notover(b->board, 0))
                {
                    cout << "Checkmate White wins :)\n";
                    break;
                }
            }
            piece *moved = b->board[end.x][end.y];

            if (moved && (moved->name == "W_Pawn" || moved->name == "B_Pawn"))
            {
                if ((moved->color == 1 && end.x == 0) || (moved->color == 0 && end.x == 7))
                {
                    cout << "Pawn promotion Choose piece to convert Q/R/B/N ";
                    char choice;
                    cin >> choice;

                    int color = moved->color;

                    delete b->board[end.x][end.y];

                    if (choice == 'Q')
                        if (color == 1)
                        {
                            b->board[end.x][end.y] = new queen(1, "W_Quen");
                        }
                        else
                            b->board[end.x][end.y] = new queen(0, "B_Quen");
                    else if (choice == 'R')
                        if (color == 1)
                        {
                            b->board[end.x][end.y] = new rook(1, "W_Rook");
                        }
                        else
                            b->board[end.x][end.y] = new rook(0, "B_Rook");

                    else if (choice == 'B')
                        if (color == 1)
                        {
                            b->board[end.x][end.y] = new bishop(1, "W_Bisp");
                        }
                        else
                            b->board[end.x][end.y] = new bishop(0, "B_Bisp");
                    else if (choice == 'N')
                        if (color == 1)
                        {
                            b->board[end.x][end.y] = new knight(1, "W_Kngt");
                        }
                        else
                            b->board[end.x][end.y] = new knight(0, "B_Kngt");
                    else
                    {
                        cout << "Invalid choice so converting to  queen\n";
                        if (color == 1)
                        {
                            b->board[end.x][end.y] = new queen(1, "W_Quen");
                        }
                        else
                            b->board[end.x][end.y] = new queen(0, "B_Quen");
                    }
                }
            }
            i++;
        }
    }
};
int main()
{
    board b;
    b.initial();
    b.displayboard();
    game g;
    g.gameconnect(&b);
}