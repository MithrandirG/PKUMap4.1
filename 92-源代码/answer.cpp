#include "answer.h"
#include "ui_answer.h"
#include<QPalette>

Answer::Answer(int i, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Answer)
{
    ui->setupUi(this);
    index=i;
    Qt::WindowFlags flags;
    flags|=Qt::Window;
    flags|=Qt::WindowCloseButtonHint;
    flags|=Qt::MSWindowsFixedSizeDialogHint;
    this->setWindowFlags(flags);
    QPalette pal=this->palette();
    pal.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/ans_bg.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
    QPalette pal2;
    pal2.setColor(QPalette::WindowText,Qt::white);
    ui->label->setPalette(pal2);
    ui->formore_label->setPalette(pal2);
}

Answer::~Answer()
{
    delete ui;
}

void Answer::setText(QString s){
    ui->label->setText(s);
}

void Answer::on_formore_clicked()
{
    this->close();
    formore_ptr->show();
}

