#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
std::vector<decis> Construct_tree(State *state, int turn, int depth);
int minimax_dfs(State *, decis *,int ,int, int ,int);
class Minimax{
public:
  static Move get_move(State *state, int depth);
};