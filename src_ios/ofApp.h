#pragma once

#include "ofxiOS.h"
#include "LifeGame.hpp"

class ofApp : public ofxiOSApp{
public:
    LifeGame::LifeGame<300,900> game;
    ofFbo fbo; // フレームバッファオブジェクト
    
    const int cellSize = 3;
    bool      flgSTOP = false;


    public:
        void setup();
        void update();
        void draw();
        void exit();
	
        void touchDown(ofTouchEventArgs & touch);
        void touchMoved(ofTouchEventArgs & touch);
        void touchUp(ofTouchEventArgs & touch);
        void touchDoubleTap(ofTouchEventArgs & touch);
        void touchCancelled(ofTouchEventArgs & touch);

        void lostFocus();
        void gotFocus();
        void gotMemoryWarning();
        void deviceOrientationChanged(int newOrientation);

    
    void InitLifeGame();
    void DrawBox(const int x, const int y);

};


