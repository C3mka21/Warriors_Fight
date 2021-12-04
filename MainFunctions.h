//Romashka

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

void collision(Karta &mp, Warrior &wr);
void attack(Karta &mp, Warrior &wr, Warrior &cr);
void attack_draw(Karta &mp, Warrior &wr, Warrior &cr);
void attack_check(Karta &mp, Warrior &wr, Warrior &cr, int i);
void death(Karta &mp, Warrior &wr, Warrior &cr);

void collision(Karta &mp, Warrior &wr){
        if(mp.get_cell(int(wr.get_ycoord() + wr.get_height()/1.25), int(wr.get_xcoord() + wr.get_width()/3)) > 2){
            wr.stop();
            return;
        }
        if(mp.get_cell(int(wr.get_ycoord() + wr.get_height()/1.25), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/3)) > 2){
            wr.stop();
            return;
        }
        if(mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6), int(wr.get_xcoord() + wr.get_width() - wr.get_width()/3)) > 2){
            wr.stop();
            return;
        }
        if(mp.get_cell(int(wr.get_ycoord() + wr.get_height() - wr.get_height()/6), int(wr.get_xcoord() + wr.get_width()/3)) > 2){
            wr.stop();
            return;
        }
}

void attack(Karta &mp, Warrior &wr, Warrior &cr){
    if(GetAsyncKeyState(wr.get_attack1key()) && wr.get_reload() >= wr.get_reload1()){
        if(GetAsyncKeyState(wr.get_runkey())){
            attack_draw(mp, wr, cr);
        }
        if(cr.get_hp() <= 0){
            death(mp, wr, cr);
        }
        cr.oldhp();
        attack_draw(mp, wr, cr);
        if(cr.get_hp() <= 0){
            death(mp, wr, cr);
        }
        cr.oldhp();
    }
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
            cr.hurt(i);
            return;
        }
        else if((wr.get_yAcoord() < cr.get_Yhitbox()) && (cr.get_Yhitbox() - wr.get_yAcoord() < wr.get_height())){
            cr.hurt(i);
            return;
        }
    }
    else if((wr.get_xAcoord() < cr.get_Xhitbox()) && (cr.get_Xhitbox() - wr.get_xAcoord() < wr.get_width()) && (i>=2)){
        if((wr.get_yAcoord() > cr.get_Yhitbox()) && (wr.get_yAcoord() - cr.get_Yhitbox() < cr.get_Hhitbox())){
            cr.hurt(i);
            return;
        }
        else if((wr.get_yAcoord() < cr.get_Yhitbox()) && (cr.get_Yhitbox() - wr.get_yAcoord() < wr.get_height())){
            cr.hurt(i);
            return;
        }
    }
    collision(mp, cr);
    cr.draw(cr.move_warrior());
}

void death(Karta &mp, Warrior &wr, Warrior &cr){
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
        txSleep(60);
    }
}
#endif
