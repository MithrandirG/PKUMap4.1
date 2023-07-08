#ifndef JUMP_H
#define JUMP_H

#include <QWidget>

namespace Ui {
class Jump;
}

class Jump : public QWidget
{
    Q_OBJECT

public:
    explicit Jump(QWidget *parent = nullptr);
    ~Jump();
    int i=0;
private slots:
    void on_pushButton_clicked();

private:
    Ui::Jump *ui;
};

#endif // JUMP_H
