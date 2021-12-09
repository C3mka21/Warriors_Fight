// Romashka

#ifndef __BMAP_H__
#define __BMAP_H__

class Karta{
private:
    HDC mAp;                /// <-  �������� ��������� (������ ����������)
    HDC m_d;                /// <-  ���������� ��������� DC
    double m_xD;            /// <-  �-���������� �������� ������ ���� �����������-���������
    double m_yD;            /// <-  Y-���������� �������� ������ ���� �����������-���������
    double m_w;             /// <-  ������ ����������� �����������, ���������������
    double m_h;             /// <-  ������ ����������� �����������, ���������������
    double m_xmAp;          /// <-  �-���������� �������� ������ ���� �����������-���������
    double m_ymAp;          /// <-  Y-���������� �������� ������ ���� �����������-���������
    double m_wmAp;          /// <-  ������ �������������  ��������������
    double m_hmAp;          /// <-  ������ �������������  ��������������
    COLORREF m_bcolor;      /// <-  ����, ������� ����� ��������� ����������
    int field[10][21];

public:

    Karta() : mAp(txLoadImage("BMap.bmp")), m_d(txDC()), m_xD(64), m_yD(64), m_w(64), m_h(64),
        m_xmAp(32), m_ymAp(0), m_wmAp(32), m_hmAp(32), m_bcolor(RGB(47, 47, 4))
        {
            if(!mAp){
                txMessageBox("�������� �� �������!");
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
