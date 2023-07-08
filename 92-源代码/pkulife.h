#ifndef PKULIFE_H
#define PKULIFE_H

#include <QWidget>

namespace Ui {
class Pkulife;
}

class Pkulife : public QWidget
{
    Q_OBJECT

public:
    explicit Pkulife(int i, QWidget *parent = nullptr);
    ~Pkulife();
    void load_image();

private slots:


private:
    Ui::Pkulife *ui;
    int index;
    QImage image;
};

#endif // PKULIFE_H
