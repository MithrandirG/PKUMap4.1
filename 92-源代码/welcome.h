#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include"widget.h"
#include"jump.h"
namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();

private slots:
    void on_enter_clicked();

    void on_exit_clicked();

    void on_about_clicked();

    void on_book_clicked();

private:
    Ui::Welcome *ui;
    Widget*w;
    Jump a;
};

#endif // WELCOME_H
