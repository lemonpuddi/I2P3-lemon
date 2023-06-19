#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax2.hpp"

/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Minimax2::get_move(State *state, int depth){
  decis root;
  int ans = 0;
  Move ans_move;
  State next;
  if(!state->legal_actions.size())
    state->get_legal_actions();
  for (auto action: state->legal_actions){
    next = *state->next_state(action);
    int tmp = minimax_dfs(state, 0, depth, -10000000, 10000000);
    if (tmp > ans){
      ans = tmp;
      ans_move = action;
    }
  }
  return ans_move;
}

int minimax_dfs(State *state, int turn, int depth, int a, int b){
  if (turn == depth){
    return state->evaluate();
  } 
  int ans = 0;
  if (!turn % 2) ans = 10000000;
  if(!state->legal_actions.size())
    state->get_legal_actions();
  for (auto action: state->legal_actions){
    State *next_state = state->next_state(action);
    if (turn % 2){
      ans = std::max(ans, minimax_dfs(next_state, turn + 1, depth, a, b));
      a = std::max(a, ans);
      if (a >= b)break;
    }else{
      ans = std::min(ans, minimax_dfs(next_state, turn + 1, depth, a, b));
      b = std::min(b, ans);
      if (b <= a)break;
    }
   
  }
  return ans;
}
