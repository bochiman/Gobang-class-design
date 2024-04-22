#ifndef CONFIRM_EXIT_H
#define CONFIRM_EXIT_H

#include <QDialog>
#include<start.h>
namespace Ui {
class Confirm_exit;
}

class Confirm_exit : public QDialog
{
    Q_OBJECT

public:
    explicit Confirm_exit(QWidget *parent = nullptr);
    ~Confirm_exit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Confirm_exit *ui;
};

#endif // CONFIRM_EXIT_H
