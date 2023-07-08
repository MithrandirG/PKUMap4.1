#include "pkulife.h"
#include "ui_pkulife.h"

Pkulife::Pkulife(int i, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pkulife)
{
    ui->setupUi(this);
    this->setWindowTitle("北大生活");
    index = i;
}

Pkulife::~Pkulife()
{
    delete ui;
}

void Pkulife::load_image(){
    //ui->label->setWordWrap(true);
    image.load(":/new/prefix1/background_pkulife.png");
    ui->label->setWordWrap(true);
    ui->label_background->setPixmap(QPixmap::fromImage(image));
    //this->setWindowTitle("博雅塔");
    if (index == 1){
        ui->label->setText("      物美超市位于45楼甲地下室，是北大最大和品种最齐超市。\n\n     北大教材中心位于二教东北侧，主要销售教材资料。" );
    }
    if (index == 2){
        ui->label->setText("      北京大学有学一、艺园、学五、燕南、农园、勺园、畅春园、佟园等众多食堂。\n\n     食堂数目众多、菜品丰富、各有特色，是北大的一道靓丽的风景线。");
    }
    if (index == 3){
        ui->label->setText("      北大勺园，有标准间、单人间、套间各类客房212套。\n\n     北大中关新园位于北京大学东南门外，是集住宿、餐饮、会议、康乐等多功能于一体的综合性服务园区。");
    }
    if (index == 4){
        ui->label->setText("      北京大学百周年纪念讲堂时常举办各种名家进校园活动，是学子课余休闲的不二之选。此外，它还是一个优秀的电影院、剧院、音乐厅。\n\n       北京大学有丰富的体育健身场馆。邱德拔体育馆、五四体育场、第二体育场、第一体育场，每天傍晚人声鼎沸。 ");
    }
}

