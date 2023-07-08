#ifndef INTRODUCTION_H
#define INTRODUCTION_H

#include <QWidget>
#include<Qimage>
#include<QPushButton>

namespace Ui {
class Introduction;
}

class Introduction : public QWidget
{
    Q_OBJECT

public:
    explicit Introduction(int i, QWidget *parent = nullptr);
    ~Introduction();
    void loadimage();
    Introduction* next = nullptr;
    Introduction* last = nullptr;
    int bg=-1;
    QPushButton* itsbutton=nullptr;
    int currentimg=0;

private slots:

    void on_Next_clicked();
    void on_Last_clicked();

    void on_change_background_activated(int index);

    void on_signbutton_clicked();



    void on_img_turnleft_clicked();

    void on_img_turnright_clicked();

private:
    Ui::Introduction *ui;
    QImage img[4];
    int index=0;
};

#endif // INTRODUCTION_H
