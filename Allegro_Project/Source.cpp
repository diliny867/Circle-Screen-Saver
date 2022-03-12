#include <iostream>
#include <windows.h>
#include <cstdlib>
#include "AllegroBase.hpp"
#include "Figure.hpp"
#include "Rect.hpp"
#include "Circle.hpp"
#include "Circles.hpp"
using namespace std;


Circles circles;
class AllegroApp :public AllegroBase {
    virtual void Fps() {
        circles.Move();
    }
    virtual void Draw() {
        circles.Draw();
    }
    virtual void OnKeyDown(const ALLEGRO_KEYBOARD_EVENT& keyboard) {
        
    }
    virtual void OnKeyUp(const ALLEGRO_KEYBOARD_EVENT& keyboard) {
        
    }
    virtual void Run() {
        ALLEGRO_EVENT ev;
        al_start_timer(alTimer_);
        circles.CreateCircles(10);
        bool redraw = false;
        while (true) {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_wait_for_event(alEventQueue_, &ev);
            if (ev.type == ALLEGRO_EVENT_TIMER) {
                if (ev.timer.source == alTimer_) {
                    Fps();
                    redraw = true;
                }
            }
            else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                break;
            }
            else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                OnKeyDown(ev.keyboard);
                pressedKeys_[ev.keyboard.keycode] = true;
            }
            else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
                OnKeyUp(ev.keyboard);
                pressedKeys_[ev.keyboard.keycode] = false;
            }
            if (redraw && al_is_event_queue_empty(alEventQueue_)) {
                redraw = false;
                Draw();
                al_flip_display();
            }
            if (exit_) {
                break;
            }
        }
    }
};

int main(int argc, char** argv) {
    srand(time(0));
    AllegroApp  allegro;
    AllegroBase& AllegroMain = allegro;
    if (!AllegroMain.Init(SCREEN_W, SCREEN_H, FPS))
    {
        AllegroMain.Destroy();
        return 1;
    }
    AllegroMain.Run();
    AllegroMain.Destroy();
    return 0;
}