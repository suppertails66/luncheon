#include "logic/GameObject.h"
#include "logic/GameScene.h"
#include <iostream>

namespace Luncheon {


GameObject::~GameObject() { };

GameObject::GameObject(GameMemory& gameMemory__,
                       GameScene& parent__)
  : gameMemory_(gameMemory__),
    parent_(parent__),
//    drawX_(0),
//    drawY_(0),
    hidden_(false),
    dead_(false) { };
  
GameObjectID GameObject::objectID() {
  return -1;
}
  
/*int GameObject::drawX() {
  return drawX_;
}

void GameObject::setDrawX(int drawX__) {
  drawX_ = drawX__;
}

int GameObject::drawY() {
  return drawY_;
}

void GameObject::setDrawY(int drawY__) {
  drawY_ = drawY__;
} */
  
void GameObject::die() {
  dead_ = true;
}

bool GameObject::dead() {
  return dead_;
}
  
void GameObject::update(GTick ticks) {
  updateSelf(ticks);
}
  
void GameObject::draw(ScreenBuffer& buffer) {
  draw(buffer, 0, 0);
/*  if (hidden_) {
    return;
  }
  
  drawSelf(buffer); */
}
  
void GameObject::draw(ScreenBuffer& buffer,
                  int drawX,
                  int drawY) {
  if (hidden_) {
    return;
  }
  
  drawSelf(buffer,
           drawX,
           drawY);
}
  
void GameObject::drawSelf(ScreenBuffer& buffer) {
  drawSelf(buffer,
           0,
           0);
}
  
bool GameObject::hidden() {
  return hidden_;
}

void GameObject::setHidden(bool hidden__) {
  hidden_ = hidden__;
}
  
GameObjectManager& GameObject::children() {
  return children_;
}
  
GameObjectManager& GameObject::subChildren() {
  return subChildren_;
}


}; 
