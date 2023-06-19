#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
int minimax_dfs(State *,int , int ,int ,int);
class Minimax2{
public:
  static Move get_move(State *state, int depth);
};