#pragma once
#include <map>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::map;

class GameState {
 public:
  map<string, vector<string>> m;
  void AddPiece(string name, string type);     // helper
  void RemovePiece(string name, string type);  // helper
  int NumPieces(string name = "", string type = "");
};