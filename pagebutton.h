#ifndef PAGEBUTTON_H
#define PAGEBUTTON_H

#include <QPushButton>

class PageButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PageButton(QWidget *parent = 0);
    PageButton(QString );
    int page;

signals:
    void onClick(int &i);

public slots:
    void onClicked();

};

#endif // PAGEBUTTON_H
