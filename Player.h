//Romashka

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

class Warrior{

private:
    HDC d;                          /// <-  Дескриптор приемного DC
    HDC GoR;                        /// <-  Контекст источника (Движение вправо)
    HDC GoL;                        /// <-  Контекст источника (Движение влево)
    HDC GoUp;                       /// <-  Контекст источника (Движение вверх)
    HDC GoD;                        /// <-  Контекст источника (Движение вниз)
    HDC AtR;                        /// <-  Контекст источника (Атака вправо)
    HDC AtL;                        /// <-  Контекст источника (Атака влево)
    HDC AtUp;                       /// <-  Контекст источника (Атака вверх)
    HDC AtD;                        /// <-  Контекст источника (Атака вниз)
    HDC HtR;                        /// <-  Контекст источника (Получение урона справа)
    HDC HtL;                        /// <-  Контекст источника (Получение урона слева)
    HDC HtUp;                       /// <-  Контекст источника (Получение урона сверху)
    HDC HtD;                        /// <-  Контекст источника (Получение урона снизу)
    HDC death;                      /// <-  Контекст источника (Смерть)
    HDC naprav = GoD;               /// <-  Переменная запоминающая направление
    double xD;                      /// <-  Х-координата верхнего левого угла изображения-приемника
    double yD;                      /// <-  Y-координата верхнего левого угла изображения-приемника
    double w;                       /// <-  Ширина копируемого изображения, неотрицательная
    double h;                       /// <-  Высота копируемого изображения, неотрицательная
    double xScr;                    /// <-  Х-координата верхнего левого угла изображения-источника
    double yScr;                    /// <-  Y-координата верхнего левого угла изображения-источника
    double wScr;                    /// <-  Ширина источникового  прямоугольника
    double hScr;                    /// <-  Высота источникового  прямоугольника
    double xspeed;                  /// <-  Скорость игрока по x
    double yspeed;                  /// <-  Скорость игрока по y
    double oldxsp = xspeed;         /// <-  Хранит изначальную скорость игрока по x
    double oldysp = yspeed;         /// <-  Хранит изначальную скорость игрока по н
    double xa = 0;                  /// <-  X-координата атаки персонажа
    double ya = 0;                  /// <-  Y-координата атаки персонажа
    double wa = 0;                  /// <-  Ширина атаки персонажа
    double ha = 0;                  /// <-  Высота атаки персонажа
    double xhb = xD + w/1.6;        /// <-  X-координата хитбокса
    double yhb = yD + h/1.85;       /// <-  Y-координата хитбокса
    double whb = w - 2*(w/1.6);     /// <-  Ширина хитбокса
    double hhb = h - (h/1.45);      /// <-  Высота хитбокса
    COLORREF bcolor;                /// <-  Цвет, который будет считаться прозрачным
    int reload;                     /// <-  Время перезарядки атаки
    int Sreload;                    /// <-  Время, на которое блокируется урон от шипов
    int hp;                         /// <-  ХП(жизни) персонажа
    int ohp = hp;                   /// <-  Хранит изначальное количество ХП(жизни) персонажа
    int nhp = hp;                   /// <-  Хранит количество ХП(жизни) персонажа
    int deaths_count;               /// <-  Количество смертей персонжа
    const int reload1 = reload;     /// <-  Хранит константу изначального времени перезарядки
    const int Sreload1 = Sreload;   /// <-  Хранит константу изначального времени, на которое блокируется урон от шипов
    const int r_move;               /// <-  Хранит значение клавиши для движения вправо
    const int l_move;               /// <-  Хранит значение клавиши для движения влево
    const int up_move;              /// <-  Хранит значение клавиши для движения вверх
    const int d_move;               /// <-  Хранит значение клавиши для движения вниз
    const int wrun;                 /// <-  Хранит значение клавиши для бега
    const int attack1;              /// <-  Хранит значение клавиши для атаки

public:
    Warrior(HDC GoR1, HDC GoL1, HDC GoUp1, HDC GoD1, HDC AtR1, HDC AtL1, HDC AtUp1, HDC AtD1, HDC HtR1, HDC HtL1, HDC HtUp1, HDC HtD1, HDC death1, double x, double y, double w1, double h1, const int r_move1, const int l_move1, const int up_move1, const int d_move1, const int run1, const int attack01):
        d(txDC()), GoR(GoR1), GoL(GoL1), GoUp(GoUp1), GoD(GoD1),
        AtR(AtR1), AtL(AtL1), AtUp(AtUp1), AtD(AtD1),
        HtR(HtR1), HtL(HtL1), HtUp(HtUp1), HtD(HtD1), death(death1),
        xD(x), yD(y), w(w1), h(h1), xScr(0), yScr(0), wScr(48), hScr(48), xspeed(4.5), yspeed(3.5), bcolor(RGB(182, 185, 184)), reload(10), Sreload(10), hp(3), deaths_count(0),
        r_move(r_move1), l_move(l_move1), up_move(up_move1), d_move(d_move1), wrun(run1), attack1(attack01)
    {
        if(!GoR){
            txMessageBox("'Движение вправо' отсутсвует", "Игра", 0);
            exit(0);
        }
        if(!GoL){
            txMessageBox("'Движение влево' отсутсвует", "Игра", 0);
            exit(0);
        }
        if(!GoUp){
            txMessageBox("'Движение вверх' отсутсвует", "Игра", 0);
            exit(0);
        }
        if(!GoD){
            txMessageBox("'Движение вниз' отсутсвует", "Игра", 0);
            exit(0);
        }
        if(!AtR){
            txMessageBox("'Правая атака' отсутсвует", "Игра", 0);
            exit(0);
        }
        if(!AtL){
            txMessageBox("'Левая атака' отсутсвует", "Игра", 0);
            exit(0);
        }
        if(!AtUp){
            txMessageBox("'Верхняя атака' отсутсвует", "Игра", 0);
            exit(0);
        }
        if(!AtD){
            txMessageBox("'Нижняя атака' отсутсвует", "Игра", 0);
            exit(0);
        }
        if(!HtR){
            txMessageBox("'Урон справа' отсутсвует", "Игра", 0);
            exit(0);
        }
        if(!HtL){
            txMessageBox("'Урон слева' отсутсвует", "Игра", 0);
            exit(0);
        }
        if(!HtUp){
            txMessageBox("'Урон сверху' отсутсвует", "Игра", 0);
            exit(0);
        }
        if(!HtD){
            txMessageBox("'Урон снизу' отсутсвует", "Игра", 0);
            exit(0);
        }
        if(!death){
            txMessageBox("'Смерть' отсутсвует", "Игра", 0);
            exit(0);
        }
    }

    ~Warrior(){
        txDeleteDC(GoR);
        txDeleteDC(GoL);
        txDeleteDC(GoUp);
        txDeleteDC(GoD);
        txDeleteDC(AtR);
        txDeleteDC(AtL);
        txDeleteDC(AtUp);
        txDeleteDC(AtD);
        txDeleteDC(HtR);
        txDeleteDC(HtL);
        txDeleteDC(HtUp);
        txDeleteDC(HtD);
        txDeleteDC(death);
    }

    HDC move_warrior();
    void run();
    void stop();
    void attack(int i);
    void hurt(int i);

    void warrior_death(int i){
        xScr = wScr * i;
        draw(death);
        xScr = 0;
    }

    inline void draw(HDC scr){
        Win32::TransparentBlt(d, int(xD), int(yD), int(w), int(h), scr, int(xScr), int(yScr), int(wScr), int(hScr), bcolor);
    }

    inline void set_xcoord(double x){
        xD = x;
    }

    inline void set_ycoord(double y){
        yD = y;
    }

    inline void hurt_hp(){
        hp = nhp - 1;
    }

    inline void newhp(){
        nhp = hp;
    }

    inline void fullhp(){
        nhp = ohp;
        hp = ohp;
    }

    void reload_changeP(){     // P - Plus
        reload++;
    }

    void Sreload_changeP(){     // S - Spike P - Plus
        if(Sreload < Sreload1)
            Sreload++;
    }

    void reload_changeAA(){    // AA - After Attack
        reload -= reload1;
    }

    void Sreload_changeAH(){    // S - Spike  AH - After Hurt
        Sreload = 0;
    }

    inline void deathP(){
        deaths_count++;
    }

    inline void clear_deaths(){
        deaths_count = 0;
    }

    inline HDC get_naprav(){
        return naprav;
    }

    inline double get_xcoord(){
        return xD;
    }

    inline double get_ycoord(){
        return yD;
    }

    inline double get_width(){
        return w;
    }

    inline double get_height(){
        return h;
    }

    inline double get_Xhitbox(){
        xhb = xD + w/1.6;
        return xhb;
    }

    inline double get_Yhitbox(){
        yhb = yD + h/1.85;
        return yhb;
    }

    inline double get_Whitbox(){
        return whb;
    }

    inline double get_Hhitbox(){
        return hhb;
    }

    inline int get_reload(){
        return reload;
    }

    inline int get_Sreload(){
        return Sreload;
    }

    inline int get_Sreload1(){
        return Sreload1;
    }

    inline int get_reload1(){
        return reload1;
    }

    inline double get_xAcoord(){
        return xa;
    }

    inline double get_yAcoord(){
        return ya;
    }

    inline double get_wAcoord(){
        return wa;
    }

    inline double get_hAcoord(){
        return ha;
    }

    inline int get_hp(){
        return nhp;
    }

    inline int get_runkey(){
        return wrun;
    }

    inline int get_attack1key(){
        return attack1;
    }

    inline int get_deaths(){
        return deaths_count;
    }

 };

 HDC Warrior::move_warrior(){
    if(GetAsyncKeyState(d_move)){
        naprav = GoD;
        xScr += wScr;
        yD += yspeed;
        if(xScr >= 336)
            xScr = 0;
        return GoD;
    }
    else if(GetAsyncKeyState(up_move)){
        naprav = GoUp;
        xScr += wScr;
        yD -= yspeed;
        if(xScr >= 336)
            xScr = 0;
        return GoUp;
    }
    else if(GetAsyncKeyState(r_move)){
        naprav = GoR;
        xScr += wScr;
        xD += xspeed;
        if(xScr >= 336)
            xScr = 0;
        return GoR;
    }
    else if(GetAsyncKeyState(l_move)){
        naprav = GoL;
        xScr += wScr;
        xD -= xspeed;
        if(xScr >= 336)
            xScr = 0;
        return GoL;
    }
    xScr = 0;
    return naprav;
}

void  Warrior::run(){
    xspeed = oldxsp;
    yspeed = oldysp;
    if(GetAsyncKeyState(wrun)){
        xspeed = xspeed*2;
        yspeed = yspeed*2;
    }
}

void Warrior::stop(){
    if(naprav == GoUp)
        yD += yspeed;
    else if(naprav == GoL)
        xD += xspeed;
    else if(naprav == GoD)
        yD -= yspeed;
    else if(naprav == GoR)
        xD -= xspeed;
}

void Warrior::attack(int i){
    xScr=wScr*i;
    ha = h * 0.667;
    wa = w * 0.667;
    if(naprav == GoR){
        draw(AtR);
        xa = 0.333 * w + xD;
        ya = 0.25 * h + yD;
    }
    else if(naprav == GoL){
        draw(AtL);
        xa = xD;
        ya = 0.167 * h + yD;
    }
    else if(naprav == GoD){
        draw(AtD);
        xa = 0.042 * w + xD;
        ya = 0.333 * h + yD;
    }
    else if(naprav == GoUp){
        draw(AtUp);
        xa = 0.333 * w + xD;
        ya = yD;
    }
    xScr = 0;
}

void Warrior::hurt(int i){
    xScr = wScr * i;
    if(naprav == GoR){
        draw(HtR);
    }
    else if(naprav == GoL){
        draw(HtL);
    }
    else if(naprav == GoD){
        draw(HtD);
    }
    else if(naprav == GoUp){
        draw(HtUp);
    }
    hurt_hp();
    xScr = 0;
}
 #endif
