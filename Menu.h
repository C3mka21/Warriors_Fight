//Romashka

#ifndef __MENU_H__
#define __MENU_H__

int menu();
void bplay(HDC play, COLORREF bcolor, int &sost);
int binfo(HDC info, HDC infoP, COLORREF bcolor);

int menu(){
    int sost = 0;
    int FxD = 0, FyD = 0, Fw = 1344, Fh = 640, FxScr = 0, FyScr = 0, FwScr = 1344, FhScr = 640; //Параметры для рисования фона
    COLORREF bcolor = RGB(10, 10, 10); //блокируемый цвет
    HDC fon = txLoadImage("Menu2.bmp");
    HDC play = txLoadImage("Menu2Play.bmp");
    HDC info = txLoadImage("infoButton.bmp");
    HDC infoP = txLoadImage("info.bmp");
    if(!fon){
        txMessageBox("'Фон' отсутсвует", "Игра", 0);
        sost = -1;
    }
    if(!play){
        txMessageBox("Кнопка 'Play' отсутсвует", "Игра", 0);
        sost = -1;
    }
    if(!info){
        txMessageBox("Кнопка 'info' отсутсвует", "Игра", 0);
        sost = -1;
    }
    if(!infoP){
        txMessageBox("'Информационное окно' отсутсвует", "Игра", 0);
        sost = -1;
    }
    Win32::TransparentBlt(txDC(), FxD, FyD, Fw, Fh, fon, FxScr, FyScr, FwScr, FhScr, bcolor);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while(sost == 0){
        bplay(play, bcolor, sost);
        if(binfo(info, infoP, bcolor == 1))
            Win32::TransparentBlt(txDC(), FxD, FyD, Fw, Fh, fon, FxScr, FyScr, FwScr, FhScr, bcolor);
        if(GetAsyncKeyState(VK_ESCAPE))
            sost = -1;
        txSleep();
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    txDeleteDC(fon);
    txDeleteDC(play);
    txDeleteDC(info);
    txDeleteDC(infoP);
    return sost;
}

void bplay(HDC play, COLORREF bcolor, int &sost){
    int PxD = 647, PyD = 306, Pw = 51, Ph = 123, PxScr = 0, PyScr = 0, PwScr = 51, PhScr = 123; //Параметры для рисования кнопки "Play"
    if((PxD <= txMouseX()) && (PxD + Pw > txMouseX()) && (PyD <= txMouseY()) && (PyD + Ph > txMouseY())){
        if(txMouseButtons() == 1){
            while(txMouseButtons() == 1){
                Win32::TransparentBlt(txDC(), PxD, PyD, Pw, Ph, play, PxScr + 2 * Pw, PyScr, PwScr, PhScr, bcolor);
            }
            if((PxD <= txMouseX()) && (PxD + Pw > txMouseX()) && (PyD <= txMouseY()) && (PyD + Ph > txMouseY())){
                sost = 1;
            }
        }
        Win32::TransparentBlt(txDC(), PxD, PyD, Pw, Ph, play, PxScr + Pw, PyScr, PwScr, PhScr, bcolor);
    }
    else{
        Win32::TransparentBlt(txDC(), PxD, PyD, Pw, Ph, play, PxScr, PyScr, PwScr, PhScr, bcolor);
    }
}

int binfo(HDC info, HDC infoP, COLORREF bcolor){
    int i = 0; // переменная, возвращающая 0 по умолчанию, и 1 если было выведено информационное окно
    int IxD = 617, IyD = 580, Iw = 115, Ih = 52, IxScr = 0, IyScr = 0, IwScr = 115, IhScr = 52; //Параметры для рисования кнопки "info"
    int IPxD = 418, IPyD = 74, IPw = 507, IPh = 459, IPxScr = 0, IPyScr = 0, IPwScr = 507, IPhScr = 459; //Параметры для рисования информационного окна
    if((IxD <= txMouseX()) && (IxD + Iw > txMouseX()) && (IyD <= txMouseY()) && (IyD + Ih > txMouseY())){
        if(txMouseButtons() == 1){
            while(txMouseButtons() == 1){
                Win32::TransparentBlt(txDC(), IxD, IyD, Iw, Ih, info, IxScr + 2 * Iw, IyScr, IwScr, IhScr, bcolor);
                txSleep();
            }
            if((IxD <= txMouseX()) && (IxD + Iw > txMouseX()) && (IyD <= txMouseY()) && (IyD + Ih > txMouseY())){
                while(!GetAsyncKeyState(VK_ESCAPE)){
                    Win32::TransparentBlt(txDC(), IPxD, IPyD, IPw, IPh, infoP, IPxScr, IPyScr, IPwScr, IPhScr, bcolor);
                    txSleep();
                }
                while(GetAsyncKeyState(VK_ESCAPE)){}
                i = 1;
            }
        }
        Win32::TransparentBlt(txDC(), IxD, IyD, Iw, Ih, info, IxScr + Iw, IyScr, IwScr, IhScr, bcolor);
    }
    else{
        Win32::TransparentBlt(txDC(), IxD, IyD, Iw, Ih, info, IxScr, IyScr, IwScr, IhScr, bcolor);
    }
    return i;
}

#endif
