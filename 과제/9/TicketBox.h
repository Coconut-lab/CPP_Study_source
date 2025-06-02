#ifndef TICKETBOX_H
#define TICKETBOX_H

#include "Screen.h"

#define TICKETBOX_MANAGER_PWD "admin"

class TicketBox {
public:
    virtual Screen * selectMenu() { return NULL; }  // 상영관 선택 메뉴
    void Initialize() {}
    void Manage();
};

class TUKoreaTBox : public TicketBox {
    CGVScreen * pCGVScreen;
    LotteCinemaScreen* pLotteCinemaScreen;
    MegaboxScreen * pMegaBoxScreen;

public:
    TUKoreaTBox();
    ~TUKoreaTBox();
    Screen * selectMenu();
    void Initialize();
    void Manage();
};

#endif
