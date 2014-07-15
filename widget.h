#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"

class Widget : public QWidget, private Ui::Widget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
};

#endif // WIDGET_H
