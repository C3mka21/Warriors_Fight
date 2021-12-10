//Romashka

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

int level_check(Karta &mp, Warrior &wr, Warrior &cr, int lvl);
void collision(Karta &mp, Warrior &wr);
int spikes_check(Karta &mp, Warrior &wr, Warrior &cr);
int spikes_hurt(Karta &mp, Warrior &wr, Warrior &cr);
int attack(Karta &mp, Warrior &wr, Warrior &cr);
void attack_draw(Karta &mp, Warrior &wr, Warrior &cr);
void attack_check(Karta &mp, Warrior &wr, Warrior &cr, int i);
void death(Karta &mp, Warrior &wr, Warrior &cr);
void game_over(Warrior &wr);

int level_check(Karta &mp, Warrior &wr, Warrior &cr, int lvl){
    if(lvl == 1)
        level1(mp, wr, cr);
    if(lvl == 2)
        level2(mp, wr, cr);
    if(lvl == 3)
        level3(mp, wr, cr);
    if(lvl == 4){
        txSleep(500);
        if(wr.get_deaths() > cr.get_deaths())
            game_over(wr);
        else
            game_over(cr);
        return 1;
    }
    return 0;
}

void collision(Karta &mp, Warrior &wr){
    if((mp.get_cell(int(wr.get_ycoord() + wr.get_height()/1.25), int(wr.get_xcoord() + wr.get_width()/3)) > 2) && (mp.get_cell(int(wr.get_ycoord() + wr.get_height()/1.25), int(wr.get_xcoord() + wr.get_width()/3)) < 16)){
        wr.stop();
        return;
    }
    if((mp.get_cell(int(wr.get_ycoord() + wr.get_height()/1.25), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/3)) > 2) && (mp.get_cell(int(wr.get_ycoord() + wr.get_height()/1.25), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/3)) < 16)){
        wr.stop();
        return;
    }
    if((mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/3)) > 2) && (mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/3)) < 16)){
        wr.stop();
        return;
    }
    if((mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6), int(wr.get_xcoord() + wr.get_width()/3)) > 2) && (mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6), int(wr.get_xcoord() + wr.get_width()/3)) < 16)){
        wr.stop();
        return;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int spikes_check(Karta &mp, Warrior &wr, Warrior &cr){
    int type1 = 18, type2 = 21, type1_1 = 17, type2_1 = 20;
    if(((mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6.5), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/2)) == type1) || (mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6.5), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/2)) == type2)) && (wr.get_Sreload() >= wr.get_Sreload1())){
        if(spikes_hurt(mp, wr, cr) == 1)
            return 1;
        return 0;
    }
    if(((mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6.5), int(wr.get_xcoord() + wr.get_width()/2)) == type1) || (mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6.5), int(wr.get_xcoord() + wr.get_width()/2)) == type2)) && (wr.get_Sreload() >= wr.get_Sreload1())){
        if(spikes_hurt(mp, wr, cr) == 1)
            return 1;
        return 0;
    }
    if(mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6.5), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/2)) == type1_1){
        mp.pers_set_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6.5), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/2), type1);
    }
    else if(mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6.5), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/2)) == type2_1){
        mp.pers_set_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6.5), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/2), type2);
    }
    if(mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6.5), int(wr.get_xcoord() + wr.get_width()/2)) == type1_1){
        mp.pers_set_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6.5), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/2), type1);
    }
    else if(mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6.5), int(wr.get_xcoord() + wr.get_width()/2)) == type2_1){
        mp.pers_set_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6.5), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/2), type2);
    }
    wr.Sreload_changeP();
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int spikes_hurt(Karta &mp, Warrior &wr, Warrior &cr){
    for(int i=0; i<4; i++){
        txClear();
        mp.draw();
        if(wr.get_ycoord() >= cr.get_ycoord()){
            cr.run();
            cr.move_warrior();
            collision(mp, cr);
            cr.draw(cr.get_naprav());
            wr.hurt(i);
        }
        else{
            wr.hurt(i);
            cr.run();
            cr.move_warrior();
            collision(mp, cr);
            cr.draw(cr.get_naprav());
        }
        txSleep(60);
    }
    wr.Sreload_changeAH();
    wr.newhp();
    if(wr.get_hp() <= 0){
        death(mp, cr, wr);
        return 1;
    }
    return 0;
}

int attack(Karta &mp, Warrior &wr, Warrior &cr){
    if(wr.get_reload() < wr.get_reload1())
            wr.reload_changeP();
    if(GetAsyncKeyState(wr.get_attack1key()) && wr.get_reload() >= wr.get_reload1()){
        if(GetAsyncKeyState(wr.get_runkey())){
            attack_draw(mp, wr, cr);
            cr.newhp();
            if(cr.get_hp() <= 0){
                death(mp, wr, cr);
                return 1;
            }
        }
        attack_draw(mp, wr, cr);
        cr.newhp();
        if(cr.get_hp() <= 0){
            death(mp, wr, cr);
            return 1;
        }
    }
    return 0;
}

void attack_draw(Karta &mp, Warrior &wr, Warrior &cr){
    for(int i=0; i<6; i++){
        txClear();
        mp.draw();
        if(wr.get_Yhitbox() >= cr.get_Yhitbox()){
            /////////////////////////////////////////////////////////////////////////////////
            attack_check(mp, wr, cr, i);
            /////////////////////////////////////////////////////////////////////////////////
            wr.attack(i);
        }
        else{
            wr.attack(i);
            /////////////////////////////////////////////////////////////////////////////////
            attack_check(mp, wr, cr, i);
            /////////////////////////////////////////////////////////////////////////////////
        }
        txSleep(50);
    }
    wr.reload_changeAA();
}

void attack_check(Karta &mp, Warrior &wr, Warrior &cr, int i){
    if((wr.get_xAcoord() > cr.get_Xhitbox()) && (wr.get_xAcoord() - cr.get_Xhitbox() < cr.get_Whitbox()) && (i >= 2)){
        if((wr.get_yAcoord() > cr.get_Yhitbox()) && (wr.get_yAcoord() - cr.get_Yhitbox() < cr.get_Hhitbox())){
            cr.hurt(i-2);
            return;
        }
        else if((wr.get_yAcoord() < cr.get_Yhitbox()) && (cr.get_Yhitbox() - wr.get_yAcoord() < wr.get_height())){
            cr.hurt(i-2);
            return;
        }
    }
    else if((wr.get_xAcoord() < cr.get_Xhitbox()) && (cr.get_Xhitbox() - wr.get_xAcoord() < wr.get_width()) && (i>=2)){
        if((wr.get_yAcoord() > cr.get_Yhitbox()) && (wr.get_yAcoord() - cr.get_Yhitbox() < cr.get_Hhitbox())){
            cr.hurt(i-2);
            return;
        }
        else if((wr.get_yAcoord() < cr.get_Yhitbox()) && (cr.get_Yhitbox() - wr.get_yAcoord() < wr.get_height())){
            cr.hurt(i-2);
            return;
        }
    }
    cr.run();
    cr.move_warrior();
    collision(mp, cr);
    cr.draw(cr.get_naprav());
}

void death(Karta &mp, Warrior &wr, Warrior &cr){
     cr.deathP();
     for(int i=0; i<5; i++){
        txClear();
        mp.draw();
        if(wr.get_Yhitbox() >= cr.get_Yhitbox()){
            cr.warrior_death(i);
            wr.draw(wr.get_naprav());
        }
        else{
            wr.draw(wr.get_naprav());
            cr.warrior_death(i);
        }
        txSleep(80);
    }
}

void game_over(Warrior &wr){
    wr.set_xcoord(624);
    wr.set_ycoord(272);
    for(int i=0; i<5; i++){
    //int i = 4;
        txClear();
        txSetColor(RGB(47, 47, 46));
        txSetFillColor(RGB(47, 47, 46));
        txRectangle(0, 0, 1344, 640);
        wr.warrior_death(i);
        txSleep(90);
    }
    txSleep(3500);
}
#endif
