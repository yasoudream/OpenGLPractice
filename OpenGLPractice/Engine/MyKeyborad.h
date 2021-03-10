#pragma once
#ifndef __MY_KEYBOARD_H__
#define __MY_KEYBOARD_H__

class MyKeyboard
{
public:
	MyKeyboard();
	virtual ~MyKeyboard();

	//Ä¬ÈÏ·½·¨
	MyKeyboard(MyKeyboard const&) = delete;
	MyKeyboard& operator=(MyKeyboard const&) = delete;


private:

};



#endif // !__MY_KEYBOARD_H__
