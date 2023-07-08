#ifndef ERROR_H
#define ERROR_H
#include <QWidget>
#include<Qimage>

namespace Ui { class Error; }//显示错误的Widget，可以公用

class Error : public QWidget
{

    Q_OBJECT

public:
    explicit Error(QWidget *parent = nullptr);
    ~Error();
    void setText(QString s="");
    Ui::Error *ui;
private:

};

#endif // ERROR_H
