#include "ofMain.h"
#include "ofApp.h"

//========================================================================
// VisualStudio の 構成プロパティ→リンカ→システム→サブシステム 設定で
//   Console(/SUBSYSTEM:CONSOLE) --> Windows (/SUBSYSTEM:WINDOWS) に変更して，
//      コマンドプロンプトが出ないようする．
//
//      上記にともない，エントリーポイントが，main() --> WinMain()になるのでその対応
//
//========================================================================
//int main(){
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
