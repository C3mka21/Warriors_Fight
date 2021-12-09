//Romashka

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

class Warrior{

private:
    HDC d;                          /// <-  ���������� ��������� DC
    HDC GoR;                        /// <-  �������� ��������� (�������� ������)
    HDC GoL;                        /// <-  �������� ��������� (�������� �����)
    HDC GoUp;                       /// <-  �������� ��������� (�������� �����)
    HDC GoD;                        /// <-  �������� ��������� (�������� ����)
    HDC AtR;                        /// <-  �������� ��������� (����� ������)
    HDC AtL;                        /// <-  �������� ��������� (����� �����)
    HDC AtUp;                       /// <-  �������� ��������� (����� �����)
    HDC AtD;                        /// <-  �������� ��������� (����� ����)
    HDC HtR;                        /// <-  �������� ��������� (��������� ����� ������)
    HDC HtL;                        /// <-  �������� ��������� (��������� ����� �����)
    HDC HtUp;                       /// <-  �������� ��������� (��������� ����� ������)
    HDC HtD;                        /// <-  �������� ��������� (��������� ����� �����)
    HDC death;                      /// <-  �������� ��������� (������)
    HDC naprav = GoD;               /// <-  ���������� ������������ �����������
    double xD;                      /// <-  �-���������� �������� ������ ���� �����������-���������
    double yD;                      /// <-  Y-���������� �������� ������ ���� �����������-���������
    double w;                       /// <-  ������ ����������� �����������, ���������������
    double h;                       /// <-  ������ ����������� �����������, ���������������
    double xScr;                    /// <-  �-���������� �������� ������ ���� �����������-���������
    double yScr;                    /// <-  Y-���������� �������� ������ ���� �����������-���������
    double wScr;                    /// <-  ������ �������������  ��������������
    double hScr;                    /// <-  ������ �������������  ��������������
    double xspeed;                  /// <-  �������� ������ �� x
    double yspeed;                  /// <-  �������� ������ �� y
    double oldxsp = xspeed;         /// <-  ������ ����������� �������� ������ �� x
    double oldysp = yspeed;         /// <-  ������ ����������� �������� ������ �� �
    double xa = 0;                  /// <-  X-���������� ����� ���������
    double ya = 0;                  /// <-  Y-���������� ����� ���������
    double wa = 0;                  /// <-  ������ ����� ���������
    double ha = 0;                  /// <-  ������ ����� ���������
    double xhb = xD + w/1.6;        /// <-  X-���������� ��������
    double yhb = yD + h/1.85;       /// <-  Y-���������� ��������
    double whb = w - 2*(w/1.6);     /// <-  ������ ��������
    double hhb = h - (h/1.45);      /// <-  ������ ��������
    COLORREF bcolor;                /// <-  ����, ������� ����� ��������� ����������
    int reload;                     /// <-  ����� ����������� �����
    int Sreload;                    /// <-  �����, �� ������� ����������� ���� �� �����
    int hp;                         /// <-  ��(�����) ���������
    int ohp = hp;                   /// <-  ������ ����������� ���������� ��(�����) ���������
    int nhp = hp;                   /// <-  ������ ���������� ��(�����) ���������
    int deaths_count;               /// <-  ���������� ������� ��������
    const int reload1 = reload;     /// <-  ������ ��������� ������������ ������� �����������
    const int Sreload1 = Sreload;   /// <-  ������ ��������� ������������ �������, �� ������� ����������� ���� �� �����
    const int r_move;               /// <-  ������ �������� ������� ��� �������� ������
    const int l_move;               /// <-  ������ �������� ������� ��� �������� �����
    const int up_move;              /// <-  ������ �������� ������� ��� �������� �����
    const int d_move;               /// <-  ������ �������� ������� ��� �������� ����
    const int wrun;                 /// <-  ������ �������� ������� ��� ����
    const int attack1;              /// <-  ������ �������� ������� ��� �����

public:
    Warrior(HDC GoR1, HDC GoL1, HDC GoUp1, HDC GoD1, HDC AtR1, HDC AtL1, HDC AtUp1, HDC AtD1, HDC HtR1, HDC HtL1, HDC HtUp1, HDC HtD1, HDC death1, double x, double y, double w1, double h1, const int r_move1, const int l_move1, const int up_move1, const int d_move1, const int run1, const int attack01):
        d(txDC()), GoR(GoR1), GoL(GoL1), GoUp(GoUp1), GoD(GoD1),
        AtR(AtR1), AtL(AtL1), AtUp(AtUp1), AtD(AtD1),
        HtR(HtR1), HtL(HtL1), HtUp(HtUp1), HtD(HtD1), death(death1),
        xD(x), yD(y), w(w1), h(h1), xScr(0), yScr(0), wScr(48), hScr(48), xspeed(4.5), yspeed(3.5), bcolor(RGB(182, 185, 184)), reload(10), Sreload(10), hp(3), deaths_count(0),
        r_move(r_move1), l_move(l_move1), up_move(up_move1), d_move(d_move1), wrun(run1), attack1(attack01)
    {
        if(!GoR){
            txMessageBox("'�������� ������' ����������", "����", 0);
            exit(0);
        }
        if(!GoL){
            txMessageBox("'�������� �����' ����������", "����", 0);
            exit(0);
        }
        if(!GoUp){
            txMessageBox("'�������� �����' ����������", "����", 0);
            exit(0);
        }
        if(!GoD){
            txMessageBox("'�������� ����' ����������", "����", 0);
            exit(0);
        }
        if(!AtR){
            txMessageBox("'������ �����' ����������", "����", 0);
            exit(0);
        }
        if(!AtL){
            txMessageBox("'����� �����' ����������", "����", 0);
            exit(0);
        }
        if(!AtUp){
            txMessageBox("'������� �����' ����������", "����", 0);
            exit(0);
        }
        if(!AtD){
            txMessageBox("'������ �����' ����������", "����", 0);
            exit(0);
        }
        if(!HtR){
            txMessageBox("'���� ������' ����������", "����", 0);
            exit(0);
        }
        if(!HtL){
            txMessageBox("'���� �����' ����������", "����", 0);
            exit(0);
        }
        if(!HtUp){
            txMessageBox("'���� ������' ����������", "����", 0);
            exit(0);
        }
        if(!HtD){
            txMessageBox("'���� �����' ����������", "����", 0);
            exit(0);
        }
        if(!death){
            txMessageBox("'������' ����������", "����", 0);
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
