#include<random>

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  //  600x400, 30 frames/sec
  ofSetWindowShape(900, 900);
  // 再生速度を1秒2フレームに設定（初期値は1秒60フレーム）
  //ofSetFrameRate(20);
  //  set background
  ofSetBackgroundColor(0, 0, 0);


  // --------------------------------------------------
  // Initialize Cell Matrix
  // --------------------------------------------------
  std::random_device rnd;     // 非決定的な乱数生成器
  std::mt19937 mt(rnd());

  LifeGame::Vec size;
  size = game.GetMatrixSize();

  for(int yy = 1; yy <= size.y; yy++){
    for(int xx = 1; xx <= size.x; xx++){

      if((mt() % 2) == 0) game.Set(LifeGame::Vec(xx, yy), true);
      else                game.Set(LifeGame::Vec(xx, yy), false);
    }
  }


  fbo.allocate(ofGetWidth(), ofGetHeight()); // フレームバッファオブジェクト


}

//--------------------------------------------------------------
void ofApp::update(){
  game.Update();

}

//--------------------------------------------------------------
void ofApp::draw(){
  
  const int padding = 3;
  
  LifeGame::Vec size = game.GetMatrixSize();

  ofSetColor(0, 200, 0);

  fbo.begin();  // フレームバッファオブジェクト開始
  ofClear(0);

  //ofSetColor(0, 0, 0);
  //ofDrawRectangle(0, 0, ofGetWidth() - 1, ofGetHeight() - 1);
  ofSetColor(0, 255, 0);


  for(size_t y = 1; y <= size.y; y++){
    for(size_t x = 1; x <= size.x; x++){

      
      /**/
      if(game.Get(LifeGame::Vec(x, y)))  ofSetColor(0, 200, 0);
      else                               ofSetColor(0, 0, 0);

      ofDrawRectangle(
        x * padding,
        y * padding,
        (x + 1) * padding,
        (y + 1) * padding);
      /**/

      /**
      if(game.Get(LifeGame::Vec(x, y))==true){
        ofDrawRectangle(
          x * padding,
          y * padding,
          (x + 1) * padding,
          (y + 1) * padding);
      }
      **/

    }
  }
  fbo.end();// フレームバッファオブジェクト修了
  fbo.draw(0, 0, ofGetWidth(), ofGetHeight()); // Update

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
