#include "ofMain.h"
#include "ofApp.h"

//========================================================================
// VisualStudio �� �\���v���p�e�B�������J���V�X�e�����T�u�V�X�e�� �ݒ��
//   Console(/SUBSYSTEM:CONSOLE) --> Windows (/SUBSYSTEM:WINDOWS) �ɕύX���āC
//      �R�}���h�v�����v�g���o�Ȃ��悤����D
//
//      ��L�ɂƂ��Ȃ��C�G���g���[�|�C���g���Cmain() --> WinMain()�ɂȂ�̂ł��̑Ή�
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
