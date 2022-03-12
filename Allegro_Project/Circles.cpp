#include "Circles.hpp"
Circles::Circles()
{
}
void Circles::CreateCircles(int n){
    srand(time(0));
    for (int i = 0; i < n; i++) {
        circles.push_back(new Circle);
        circles[i]->Random(50, SCREEN_W-50, 50, SCREEN_H - 50,20,40,-3,3, 1, 3);
        if (i > 0) {
            for (int j = 0; j < i; j++) {
                if (i != j) {
                    if (circles[i]->Overlap(*circles[j])) {
                        circles[i]->Random(50, SCREEN_W - 50, 50, SCREEN_H - 50, 20, 40, -3, 3,1,2);
                        j = -1;
                    }
                }
            }
        }
        circles[i]->Normalise();
    }
}
void Circles::Move() {
    double r;
    double v;
    double tmp;
    for (int i = 0; i < circles.size(); i++) {
        v = circles[i]->GetV();
        circles[i]->IncCx(circles[i]->GetDx()*v);//set new position
        circles[i]->IncCy(circles[i]->GetDy()*v);//set new position
        r = circles[i]->GetR();
        if (circles[i]->GetCx() - r <= 0) {//if hit screen border
            if (circles[i]->GetDx() < 0) {
                circles[i]->SetDx(circles[i]->GetDx() * -1);
            }
        }
        if (circles[i]->GetCx() + r >= SCREEN_W) {//if hit screen border
            if (circles[i]->GetDx() > 0) {
                circles[i]->SetDx(circles[i]->GetDx() * -1);
            }
        }
        if (circles[i]->GetCy() - r <= 0) {//if hit screen border
            if (circles[i]->GetDy() < 0) {
                circles[i]->SetDy(circles[i]->GetDy() * -1);
            }
        }
        if (circles[i]->GetCy() + r >= SCREEN_H) {//if hit screen border
            if (circles[i]->GetDy() > 0) {
                circles[i]->SetDy(circles[i]->GetDy() * -1);
            }
        }
        /*
        if (circles[i]->GetCx() - r <= 0 || circles[i]->GetCx() + r >= SCREEN_W) {//if hit screen border
                circles[i]->SetDx(circles[i]->GetDx() * -1);

        }
        if (circles[i]->GetCy() - r <= 0 || circles[i]->GetCy() + r >= SCREEN_H) {//if hit screen border
                circles[i]->SetDy(circles[i]->GetDy() * -1);
        }
        */
        
        for (int j = 0; j < circles.size(); j++) {
            if (i != j) {
                if (circles[i]->Overlap(*circles[j])) {
                    /*
                    tmp = circles[j]->GetDx();
                    circles[j]->SetDx(circles[i]->GetDx());
                    circles[i]->SetDx(tmp);
                    tmp = circles[j]->GetDy();
                    circles[j]->SetDy(circles[i]->GetDy());
                    circles[i]->SetDy(tmp);
                    */
                    tmp = circles[i]->GetDx();
                    circles[i]->SetDx(circles[j]->GetDx() - tmp);
                    circles[j]->SetDx(tmp - circles[j]->GetDx());
                    tmp = circles[i]->GetDy();
                    circles[i]->SetDy(circles[j]->GetDy() - tmp);
                    circles[j]->SetDy(tmp - circles[j]->GetDy());
                    circles[i]->Normalise();
                    circles[i]->IncCx(circles[i]->GetDx() * v);//set new position
                    circles[i]->IncCy(circles[i]->GetDy() * v);//set new position
                }
            }
        }
        
    }
    
}

void Circles::Draw(){
    //ALLEGRO_FONT* font = al_load_ttf_font("Jaapokkienchance-Regular.otf", 10, NULL);
    for (int i = 0; i < circles.size(); i++) {
        al_draw_filled_circle(circles[i]->GetCx(),circles[i]->GetCy(),circles[i]->GetR(),circles[i]->color);
        //al_draw_multiline_textf(font, al_map_rgb(0, 255, 0), circles[i]->GetCx(), circles[i]->GetCy(), SCREEN_W, SCREEN_H, 1, "Cx: %f Cy: %f R: %f", circles[i]->GetCx(), circles[i]->GetCy(), circles[i]->GetR());
        //al_draw_multiline_textf(font, al_map_rgb(0, 255, 0), circles[i]->GetCx(), circles[i]->GetCy()-10, SCREEN_W, SCREEN_H, 1, "Dx: %f Dy: %f", circles[i]->GetDx(), circles[i]->GetDy());
    }
}