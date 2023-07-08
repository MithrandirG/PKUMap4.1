#include "jump.h"
#include "ui_jump.h"

Jump::Jump(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Jump)
{
    ui->setupUi(this);
}

Jump::~Jump()
{
    delete ui;
}

void Jump::on_pushButton_clicked()
{
    if(i==0){
        ui->pushButton->setText("开发者在这");
        ui->pushButton->setGeometry(10,10,111,31);
        i++;
        return ;
    }

    if(i==1){
        ui->pushButton->setText("好吧，我在这");
        ui->pushButton->setGeometry(50,200,111,31);
        i++;
        return ;
    }
   if(i==2){
        ui->pushButton->setText("我在这呢");
        ui->pushButton->setGeometry(150,10,111,31);
        i++;
        return ;
    }

    else {
        ui->pushButton->hide();
        ui->label_2->setText("开发者因为绩点过低，\n去了王克桢楼便再无音讯");
        return ;
    }

}

