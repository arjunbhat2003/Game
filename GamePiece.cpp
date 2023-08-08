#include "GamePiece.hpp"
#include "GameState.hpp"

GamePiece::GamePiece(string name, string type, GameState* gs) {
  name_ = name;
  type_ = type;
  gs_ = gs;
  (*gs).AddPiece(name, type);  // helper in GS
}

GamePiece::GamePiece(const GamePiece& gp) {
  name_ = gp.name_;
  type_ = gp.type_;
  gs_ = gp.gs_;
  (*gs_).AddPiece(name_, type_);  // helper in GS
}

GamePiece::~GamePiece() {
  (*gs_).RemovePiece(name_, type_);  // helper in GS
}

string GamePiece::GetPlayer() { return name_; }

string GamePiece::GetType() { return type_; }

int GamePiece::GetPower() const {
  if (type_ == "Warrior") {
    return 5;
  } else if (type_ == "Scout") {
    return 1;
  } else if (type_ == "Wizard") {
    int num_wiz = (*gs_).NumPieces(name_, type_);
    return num_wiz;
  }
  return 0;  // else
}

int GamePiece::GetSpeed() const {
  if (type_ == "Warrior") {
    return 2;
  } else if (type_ == "Scout") {
    return 8;
  } else if (type_ == "Wizard") {
    int num_enemy_wiz =
        (*gs_).NumPieces("", type_) -
        (*gs_).NumPieces(name_,
                         type_);  // subtracts total wiz by wiz owned by player
    if (12 - num_enemy_wiz >= 1) {
      return 12 - num_enemy_wiz;
    } else {
      return 1;
    }
  }
  return 0;  // else
}

bool operator==(const GamePiece& gp1, const GamePiece& gp2) {
  if ((gp1.GetPower() == gp2.GetPower()) &&
      (gp1.GetSpeed() == gp2.GetSpeed())) {
    return true;
  }
  return false;
}

bool operator!=(const GamePiece& gp1, const GamePiece& gp2) {
  if ((gp1.GetPower() != gp2.GetPower()) ||
      (gp1.GetSpeed() != gp2.GetSpeed())) {
    return true;
  }
  return false;
}

bool operator<(const GamePiece& gp1, const GamePiece& gp2) {
  if (gp1.GetPower() < gp2.GetPower()) {
    return true;
  } else if (gp1.GetPower() == gp2.GetPower()) {
    if (gp1.GetSpeed() < gp2.GetSpeed()) {
      return true;
    }
  }
  return false;
}

bool operator>(const GamePiece& gp1, const GamePiece& gp2) {
  if (gp1.GetPower() > gp2.GetPower()) {
    return true;
  } else if (gp1.GetPower() == gp2.GetPower()) {
    if (gp1.GetSpeed() > gp2.GetSpeed()) {
      return true;
    }
  }
  return false;
}

bool operator<=(const GamePiece& gp1, const GamePiece& gp2) {
  if ((gp1 == gp2) || (gp1 < gp2)) {
    return true;
  }
  return false;
}

bool operator>=(const GamePiece& gp1, const GamePiece& gp2) {
  if ((gp1 == gp2) || (gp1 > gp2)) {
    return true;
  }
  return false;
}

void swap(GamePiece& gp1, GamePiece& gp2) {  // helper to use in assignment
  std::swap(gp1.name_, gp2.name_);
  std::swap(gp1.type_, gp2.type_);
  std::swap(gp1.gs_, gp2.gs_);
}

GamePiece& GamePiece::operator=(GamePiece other) {
  swap(*this, other);  // calls helper
  return *this;
}

std::ostream& operator<<(std::ostream& out, const GamePiece& gp) {
  out << "(" << gp.name_ << "," << gp.type_ << "," << gp.GetPower() << ","
      << gp.GetSpeed() << ")";
  return out;
}
