#include "logic/GameScene.h"
#include <iostream>

namespace Luncheon {


GameScene::~GameScene() {
  delete child_;
}

GameScene::GameScene(GameMemory& gameMemory__)
  : gameMemory_(gameMemory__),
    parent_(0),
    child_(0),
    hasFocus_(true),
    needsDestruction_(false) { };
  
GameObjectManager& GameScene::objectManager() {
  return objectManager_;
}
  
bool GameScene::hasFocus() {
  return hasFocus_;
}

void GameScene::setHasFocus(bool hasFocus__) {
  hasFocus_ = hasFocus__;
}
  
bool GameScene::needsDestruction() {
  return needsDestruction_;
}

void GameScene::setNeedsDestruction(bool needsDestruction__) {
  needsDestruction_ = needsDestruction__;
}
  
bool GameScene::hasParent() {
  return (parent_ != 0);
}
  
bool GameScene::hasChild() {
  return (child_ != 0);
}
  
GameScene& GameScene::parent() {
  return *parent_;
}

GameScene& GameScene::child() {
  return *child_;
}
  
void GameScene::setParent(GameScene* parent__) {
  parent_ = parent__;
}
  
void GameScene::changeChild(GameScene* child__) {
  // Get rid of any existing child
  destroyChild();
  
  child_ = child__;
  child_->setParent(this);
  
  // Give focus to new child
  hasFocus_ = false;
  child_->setHasFocus(true);
}
  
void GameScene::destroyChild() {
  if (child_ == 0) {
    return;
  }
  
  // Retrieve the focus from the child
  if (child_->hasFocus()) {
    hasFocus_ = true;
  }
  
  delete child_;
  child_ = 0;
}


}; 
