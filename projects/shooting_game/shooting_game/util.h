#pragma once
#include <iostream>
using namespace std;

constexpr auto ENTER = 13;
constexpr auto LEFT = 75;
constexpr auto RIGHT = 77;
constexpr auto UP = 72;
constexpr auto DOWN = 80;
constexpr auto SPACE = 32;

void gotoxy(int x, int y);

// 화면 초기화 - 프로그램이 처음 시작될 때
void screen_init();

// 메모리 내용 고속복사
void screen_flipping();

// 화면 제거
void screen_clear();

// 해제 - 프로그램 종료 전에 처리
void screen_release();

// 화면 x, y 위치에 str을 메모리 버퍼에 저장
void screen_print(int x, int y, const char* str);

// 문자의 색깔을 지정 (설정)
void set_color(unsigned short color);
