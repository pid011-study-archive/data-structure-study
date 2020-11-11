#include "util.h"
#include <Windows.h>

static int g_nScreenIndex;
static HANDLE g_hScreen[2];

void gotoxy(int x, int y) {
    COORD CursorPosition = { short(x), short(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void screen_init() {
    CONSOLE_CURSOR_INFO cci {};

    // 화면 버퍼 2개를 만든다.
    g_hScreen[0] = CreateConsoleScreenBuffer(
        GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    g_hScreen[1] = CreateConsoleScreenBuffer(
        GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    // 커서 숨기기
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(g_hScreen[0], &cci);
    SetConsoleCursorInfo(g_hScreen[1], &cci);
}

void screen_flipping() {
    SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
    g_nScreenIndex = g_nScreenIndex == 0 ? 1 : 0;
}

void screen_clear() {
    COORD Coor = { 0, 0 };
    DWORD dw;
    FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 25, Coor, &dw);
}

void screen_release() {
    CloseHandle(g_hScreen[0]);
    CloseHandle(g_hScreen[1]);
}

void screen_print(int x, int y, const char* str) {
    DWORD dw;
    COORD CursorPosition = { short(x * 2), short(y) };
    SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
    WriteFile(g_hScreen[g_nScreenIndex], str, strlen(str), &dw, nullptr);
}
// 1 ~ 15 까지 색상 설정 가능
void set_color(unsigned short color) {
    SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}
