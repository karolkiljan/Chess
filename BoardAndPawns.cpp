//
// Created by karol on 12/31/18.
//

//
// Created by karol on 11/26/18.
//
#include <string>
#include <vector>

using namespace std;
//dopisac metode, ktora bedzie sprawdzala u krola mozliwe bicia


class Chess_Pawn {
public:
    int row;
    int col;
    void moves(){};
    int price;
    char color;

    Chess_Pawn(int row, int col, int price, char color){
        this -> row = row;
        this -> col = col;
        this -> color = color;
        this -> price = price;
    }
};

//-----------------------------------------------
class Field {
public:
    int row;
    int column;

    Field(int row, int column) {
        this->row = row;
        this->column = column;
    };
    Chess_Pawn *pawn = NULL;

};

class Board {
public:
    Field *board[8][8];

    Board(){
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                this -> board[row][col] = new Field(row, col);
            }
        }
    };

};
//-------------------------------------------------
class Bishop: public Chess_Pawn {
    int price = 9;

    vector<Field*> moves(int row, int col, Field *board[8][8]){
        int start_row = row;
        int start_col = col;
        vector<Field*> result;

        // sprawdzam ruch góra-lewo
        row--;
        col--;
        while((row >= 0 and col >= 0) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            row--;
            col--;
        }
        if((row >= 0 and col >= 0) and (board[row][col] -> pawn -> color != this -> color))
        result.push_back(board[row][col]);

        //ruch gora-prawo

        row = start_row -1;
        col = start_col +1;
        while((row >= 0 and col <= 8) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            row--;
            col++;
        }
        if((row >= 0 and col <= 8) and (board[row][col] -> pawn -> color != this -> color))
        result.push_back(board[row][col]);

        // dol-prawo
        row = start_row +1;
        col = start_col +1;
        while((row <= 8 and col <= 8) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            row++;
            col++;
        }
        if((row <= 8 and col <= 8) and (board[row][col] -> pawn -> color != this -> color))
        result.push_back(board[row][col]);
        //ruch dol-lewo
        row = start_row +1;
        col = start_col -1;
        while((row <= 8 and col <= 8) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            row++;
            col++;
        }
        if((row <= 8 and col <= 8) and (board[row][col] -> pawn -> color != this -> color))
        result.push_back(board[row][col]);

        return result;

    };

};

class Rook: public Chess_Pawn {
public:
    int price = 7;
    vector<Field*> moves(int row, int col, Field *board[8][8]){
        int start_row = row;
        int start_col = col;
        std::vector <Field*> result;
        //gora
        row--;
        while((row >= 0) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            row--;
        }
        if((row >=0) and (board[row][col] -> pawn -> color != this -> color))
        result.push_back(board[row][col]);

        //dol
        row = start_row +1;
        while((row <= 8) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            row++;
        }
        if((row <= 8) and (board[row][col] -> pawn -> color != this -> color))
        result.push_back(board[row][col]);

        //prawo
        row = start_row;
        col++;
        while((col <= 8) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            col++;
        }
        if((col <=8) and (board[row][col] -> pawn -> color != this -> color))
        result.push_back(board[row][col]);

        //lewo
        col = start_col -1;
        while((col >= 0) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            col--;
        }
        if((col >= 0) and (board[row][col] -> pawn -> color != this -> color))
        result.push_back(board[row][col]);

        return result;


    };
};

class Knight: public Chess_Pawn {
public:
    int price = 8;
    vector<Field*> moves(int row, int col, Field *board[8][8]){
        vector<Field*> result;
        //lewo-gora
        if(row - 1 >= 0 and col - 2 >= 0)
            if(board[row][col] -> pawn -> color != this -> color)
                result.push_back(board[row-1][col-2]);
        //lewo-dol
        if(row + 1 <= 8 and col - 2 >= 0)
            if(board[row][col] -> pawn -> color != this -> color)
                result.push_back(board[row+1][col-2]);
        //gora-lewo
        if(row - 2 >= 0 and col - 1 >= 0)
            if(board[row][col] -> pawn -> color != this -> color)
                result.push_back(board[row-2][col-1]);
        //gora-prawo
        if(row - 2 >= 0 and col + 1 <= 0)
            if(board[row][col] -> pawn -> color != this -> color)
                result.push_back(board[row-2][col+1]);
        //prawo-gora
        if(row - 1 >= 0 and col + 2 <=8)
            if(board[row][col] -> pawn -> color != this -> color)
                result.push_back(board[row-1][col+2]);
        //prawo-dol
        if(row + 1 <= 8 and col + 2 <= 8)
            if(board[row][col] -> pawn -> color != this -> color)
                result.push_back(board[row+11][col+2]);
        //dol-prawo
        if(row + 2 <= 8 and col + 1 <= 8)
            if(board[row][col] -> pawn -> color != this -> color)
                result.push_back(board[row+2][col+1]);
        //dol-lewo
        if(row + 2 <= 8 and col - 1 >= 0)
            if(board[row][col] -> pawn -> color != this -> color)
                result.push_back(board[row+2][col-1]);
        return result;

    };
};

class Pawn: public Chess_Pawn {
public:
    int price = 10;
    std::vector<Field*> moves(int row, int col, Field *board[8][8]){
        std::vector <Field*> result;
        if(color == 'b'){
            if(row + 1 <= 8 and board[row+1][col] -> pawn != NULL )
                result.push_back(board[row+1][col]);
            if(row +1 <= 8 and col - 1 >= 0 and board[row+1][col-1] -> pawn -> color == 'w')
                result.push_back(board[row+1][col-1]);
            if(row +1 <= 8 and col + 1 <= 8 and board[row+1][col+1] -> pawn -> color == 'w')
                result.push_back(board[row+1][col+1]);
        }
        if(color == 'w'){
            if(row - 1 >= 0 and board[row-1][col] -> pawn != NULL )
                result.push_back(board[row-1][col]);
            if(row - 1 >= 0 and col - 1 >= 0 and board[row+1][col-1] -> pawn -> color == 'b')
                result.push_back(board[row-1][col-1]);
            if(row - 1 >= 0 and col + 1 <= 8 and board[row+1][col+1] -> pawn -> color == 'b')
                result.push_back(board[row-1][col+1]);
        }
        return result;
    };

};

class Queen: public Chess_Pawn {
public:
    int price = 10;

    vector<Field*> moves(int row, int col, Field *board[8][8]){
        int start_row = row;
        int start_col = col;
        vector <Field*> result;
        // sprawdzam ruch góra-lewo
        row--;
        col--;
        while((row >= 0 and col >= 0) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            row--;
            col--;
        }
        if((row >= 0 and col >= 0) and (board[row][col] -> pawn -> color != this -> color))
            result.push_back(board[row][col]);

        //ruch gora-prawo

        row = start_row -1;
        col = start_col +1;
        while((row >= 0 and col <= 8) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            row--;
            col++;
        }
        if((row >= 0 and col <= 8) and (board[row][col] -> pawn -> color != this -> color))
        result.push_back(board[row][col]);

        // dol-prawo
        row = start_row +1;
        col = start_col +1;
        while((row <= 8 and col <= 8) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            row++;
            col++;
        }
        if((row <= 8 and col <= 8) and (board[row][col] -> pawn -> color != this -> color))
        result.push_back(board[row][col]);
        //ruch dol-lewo
        row = start_row +1;
        col = start_col -1;
        while((row <= 8 and col <= 8) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            row++;
            col++;
        }
        if((row <= 8 and col <= 8) and (board[row][col] -> pawn -> color != this -> color))
            result.push_back(board[row][col]);

        start_row = row;
        start_col = col;

        //gora
        row--;
        while((row >= 0) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            row--;
        }
        if((row >=0) and (board[row][col] -> pawn -> color != this -> color))
            result.push_back(board[row][col]);

        //dol
        row = start_row +1;
        while((row <= 8) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            row++;
        }
        if((row <= 8) and (board[row][col] -> pawn -> color != this -> color))
            result.push_back(board[row][col]);

        //prawo
        row = start_row;
        col++;
        while((col <= 8) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            col++;
        }
        if((col <=8) and (board[row][col] -> pawn -> color != this -> color))
            result.push_back(board[row][col]);

        //lewo
        col = start_col -1;
        while((col >= 0) and board[row][col] -> pawn != NULL){
            result.push_back(board[row][col]);
            col--;
        }
        if((col >= 0) and (board[row][col] -> pawn -> color != this -> color))
            result.push_back(board[row][col]);

        return result;
    };

    class King: public Chess_Pawn {
    public:
        int price = 11;
        std::vector<Field*> moves(int row, int col, Field *board[8][8]){
            std::vector <Field*> result;
            if(row - 1 >= 0 and col - 1 >= 0 and board[row-1][col-1] -> pawn -> color != this -> color)
                result.push_back(board[row-1][col-1]);
            if(row - 1 >= 0 and board[row-1][col] -> pawn -> color != this -> color)
                result.push_back(board[row-1][col]);
            if(row - 1 >= 0 and col + 1 <= 8 and board[row-1][col+1] -> pawn -> color != this -> color)
                result.push_back(board[row-1][col+1]);
            if(col + 1 <= 8 and board[row][col+1] -> pawn -> color != this -> color)
                result.push_back(board[row][col+1]);
            if(row + 1 <= 8 and col + 1 <= 8 and board[row+1][col+1] -> pawn -> color != this -> color)
                result.push_back(board[row+1][col+1]);
            if(row + 1 <= 8 and board[row+1][col] -> pawn -> color != this -> color)
                result.push_back(board[row+1][col]);
            if(row + 1 >= 0 and col - 1 >= 0 and board[row+1][col-1] -> pawn -> color != this -> color)
                result.push_back(board[row+1][col-1]);
            if(col - 1 >= 0 and board[row][col-1] -> pawn -> color != this -> color)
                result.push_back(board[row][col-1]);
            return result;
        };
        vector<Field*> check;
    };
};
