#include "GameState.hpp"
#include <algorithm>

void GameState::AddPiece(string name, string type) {
  if (m.find(name) != m.end()) {
    m[name].push_back(type);  // if player exists
  } else {
    m.insert({name, vector<string>({type})});  // creates player
  }
}

void GameState::RemovePiece(string name, string type) {
  auto it = std::find(m[name].begin(), m[name].end(), type);
  m[name].erase(it);
}

int GameState::NumPieces(string name, string type) {
  int count = 0;
  if (name.empty() && type.empty()) {  // counts all pieces
    for (auto s : m) {
      count += static_cast<int>(s.second.size());
    }
  } else if (type.empty()) {  // counts players pieces
    count += static_cast<int>(m[name].size());
  } else if (name.empty()) {  // counts all of certain piece
    for (auto s : m) {
      count += std::count(s.second.begin(), s.second.end(), type);
    }
  } else {  // counts certain players certain pieces
    if (m.find(name) != m.end()) {
      count += std::count(m[name].begin(), m[name].end(), type);
    }
  }
  return count;
}