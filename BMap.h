// Romashka

#ifndef __BMAP_H__
#define __BMAP_H__

class Karta{
private:
    HDC mAp;                /// <-   онтекст источника (откуда копировать)
    HDC m_d;                /// <-  ƒескриптор приемного DC
    double m_xD;            /// <-  ’-координата верхнего левого угла изображени€-приемника
    double m_yD;            /// <-  Y-координата верхнего левого угла изображени€-приемника
    double m_w;             /// <-  Ўирина копируемого изображени€, неотрицательна€
    double m_h;             /// <-  ¬ысота копируемого изображени€, неотрицательна€
    double m_xmAp;          /// <-  ’-координата верхнего левого угла изображени€-источника
    double m_ymAp;          /// <-  Y-координата верхнего левого угла изображени€-источника
    double m_wmAp;          /// <-  Ўирина источникового  пр€моугольника
    double m_hmAp;          /// <-  ¬ысота источникового  пр€моугольника
    COLORREF m_bcolor;      /// <-  ÷вет, который будет считатьс€ прозрачным
    int field[10][21];

public:

    Karta() : mAp(txLoadImage("BMap.bmp")), m_d(txDC()), m_xD(64), m_yD(64), m_w(64), m_h(64),
        m_xmAp(32), m_ymAp(0), m_wmAp(32), m_hmAp(32), m_bcolor(RGB(47, 47, 4))
        {
            if(!mAp){
                txMessageBox(" артинка не найдена!");
                exit(0);
            }
        }

    ~Karta(){
        txDeleteDC(mAp);
    }

    void draw(){
        for(int i=0; i<10; i++){
            for(int j=0; j<21; j++){
                Win32::TransparentBlt(m_d, int(m_xD)*j, int(m_yD)*i, int(m_w), int(m_h), mAp, int(m_xmAp)*field[i][j], int(m_ymAp), int(m_wmAp), int(m_hmAp), m_bcolor);
            }
        }
    }

    inline int get_cell(int y, int x){
        y = int(y/m_yD); //80
        x = int(x/m_xD); //48
        return field[y][x];
    }

    inline void set_cell(int y, int x, int type){
        field[y][x] = type;
    }

    inline void pers_set_cell(int y, int x, int type){
        y = int(y/m_yD);
        x = int(x/m_xD);
        field[y][x] = type;
    }
};
#endif
