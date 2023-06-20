#ifndef __STATE_H__
#define __STATE_H__

#include <string>
#include <cstdlib>
#include <vector>
#include <utility>

#include "../config.hpp"


typedef std::pair<size_t, size_t> Point;
typedef std::pair<Point, Point> Move;

class weight{
  public:
    double king[BOARD_H][BOARD_W] = {
      {-3, -4, -5, -4, -3},
      {-3, -4, -5, -4, -3},
      {-2, -3, -4, -3, -2},
      {-1, -1, -2, -2, -1},
      {1, 1, 0, 1, 1},
      {1, 2, 0, 2, 2},
    };
    double queen[BOARD_H][BOARD_W] = {
      {-2, -1, -0.5, -1, -2},
      {-1, 0, 0.5, 0, -1},
      {-0.5, 0, 0.5, 0, -0.5},
      {-0.5, 0, 0.5, 0, -0.5},
      {-1, 0, 0.5, 0, -1},
      {-2, -1, -0.5, -1, -2},
    };
    double rook[BOARD_H][BOARD_W] = {
      {0, 0, 0, 0, 0},
      {0.5, 1, 1, 1, 0.5},
      {-0.5, 0, 0, 0, -0.5},
      {-0.5, 0, 0, 0, -0.5},
      {0.5, 1, 1, 1, 0.5},
      {0, 0, 0, 0, 0},
    };
    double bishop[BOARD_H][BOARD_W] = {
      {-2, -1, -1, -1, -2},
      {-1, 0, 0, 0, -1},
      {-1, 0.5, 0.5, 0.5, -1},
      {-1, 0, 1, 0, -1},
      {-1, 0.5, 0, 0.5, -1},
      {-2, -1, -1, -1, -2},
    };
    double knight[BOARD_H][BOARD_W] = {
      {-3, -2, -1, -2, -3},
      {-1, 1, 1.5, 1, -1},
      {-1, 1.5, 2, 1.5, -1},
      {-1, 1.5, 2, 1.5, -1},
      {-1, 1, 1.5, 1, -1},
      {-3, -2, -1, -2, -3},
    };
    double pawn[BOARD_H][BOARD_W] = {
      {0, 0, 0, 0, 0},
      {5, 5, 5, 5, 5},
      {1.5, 2, 3, 2, 1.5},
      {1, 1.5, 2, 1.5, 1},
      {0.5, 1, -2, 1, 0.5},
      {0, 0, 0, 0, 0},
    };
};

class Board{
  public:
    char board[2][BOARD_H][BOARD_W] = {{
      //white
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1},
      {2, 3, 4, 5, 6},
    }, {
      //black
      {6, 5, 4, 3, 2},
      {1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    }};
};

enum GameState {
  UNKNOWN = 0,
  WIN,
  DRAW,
  NONE
};


class State{
  public:
    //You may want to add more property for a state
    GameState game_state = UNKNOWN;
    Board board;
    int player = 0;
    std::vector<Move> legal_actions;
    
    State(){};
    State(int player): player(player){};
    State(Board board): board(board){};
    State(Board board, int player): board(board), player(player){};
    
    double evaluate();
    State* next_state(Move move);
    void get_legal_actions();
    std::string encode_output();
    std::string encode_state();
};

class decis{
  public:
    int turn;
    Move next;
    std::vector<decis *> children;
  
    decis(){};
    decis(Move move){this->next = move;};
};

#endif