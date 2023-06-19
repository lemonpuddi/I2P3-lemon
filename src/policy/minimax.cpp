#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax.hpp"

/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Minimax::get_move(State *state, int depth){
  decis root;
  for (auto it:Construct_tree(state, 0, depth)){
    root.children.push_back(&it);
  }
  
}

std::vector<decis> Construct_tree(State *state, int turn, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  std::vector<decis> childrens;

  for (auto action: state->legal_actions){
    decis next(action);
    next.turn = turn;
    childrens.push_back(next);
    if (turn >= depth)continue;
    //State *next_state = State::next_state(action);
          Board next2 = state->board;
          Point from = action.first, to = action.second;
          
          int8_t moved = next2.board[state->player][from.first][from.second];
          //promotion for pawn
          if(moved == 1 && (to.first==BOARD_H-1 || to.first==0)){
            moved = 5;
          }
          if(next2.board[1-state->player][to.first][to.second]){
            next2.board[1-state->player][to.first][to.second] = 0;
          }
          
          next2.board[state->player][from.first][from.second] = 0;
          next2.board[state->player][to.first][to.second] = moved;
          
          State* next_state = new State(next2, 1-state->player);
          
          if(state->game_state != WIN)
            next_state->get_legal_actions();
    for (auto it:Construct_tree(next_state, turn+1, depth)){
      next.children.push_back(&it);
    }
  }
  return childrens;
}