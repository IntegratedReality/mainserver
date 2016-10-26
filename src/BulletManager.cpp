#include "BulletManager.h"
#include "Const.h"
#include <cmath>
#include <iostream>

using namespace std;

void BulletManager::init() {
  BulletManager::bullets.clear();
}

void BulletManager::update() {
  for (auto& e:bullets) {
    e->update();
  }
  
  //remove-eraseイディオム
  //http://faithandbrave.hateblo.jp/entry/20111020/1319093073
  bullets.erase(std::remove_if
                (bullets.begin(),
                 bullets.end(),
                 [](unique_ptr<Bullet>& b){
                   return b->getDeleteFlag();
                 }
                 ),
                bullets.end());
}

void BulletManager::draw() {
  for(auto& e: bullets){
    e->draw();
  }
}

std::vector<unique_ptr<Bullet>> BulletManager::bullets;

std::vector<Position> BulletManager::getPositionsVec(){
  std::vector<Position> vec;
  vec.reserve(bullets.size());
  for(auto& e:bullets){
    vec.emplace_back(e->getPosition()); //unique_ptr化
  }
  return vec;
}

void BulletManager::makeBullet(Position _pos, ETeam _team, bool _deathshot) {
  Bullet *bullet = new Bullet();
  _pos.x += (RADIUS_OF_POINT_OBJ + 10) * cos(_pos.theta);
  _pos.y += (RADIUS_OF_POINT_OBJ + 10) * sin(_pos.theta);
  bullet->init(_pos, _team, _deathshot);
  BulletManager::bullets.emplace_back(bullet);
}
