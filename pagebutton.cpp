#include "pagebutton.h"

PageButton::PageButton(QWidget *parent) :
    QPushButton(parent)
{
}
PageButton::PageButton(QString s):
    QPushButton(s){

}

void PageButton::onClicked(){
    emit onClick(page);
}
