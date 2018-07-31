#include<random>

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  //  600x400, 30 frames/sec
  ofSetWindowShape(900, 900);
  // 再生速度を1秒2フレームに設定（初期値は1秒60フレーム）
  ofSetFrameRate(15);
  //  set background
  ofSetBackgroundColor(0, 0, 0);

  // ランダムに Cell を配置
  InitLifeGame();

  //
  fbo.allocate(ofGetWidth(), ofGetHeight()); // フレームバッファオブジェクト
  
}


//--------------------------------------------------------------

// --------------------------------------------------
// ランダムに Cell を配置
// --------------------------------------------------
void ofApp::InitLifeGame(){
  static std::random_device rnd; 
  static std::mt19937 mt(rnd());

  LifeGame::Vec size;
  size = game.GetMatrixSize();

  for(int yy = 1; yy <= size.y; yy++){
    for(int xx = 1; xx <= size.x; xx++){

      if((mt() % 2) == 0) game.Set(LifeGame::Vec(xx, yy), true);
      else                game.Set(LifeGame::Vec(xx, yy), false);
    }
  }


}

// --------------------------------------------------
// 指定位置(x,y)へ，Box(4x4) 状に，Cell を配置
// --------------------------------------------------
void ofApp::DrawBox(const int x, const int y){
  int xx = x / cellSize + 1;
  int yy = y / cellSize + 1;

  for(int i = -2; i < 3; i++){
    for(int j = -2; j < 3; j++){
      game.On(LifeGame::Vec(i + xx, j + yy));
    }
  }
  }




//--------------------------------------------------------------
//--------------------------------------------------------------
void ofApp::update(){
  if( !flgSTOP ) game.Update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  LifeGame::Vec size = game.GetMatrixSize();

  ofSetColor(0, 200, 0);

  fbo.begin();  // フレームバッファオブジェクト開始 
                //  (MEMO) iOSで これを使うと，何故かうまくいかない．
  
  ofClear(0); // Clear

  //ofSetColor(0, 0, 0);
  //ofDrawRectangle(0, 0, ofGetWidth() - 1, ofGetHeight() - 1);
  ofSetColor(0, 255, 0);


  for(size_t y = 1; y <= size.y; y++){
    for(size_t x = 1; x <= size.x; x++){

      
      /**
      if(game.Get(LifeGame::Vec(x, y)))  ofSetColor(0, 200, 0);
      else                               ofSetColor(0, 0, 0);

      ofDrawRectangle(
        x * cellSize,
        y * cellSize,
        (x + 1) * cellSize,
        (y + 1) * cellSize);
      **/

      /**/
      if(game.Get(LifeGame::Vec(x, y))==true){
        ofDrawRectangle(
          x * cellSize,
          y * cellSize,
          cellSize,
          cellSize);
      }
      /**/

    }
  }
  fbo.end();// フレームバッファオブジェクト修了
  fbo.draw(0, 0, ofGetWidth(), ofGetHeight()); // Update

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  // --------------------------------------------------
  // If Any Key is pressed, Init LifeGame
  // --------------------------------------------------
  InitLifeGame();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  DrawBox(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  flgSTOP = true; // Stop Updating Game
  DrawBox(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  flgSTOP = false; // Restart Updating Game

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
