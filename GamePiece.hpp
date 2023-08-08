#pragma once
#include "GameState.hpp"
#include <string>
#include <iostream>
using std::string;
class GamePiece {
 private:
  string name_;
  string type_;
  GameState* gs_;

 public:
  GamePiece(string name, string type, GameState* gs);
  GamePiece(const GamePiece& gp);
  ~GamePiece();
  string GetPlayer();
  string GetType();
  int GetPower() const;
  int GetSpeed() const;
  friend bool operator==(const GamePiece& gp1, const GamePiece& gp2);
  friend bool operator!=(const GamePiece& gp1, const GamePiece& gp2);
  friend bool operator<(const GamePiece& gp1, const GamePiece& gp2);
  friend bool operator>(const GamePiece& gp1, const GamePiece& gp2);
  friend bool operator<=(const GamePiece& gp1, const GamePiece& gp2);
  friend bool operator>=(const GamePiece& gp1, const GamePiece& gp2);
  friend void swap(GamePiece& gp1, GamePiece& gp2);  // helper
  GamePiece& operator=(GamePiece other);
  friend std::ostream& operator<<(std::ostream& out, const GamePiece& gp);
};