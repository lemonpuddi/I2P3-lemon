#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
double minimax_dfs1(State *,int , int ,double ,double);
class Minimax3{
public:
  static Move get_move(State *state, int depth);
};