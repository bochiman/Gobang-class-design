#ifndef START1_H
#define START1_H
#include <QMainWindow>
#include <QWidget>
#include <checkbrd.h>
#include <checkbrd_ai.h>
#include<confirm_exit.h>
#include <start2.h>
#include <qobject.h>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>
#include <QPen>
#include <QWidget>
#include <start2.h>
#include <start.h>

namespace Ui {
class Start1;
}

class Start1 : public QWidget
{
    Q_OBJECT

public:
    explicit Start1(QWidget *parent = nullptr);
    ~Start1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Start1 *ui;
};

#endif // START1_H
