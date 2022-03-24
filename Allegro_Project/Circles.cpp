#include "Circles.hpp"
Circles::Circles()
{
}
void Circles::CreateCircles(int n){
    srand(time(0));
    for (int i = 0; i < n; i++) {
        circles.push_back(new Circle);
        circles[i]->Random(50, SCREEN_W-50, 50, SCREEN_H - 50,1,3,-3,3, 1, 3);
        if (i > 0) {
            for (int j = 0; j < i; j++) {
                if (i != j) {
                    if (circles[i]->Overlap(*circles[j])) {
                        circles[i]->Random(50, SCREEN_W - 50, 50, SCREEN_H - 50, 1, 3, -3, 3,1,2);
                        j = -1;
                    }
                }
            }
        }
        circles[i]->Normalise();
    }
}
void Circles::Move() {
    double r,v;
    double tmp;
    //double v1, v2;
    double d, nx, ny, p;
    double midx, midy;
    double tmpdx, tmpdy;
    // TODO: fix move
    /*
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
        
        
        for (int j = 0; j < circles.size(); j++) {
            if (i != j) {
                if (circles[i]->Overlap(*circles[j])) {
                    /*
                    //tmp = circles[j]->GetDx();
                    //circles[j]->SetDx(circles[i]->GetDx());
                    //circles[i]->SetDx(tmp);
                    //tmp = circles[j]->GetDy();
                    //circles[j]->SetDy(circles[i]->GetDy());
                    //circles[i]->SetDy(tmp);

                    v1 = circles[i]->GetV();
                    v2 = circles[j]->GetV();
                    tmp = circles[i]->GetDx()*v1;
                    circles[i]->SetDx(circles[j]->GetDx()*v2 + tmp);
                    circles[j]->SetDx(tmp - circles[j]->GetDx()*v2);
                    tmp = circles[i]->GetDy()*v1;
                    circles[i]->SetDy(circles[j]->GetDy()*v2 + tmp);
                    circles[j]->SetDy(tmp - circles[j]->GetDy()*v2);
                    circles[i]->Normalise();
                    circles[j]->Normalise();
                    


                    d = std::sqrt((circles[i]->GetCx() - circles[j]->GetCx())*(circles[i]->GetCx() - circles[j]->GetCx()) + (circles[i]->GetCy() - circles[j]->GetCy())*(circles[i]->GetCy() - circles[j]->GetCy()));
                    nx = (circles[j]->GetCx() - circles[i]->GetCx()) / d;
                    ny = (circles[j]->GetCy() - circles[i]->GetCy()) / d;
                    p = 2 * (circles[i]->GetDx() * nx + circles[i]->GetDy() * ny - circles[j]->GetDx() * nx - circles[j]->GetDy() * ny) / (circles[i]->GetM() + circles[j]->GetM());
                    circles[i]->SetDx(circles[i]->GetDx() - p * circles[i]->GetM() * nx);
                    circles[i]->SetDy(circles[i]->GetDy() - p * circles[i]->GetM() * ny);
                    circles[j]->SetDx(circles[j]->GetDx() + p * circles[j]->GetM() * nx);
                    circles[j]->SetDy(circles[j]->GetDy() + p * circles[j]->GetM() * ny);
                    circles[i]->Normalise();
                    circles[j]->Normalise();

                    //printf("dx: %f dy: %f d: %f, v: %f\n",circles[i]->GetDx(),circles[i]->GetDy(),sqrt(circles[i]->GetDx()* circles[i]->GetDx()+circles[i]->GetDy()* circles[i]->GetDy()),circles[i]->GetV() );

                    
                    /*
                    midx = (circles[i]->GetCx() + circles[j]->GetCx()) / 2;                                               //no
                    midy = (circles[i]->GetCy() + circles[j]->GetCy()) / 2;                                               //no
                    circles[i]->SetCx((midx + circles[i]->GetR() * (circles[i]->GetCx() - circles[j]->GetCx()) / d));   //no
                    circles[i]->SetCy((midy + circles[i]->GetR() * (circles[i]->GetCy() - circles[j]->GetCy()) / d));   //no
                    circles[j]->SetCx((midx + circles[j]->GetR() * (circles[j]->GetCx() - circles[i]->GetCx()) / d));   //no
                    circles[j]->SetCy((midy + circles[i]->GetR() * (circles[j]->GetCy() - circles[i]->GetCy()) / d));   //no
                    

                    /*
                    v1 = circles[i]->GetV();
                    v2 = circles[j]->GetV();
                    circles[i]->IncCx(circles[i]->GetDx() * v1);//set new position
                    circles[i]->IncCy(circles[i]->GetDy() * v1);//set new position
                    circles[j]->IncCx(circles[j]->GetDx() * v2);//set new position
                    circles[j]->IncCy(circles[j]->GetDy() * v2);//set new position
                    
                }
            }
        }
    }
    */

    double step = 0.05;

    for (int i = 0; i < circles.size(); i++) {

        v = circles[i]->GetV();
        for (double vi = 0.0; vi <= v; vi += step){     //dont think this is the right way to do it
            circles[i]->IncCx(circles[i]->GetDx() * step);//set new position
            circles[i]->IncCy(circles[i]->GetDy() * step);//set new position
            tmpdx = circles[i]->GetDx();
            tmpdy = circles[i]->GetDy();

            for (int j = 0; j < circles.size(); j++) {
                if (i != j) {
                    if (circles[i]->Overlap(*circles[j])) {

                        d = std::sqrt((circles[i]->GetCx() - circles[j]->GetCx()) * (circles[i]->GetCx() - circles[j]->GetCx()) + (circles[i]->GetCy() - circles[j]->GetCy()) * (circles[i]->GetCy() - circles[j]->GetCy()));
                        nx = (circles[j]->GetCx() - circles[i]->GetCx()) / d;
                        ny = (circles[j]->GetCy() - circles[i]->GetCy()) / d;
                        p = 2 * (circles[i]->GetDx() * nx + circles[i]->GetDy() * ny - circles[j]->GetDx() * nx - circles[j]->GetDy() * ny) / (circles[i]->GetM() + circles[j]->GetM());
                        circles[i]->SetDx(circles[i]->GetDx() - p * circles[i]->GetM() * nx);
                        circles[i]->SetDy(circles[i]->GetDy() - p * circles[i]->GetM() * ny);
                        circles[j]->SetDx(circles[j]->GetDx() + p * circles[j]->GetM() * nx);
                        circles[j]->SetDy(circles[j]->GetDy() + p * circles[j]->GetM() * ny);
                        circles[i]->Normalise();
                        circles[j]->Normalise();

                        circles[i]->IncCx(-tmpdx * step*2);//set new position
                        circles[i]->IncCy(-tmpdy * step*2);//its... its... not good... i think
                    }
                }
            }
        }

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
        */

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
                    //tmp = circles[j]->GetDx();
                    //circles[j]->SetDx(circles[i]->GetDx());
                    //circles[i]->SetDx(tmp);
                    //tmp = circles[j]->GetDy();
                    //circles[j]->SetDy(circles[i]->GetDy());
                    //circles[i]->SetDy(tmp);

                    v1 = circles[i]->GetV();
                    v2 = circles[j]->GetV();
                    tmp = circles[i]->GetDx()*v1;
                    circles[i]->SetDx(circles[j]->GetDx()*v2 + tmp);
                    circles[j]->SetDx(tmp - circles[j]->GetDx()*v2);
                    tmp = circles[i]->GetDy()*v1;
                    circles[i]->SetDy(circles[j]->GetDy()*v2 + tmp);
                    circles[j]->SetDy(tmp - circles[j]->GetDy()*v2);
                    circles[i]->Normalise();
                    circles[j]->Normalise();
                    */


                    d = std::sqrt((circles[i]->GetCx() - circles[j]->GetCx())*(circles[i]->GetCx() - circles[j]->GetCx()) + (circles[i]->GetCy() - circles[j]->GetCy())*(circles[i]->GetCy() - circles[j]->GetCy()));
                    nx = (circles[j]->GetCx() - circles[i]->GetCx()) / d;
                    ny = (circles[j]->GetCy() - circles[i]->GetCy()) / d;
                    p = 2 * (circles[i]->GetDx() * nx + circles[i]->GetDy() * ny - circles[j]->GetDx() * nx - circles[j]->GetDy() * ny) / (circles[i]->GetM() + circles[j]->GetM());
                    circles[i]->SetDx(circles[i]->GetDx() - p * circles[i]->GetM() * nx);
                    circles[i]->SetDy(circles[i]->GetDy() - p * circles[i]->GetM() * ny);
                    circles[j]->SetDx(circles[j]->GetDx() + p * circles[j]->GetM() * nx);
                    circles[j]->SetDy(circles[j]->GetDy() + p * circles[j]->GetM() * ny);
                    circles[i]->Normalise();
                    circles[j]->Normalise();

                    //printf("dx: %f dy: %f d: %f, v: %f\n",circles[i]->GetDx(),circles[i]->GetDy(),sqrt(circles[i]->GetDx()* circles[i]->GetDx()+circles[i]->GetDy()* circles[i]->GetDy()),circles[i]->GetV() );


                    /*
                    midx = (circles[i]->GetCx() + circles[j]->GetCx()) / 2;                                               //no
                    midy = (circles[i]->GetCy() + circles[j]->GetCy()) / 2;                                               //no
                    circles[i]->SetCx((midx + circles[i]->GetR() * (circles[i]->GetCx() - circles[j]->GetCx()) / d));   //no
                    circles[i]->SetCy((midy + circles[i]->GetR() * (circles[i]->GetCy() - circles[j]->GetCy()) / d));   //no
                    circles[j]->SetCx((midx + circles[j]->GetR() * (circles[j]->GetCx() - circles[i]->GetCx()) / d));   //no
                    circles[j]->SetCy((midy + circles[i]->GetR() * (circles[j]->GetCy() - circles[i]->GetCy()) / d));   //no
                    */

                    /*
                    v1 = circles[i]->GetV();
                    v2 = circles[j]->GetV();
                    circles[i]->IncCx(circles[i]->GetDx() * v1);//set new position
                    circles[i]->IncCy(circles[i]->GetDy() * v1);//set new position
                    circles[j]->IncCx(circles[j]->GetDx() * v2);//set new position
                    circles[j]->IncCy(circles[j]->GetDy() * v2);//set new position
                    */
                }
            }
        }
    }

}

void Circles::Draw(){
    //ALLEGRO_FONT* font = al_load_ttf_font("Jaapokkienchance-Regular.otf", 10, NULL);
    for (int i = 0; i < circles.size(); i++) {
        //circles[i]->color = al_map_rgb(rand() % 256, rand() % 256, rand() % 256);
        al_draw_filled_circle(circles[i]->GetCx(),circles[i]->GetCy(),circles[i]->GetR(),circles[i]->color);
        //al_draw_multiline_textf(font, al_map_rgb(0, 255, 0), circles[i]->GetCx(), circles[i]->GetCy(), SCREEN_W, SCREEN_H, 1, "Cx: %f Cy: %f R: %f", circles[i]->GetCx(), circles[i]->GetCy(), circles[i]->GetR());
        //al_draw_multiline_textf(font, al_map_rgb(0, 255, 0), circles[i]->GetCx(), circles[i]->GetCy()-10, SCREEN_W, SCREEN_H, 1, "Dx: %f Dy: %f", circles[i]->GetDx(), circles[i]->GetDy());
    }
}