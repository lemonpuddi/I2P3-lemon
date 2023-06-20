#include <cstdlib>
#include <iostream>
#include <fstream>

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
  State *next;
  std::ofstream log("debug.txt");
  std::cout << depth <<",";
  if(!state->legal_actions.size())
    state->get_legal_actions();
  for (auto action: state->legal_actions){
    next = state->next_state(action);
    int tmp = (int)minimax_dfs(next, 0, depth, -10000000, 10000000);
    std::cout << tmp << ",AA";
    if (tmp >= ans){
      ans = tmp;
      ans_move = action;
    }
  }
  std::cout << std::endl;
  return ans_move;
}

double minimax_dfs(State *state, int turn, int depth, double a, double b){
  if (turn == depth){
    for(int i = 0;i<turn;i++)std::cout << " ";
    double tmp = state->evaluate();
    std::cout << state->encode_state();
    std::cout << tmp <<" ,leaf node, " <<turn<<","<< depth << std::endl;
    return state->evaluate();
  } 
  std::cout << "dfs2 start" << ",turn " << turn;
  double ans = 0;
  std ::cout <<"________________________________________" << std::endl <<state->encode_state();
  if (!turn % 2) ans = 10000000;
  if(!state->legal_actions.size())
    state->get_legal_actions();
  for (auto action: state->legal_actions){
    State *next_state = state->next_state(action);
    if (!state->player){
      ans = std::max(ans, minimax_dfs(next_state, turn + 1, depth, a, b));
      a = std::max(a, ans);
      if (a >= b)break;
    }else{
      ans = std::min(ans, minimax_dfs(next_state, turn + 1, depth, a, b));
      b = std::min(b, ans);
      if (b <= a)break;
    }
   
  }
    for(int i = 0;i<turn;i++)std::cout << " ";
    std::cout << ans << std::endl;
  return ans;
}
