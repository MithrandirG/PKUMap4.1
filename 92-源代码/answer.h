#ifndef ANSWER_H
#define ANSWER_H
#include <QWidget>
#include<Qimage>
#include "introduction.h"

namespace Ui { class Answer; }
class Answer : public QWidget
{

    Q_OBJECT

public:
    explicit Answer(int i, QWidget*parent = nullptr);
    ~Answer();
    void setText(QString s);
    Introduction* formore_ptr=nullptr;

private slots:
    void on_formore_clicked();

private:
    Ui::Answer *ui;
    int index;
};
#endif // ANSWER_H
