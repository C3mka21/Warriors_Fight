// Romashka

#include "TXLib.h"
#include "Player.h"
#include "BMap.h"
#include "Menu.h"
#include "Levels.h"
#include "MainFunctions.h"

int main(){
    txCreateWindow(1344, 640);
    txClear();
    Karta mp;
    Warrior wr(txLoadImage("WRW.bmp"), txLoadImage("WLW.bmp"), txLoadImage("WUpW.bmp"), txLoadImage("WDW.bmp"), txLoadImage("WRA01.bmp"), txLoadImage("WLA01.bmp"), txLoadImage("WUpA01.bmp"), txLoadImage("WDA01.bmp"), txLoadImage("WRH.bmp"), txLoadImage("WLH.bmp"), txLoadImage("WUpH.bmp"), txLoadImage("WDH.bmp"), txLoadImage("WDD.bmp"), 300, 300, 96, 96, 'D', 'A', 'W', 'S', VK_LSHIFT, VK_SPACE);
    Warrior cr(txLoadImage("MRW.bmp"), txLoadImage("MLW.bmp"), txLoadImage("MUpW.bmp"), txLoadImage("MDW.bmp"), txLoadImage("MRA01.bmp"), txLoadImage("MLA01.bmp"), txLoadImage("MUpA01.bmp"), txLoadImage("MDA01.bmp"), txLoadImage("MRH.bmp"), txLoadImage("MLH.bmp"), txLoadImage("MUpH.bmp"), txLoadImage("MDH.bmp"), txLoadImage("MDD.bmp"), 1010, 300, 96, 96, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, 'I', 'O');
menu:
    if(menu() == -1)
        return 0;
    int lvl = 1;
    wr.clear_deaths();
    cr.clear_deaths();
nextLevel:
    if(level_check(mp, wr, cr, lvl) == 1)
        goto menu;
    txBegin();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while(!GetAsyncKeyState(VK_ESCAPE)){
        txClear();
        mp.draw();
        cr.run();
        wr.run();
        cr.move_warrior();
        wr.move_warrior();
        collision(mp, wr);
        collision(mp, cr);
        if(wr.get_ycoord() >= cr.get_ycoord()){
            cr.draw(cr.get_naprav());
            wr.draw(wr.get_naprav());
        }
        else{
            wr.draw(wr.get_naprav());
            cr.draw(cr.get_naprav());
        }
        if((lvl + spikes_check(mp, wr, cr) == lvl + 1)||(lvl + attack(mp, wr, cr) == lvl + 1)){
            lvl++;
            goto nextLevel;
        }
        if((lvl + spikes_check(mp, cr, wr) == lvl + 1)||(lvl + attack(mp, cr, wr) == lvl + 1)){
            lvl++;
            goto nextLevel;
        }
        txSleep(60);
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    txEnd();
    return 0;
}


