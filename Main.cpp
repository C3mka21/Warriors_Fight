// Romashka

#include "TXLib.h"
#include "Player.h"
#include "BMap.h"
#include "MainFunctions.h"

int main(){
    txCreateWindow(1344, 640);
    txMessageBox("Õîäüáà - WASD\nÁåã - SHIFT + WASD\nÀòàêà - ÏÐÎÁÅË\nÄâîéíàÿ àòàêà - SHIFT + ÏÐÎÁÅË", "Óïðàâëåíèå", 0);
    txClear();
    Karta mp;
    Warrior wr(txLoadImage("WRW.bmp"), txLoadImage("WLW.bmp"), txLoadImage("WUpW.bmp"), txLoadImage("WDW.bmp"), txLoadImage("WRA01.bmp"), txLoadImage("WLA01.bmp"), txLoadImage("WUpA01.bmp"), txLoadImage("WDA01.bmp"), txLoadImage("WRH.bmp"), txLoadImage("WLH.bmp"), txLoadImage("WUpH.bmp"), txLoadImage("WDH.bmp"), txLoadImage("WDD.bmp"), 300, 300, 96, 96, 'D', 'A', 'W', 'S', VK_SHIFT, VK_SPACE);
    Warrior cr(txLoadImage("MRW.bmp"), txLoadImage("MLW.bmp"), txLoadImage("MUpW.bmp"), txLoadImage("MDW.bmp"), txLoadImage("MRA01.bmp"), txLoadImage("MLA01.bmp"), txLoadImage("MUpA01.bmp"), txLoadImage("MDA01.bmp"), txLoadImage("MRH.bmp"), txLoadImage("MLH.bmp"), txLoadImage("MUpH.bmp"), txLoadImage("MDH.bmp"), txLoadImage("MDD.bmp"), 1010, 300, 96, 96, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, 'V', 'H');
    txBegin();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while(!GetAsyncKeyState(VK_ESCAPE)){
        txClear();
        mp.draw();
        cr.run();
        wr.run();
        collision(mp, wr);
        collision(mp, cr);
        if(wr.get_ycoord() >= cr.get_ycoord()){
            cr.draw(cr.move_warrior());
            wr.draw(wr.move_warrior());
        }
        else{
            wr.draw(wr.move_warrior());
            cr.draw(cr.move_warrior());
        }
        attack(mp, wr, cr);
        attack(mp, cr, wr);
        if(wr.get_reload() < wr.get_reload1())
            wr.reload_changeP();
        if(cr.get_reload() < cr.get_reload1())
            cr.reload_changeP();
        txSleep(60);
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    txEnd();
    return 0;
}


