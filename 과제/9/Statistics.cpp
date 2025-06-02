#include "Statistics.h"
#include "Screen.h"
#include "Ticket.h"

// 스크린별 총 수익 계산
int Statistics::totalRevenue(Screen* pScreen) {
    if (!pScreen) return 0;
    
    int totalRevenue = 0;
    int rowMax = pScreen->getRowMax();
    int colMax = pScreen->getColMax();
    Ticket** seatArray = pScreen->getTicketArray();
    
    for (int i = 0; i < rowMax; i++) {
        for (int j = 0; j < colMax; j++) {
            if (seatArray[i][j].getCheck() == SEAT_COMPLETION_MARK) {
                totalRevenue += seatArray[i][j].getPayAmount();
            }
        }
    }
    
    return totalRevenue;
}

// 스크린별 총 판매량 계산
int Statistics::totalSalesCount(Screen* pScreen) {
    if (!pScreen) return 0;
    
    int salesCount = 0;
    int rowMax = pScreen->getRowMax();
    int colMax = pScreen->getColMax();
    Ticket** seatArray = pScreen->getTicketArray();
    
    for (int i = 0; i < rowMax; i++) {
        for (int j = 0; j < colMax; j++) {
            if (seatArray[i][j].getCheck() == SEAT_COMPLETION_MARK) {
                salesCount++;
            }
        }
    }
    
    return salesCount;
}
