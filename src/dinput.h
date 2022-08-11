#ifndef DINPUT_H
#define DINPUT_H

#include <SDL.h>

typedef struct MouseData {
    int x;
    int y;
    unsigned char buttons[2];
    int wheelX;
    int wheelY;
} MouseData;

typedef struct KeyboardData {
    int key;
    char down;
} KeyboardData;

bool directInputInit();
void directInputFree();
bool mouseDeviceAcquire();
bool mouseDeviceUnacquire();
bool mouseDeviceGetData(MouseData* mouseData);
bool keyboardDeviceAcquire();
bool keyboardDeviceUnacquire();
bool keyboardDeviceReset();
bool keyboardDeviceGetData(KeyboardData* keyboardData);
bool mouseDeviceInit();
void mouseDeviceFree();
bool keyboardDeviceInit();
void keyboardDeviceFree();

void handleTouchFingerEvent(SDL_TouchFingerEvent* event);
void handleMouseWheelEvent(SDL_MouseWheelEvent* event);

#ifdef __vita__
enum TouchpadMode
{
    TOUCH_DISABLED = 0,
    TOUCH_DIRECT = 1,
    TOUCH_TRACKPAD = 2
};

void handleTouchEventDirect(const SDL_TouchFingerEvent& event);
#endif

#endif /* DINPUT_H */
