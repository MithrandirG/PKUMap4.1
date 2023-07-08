#include "welcome.h"
#include "ui_welcome.h"
#include <QDesktopServices>
#include <QUrl>
Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{

    ui->setupUi(this);
    this->setWindowTitle("燕园地图导览");
    Qt::WindowFlags flags;
    flags|=Qt::Window;
    flags|=Qt::WindowCloseButtonHint;
    flags|=Qt::MSWindowsFixedSizeDialogHint;
    this->setWindowFlags(flags);
    QPalette pal=this->palette();
    pal.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/cat.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_enter_clicked()
{
    w=new Widget;
    w->show();
    this->close();
}


void Welcome::on_exit_clicked()
{
    this->close();
}


void Welcome::on_about_clicked()
{
    a.setWindowTitle("开发者信息");

    a.show();
}


void Welcome::on_book_clicked()
{
    const QUrl regUrl(QLatin1String("https://visitor.pku.edu.cn/visitor/modules/tourist/indexW.html#/touristWeb"));
    QDesktopServices::openUrl(regUrl);
}

