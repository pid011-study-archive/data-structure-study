#include "util.h"
#include <Windows.h>
#include <iostream>
#include <stdexcept>

static int g_nScreenIndex;
static HANDLE g_hScreen[2];

void gotoxy(int x, int y) {
    SHORT tx = static_cast<SHORT>(x);
    SHORT ty = static_cast<SHORT>(y);
    COORD CursorPosition = { tx, ty };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void ScreenInit() {
    CONSOLE_CURSOR_INFO cci;

    // 화면 버퍼 2개를 만든다.
    g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    // 커서 숨기기
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(g_hScreen[0], &cci);
    SetConsoleCursorInfo(g_hScreen[1], &cci);
}

void ScreenFlipping() {
    SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
    g_nScreenIndex = !g_nScreenIndex;
}

void ScreenClear() {
    COORD Coord = { 0, 0 };
    DWORD dw;
    FillConsoleOutputCharacterW(g_hScreen[g_nScreenIndex], L' ', 120 * 80, Coord, &dw);
    //     FillConsoleOutputCharacter( g_hScreen[g_nScreenIndex], ' ', 80*25, Coord, &dw );
}

void ScreenRelease() {
    CloseHandle(g_hScreen[0]);
    CloseHandle(g_hScreen[1]);
}

void ScreenPrint(int x, int y, const wchar_t* string) {
    DWORD dw;
    SHORT tx = static_cast<SHORT>(x);
    SHORT ty = static_cast<SHORT>(y);
    COORD CursorPosition = { tx * 2, ty };
    bool bOK;
    try {
        bOK = WriteConsoleOutputCharacterW(g_hScreen[g_nScreenIndex], string, wcslen(string), CursorPosition, &dw);
        if (bOK == false)
            throw std::runtime_error("Runtime error");
    } catch (std::runtime_error& e) {
        std::cout << "예외발생 : " << e.what() << std::endl;
        // nothing
    }
}
// 0 ~ 15 까지 색상 설정 가능
void SetColor(unsigned short color) {
    SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}
