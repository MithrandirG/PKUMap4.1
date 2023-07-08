#include "introduction.h"
#include "ui_introduction.h"
#include<QPalette>

Introduction::Introduction(int i, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Introduction)
{
    ui->setupUi(this);
    index=i;
    Qt::WindowFlags flags;
    flags|=Qt::Window;
    flags|=Qt::WindowCloseButtonHint;
    flags|=Qt::MSWindowsFixedSizeDialogHint;
    this->setWindowFlags(flags);
    if(i==19){
        last=this;
        next=this;
    }

    if(index!=-2){
        bg=1;
        ui->change_background->setCurrentIndex(0);
        QPalette pal=this->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/background1.png").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
        setPalette(pal);
    }
}

Introduction::~Introduction()
{
    delete ui;
}
void Introduction::loadimage(){
    //ui->label->adjustSize();
    ui->label->setWordWrap(true);
    if(index==1){
        this->setWindowTitle("博雅塔");
        img[0].load(":/new/prefix1/tower.png");
        img[1].load(":/new/prefix2/intro_imgs/imgs/02.jpg");
        img[2].load(":/new/prefix2/intro_imgs/imgs/01.png");
        ui->Last->setText("上个景点：计算中心");
        ui->Next->setText("下个景点：未名湖");
        ui->label_image->setPixmap(QPixmap::fromImage(img[0]));
        ui->label->setText("      博雅塔坐落在未名湖畔东南隅的山地上，一年四季守护着秀美的燕园。\n      它采用辽代密檐砖塔外形，在设计上参照了通州的燃灯塔，凡十三级，中空，有螺旋梯直通塔顶。博雅塔主要是由当时燕京大学哲学系教授博晨光的叔父捐资兴建的，所以被命名为“博雅塔”。博雅塔在建成之初是一座水塔。而今，博雅塔因其典雅、质朴的造型成为了燕园文脉的载体与象征。\n      博雅塔在特别的节庆之夜还会亮灯，与未名湖波光中的倒影相映成趣。");
        ui->title->setText("博雅塔");
    }
    else if(index==2){
        this->setWindowTitle("未名湖");
        img[0].load(":/new/prefix1/lake.png");
        img[1].load(":/new/prefix2/intro_imgs/imgs/11.jpg");
        img[2].load(":/new/prefix2/intro_imgs/imgs/12.jpg");
        ui->Last->setText("上个景点：博雅塔");
        ui->Next->setText("下个景点：俄文楼");
        ui->label_image->setPixmap(QPixmap::fromImage(img[0]));
        ui->label->setText("      燕园“一塔湖图”三景中的“湖”，就是未名湖。它是北大众多湖泊泉流中的绝冠。相传未名湖本无名，钱穆先生在北大任教时乃以“未名”名之。\n      未名湖也有三景，一岛一鱼一石舫。岛是湖心岛，由一座小桥与北岸连通；鱼是翻尾石鱼，远望宛如真正的鱼儿跃出水面；石舫，又名“不系舟”，是乾隆时期淑春园的遗物。\n      “未名湖是个海洋，鸟儿飞来这个地方。这里是我的胸膛，这里跳着我的心脏。”");
        ui->title->setText("未名湖");
    }
    else if(index==3){
        this->setWindowTitle("俄文楼");
        img[0].load(":/new/prefix2/intro_imgs/imgs/23.jpg");
        img[1].load(":/new/prefix2/intro_imgs/imgs/21.jpg");
        img[2].load(":/new/prefix2/intro_imgs/imgs/22.jpg");
        ui->Last->setText("上个景点：未名湖");
        ui->Next->setText("下个景点：北大图书馆");
        ui->label_image->setPixmap(QPixmap::fromImage(img[0]));
        ui->label->setText("      俄文楼是元培学院的院楼，元培学院的办公与日常活动均在这里进行。\n      俄文楼曾经是女子学院教学楼，由罗素·塞奇基金会为纪念塞奇夫人而捐资兴建。它位于静园草坪以北，未名湖以南，体量雄浑，气势开阔，是典型的墨菲时代的建筑。灰瓦白墙，红色门窗嵌套其中，门前古树环绕着李大钊先生的雕像，不时有人前来瞻仰，静谧而肃穆，向人们诉说着思想自由、兼容并包的元培精神。");
        ui->title->setText("俄文楼");
    }
    else if(index==4){
        this->setWindowTitle("北大图书馆");
        img[0].load(":/new/prefix2/intro_imgs/imgs/33.jpg");
        img[1].load(":/new/prefix2/intro_imgs/imgs/31.jpg");
        img[2].load(":/new/prefix2/intro_imgs/imgs/32.jpg");
        ui->Last->setText("上个景点：俄文楼");
        ui->Next->setText("下个景点：静园");
        ui->label_image->setPixmap(QPixmap::fromImage(img[0]));
        ui->label->setText("      北京大学图书馆已历经百年，是亚洲最大的高校图书馆。圆形的玻璃穹顶之下，跨越时空的思维桥梁每一秒都在搭建。古今中外的智慧结晶，通过书页和数据快速传输。\n      1898年，京师大学堂成立藏书楼。1918年红楼初建，乃更名为“北京大学图书馆”，李大钊、毛泽东等伟人都曾在此工作。2020年，图书馆东馆大修完毕重新开放，无数学子在这里徜徉书海，众多大师在这里洞察真知。北大图书馆涵养了北大的学术精神，也传承了中华民族的文脉品格。");
        ui->title->setText("北大图书馆");
    }
    else if(index==5){
        this->setWindowTitle("静园");
        img[0].load(":/new/prefix2/intro_imgs/imgs/43.jpg");
        img[1].load(":/new/prefix2/intro_imgs/imgs/41.jpg");
        img[2].load(":/new/prefix2/intro_imgs/imgs/42.jpg");
        ui->Last->setText("上个景点：北大图书馆");
        ui->Next->setText("下个景点：燕南园");
        ui->label_image->setPixmap(QPixmap::fromImage(img[0]));
        ui->label->setText("      静园由六座院落与中间的草坪组成，精巧玲珑，静谧典雅，给人以“庭院深深”之感。六院房间均为木制结构，又在细节处各不相同，雕梁画壁，古色古香；各有精巧灰顶红色小门楼一座，由灰色石砌虎皮矮墙联成一体。每座院门都有紫藤萝花架，每年5月，紫花缀满门楼，颇为恬静幽美。\n      静园草坪中时见老师学生们畅快活动，或聚餐雅集，或锻炼游戏。青年天文学会等学生社团也会在此举办活动，静园草坪夜晚的星空很美。");
        ui->title->setText("静园");
    }
    else if(index==6){
        this->setWindowTitle("燕南园");
        img[0].load(":/new/prefix2/intro_imgs/imgs/53.jpg");
        img[1].load(":/new/prefix2/intro_imgs/imgs/51.jpg");
        img[2].load(":/new/prefix2/intro_imgs/imgs/52.jpg");
        ui->Last->setText("上个景点：静园");
        ui->Next->setText("下个景点：蔡元培铜像");
        ui->label_image->setPixmap(QPixmap::fromImage(img[0]));
        ui->label->setText("      燕南园建成于20世纪20年代，园内现存17栋建筑，有自成一体的西式小楼，也有矮墙环绕的中式小院。\n      历史学家洪业、翦伯赞，数学家江泽涵，物理学家周培源、饶毓泰、褚圣麟，经济学家马寅初、陈岱孙，哲学家冯友兰、汤用彤、冯定，化学家张龙翔、黄子卿，语言学家王力、林焘，美学家朱光潜，生物学家沈同，文学家林庚，历史地理学家侯仁之，社会学家吴文藻和文学家冰心夫妇等都曾生活在此。\n      燕南园景致古朴，与园外大不相同。偶入小围墙之内，恍然知别有洞天也。");
        ui->title->setText("燕南园");
    }
    else if(index==7){
        this->setWindowTitle("蔡元培铜像");
        img[0].load(":/new/prefix2/intro_imgs/imgs/63.jpg");
        img[1].load(":/new/prefix2/intro_imgs/imgs/61.jpg");
        img[2].load(":/new/prefix2/intro_imgs/imgs/62.jpg");
        ui->Last->setText("上个景点：燕南园");
        ui->Next->setText("下个景点：北大西门");
        ui->label_image->setPixmap(QPixmap::fromImage(img[0]));
        ui->label->setText("      蔡元培先生的雕像是北大1977、1978级毕业生在毕业前夕集资铸建的。\n该铜像由我国著名雕塑家曾竹韶教授创作，铜像基座上有许德珩亲笔书写的“蔡元培先生”五个镀金字。\n      蔡元培先生于1916年至1927年任北大校长，开“思想自由，兼容并包”之校风，使北京大学与新文化运动的风貌焕然一新，毛泽东称其为“学界泰斗，人世楷模”。时至今日，每逢清明时节，犹有后辈来到铜像前追念献花。");
        ui->title->setText("蔡元培铜像");
    }
    else if(index==8){
        this->setWindowTitle("北大西门");
        img[0].load(":/new/prefix2/intro_imgs/imgs/73.jpg");
        img[1].load(":/new/prefix2/intro_imgs/imgs/71.jpg");
        img[2].load(":/new/prefix2/intro_imgs/imgs/72.jpg");
        ui->Last->setText("上个景点：蔡元培铜像");
        ui->Next->setText("下个景点：邱德拔体育馆");
        ui->label_image->setPixmap(QPixmap::fromImage(img[0]));
        ui->label->setText("      北大西校门是北京大学的正门。它风格古朴，庄严典雅，坐西朝东，为古典三开朱漆宫门建筑，与颐和园东宫门相似，具有浓郁的民族风格。\n      西校门内是一座精心雕镂的石桥。正对西门的是校园的主要建筑，即现在的办公楼，其间空地上还耸立着从圆明园迁来的两只华表。西校门向西而行，是清代名园鸣鹤园的遗迹，往南的一片绿地和荷塘，是明末画家米万种勺园故址。\n      西门正中有“北京大学”四字匾额，由毛泽东主席在1950年应北大学生会请求的亲笔题字放大而成，与红色的校门浑然一体。");
        ui->title->setText("北大西门");
    }
    else if(index==9){
        this->setWindowTitle("邱德拔体育馆");
        img[0].load(":/new/prefix2/intro_imgs/imgs/83.jpg");
        img[1].load(":/new/prefix2/intro_imgs/imgs/81.jpg");
        img[2].load(":/new/prefix2/intro_imgs/imgs/82.jpg");
        ui->Last->setText("上个景点：北大西门");
        ui->Next->setText("下个景点：五四体育场");
        ui->label_image->setPixmap(QPixmap::fromImage(img[0]));
        ui->label->setText("      北京大学邱德拔体育馆于2005年9月17日正式动工，位于北京大学校内东南地区，毗邻中关村大街。\n      落成之后，它首先作为2008年北京奥运会乒乓球比赛场馆，向全世界展示中国“国球”的风采。体育馆建筑造型名为“中国脊”，意寓着民族之脊、北大之脊、国球之脊、建筑之脊，是北大风格与体育精神的结合。\n      如今，邱德拔体育馆已成为供全校师生员工使用的体育教学与活动基地，内有游泳馆、羽毛球场、击剑厅等种类齐全的体育设施，体现了北大“完全人格，首在体育”的教育理念。");
        ui->title->setText("邱德拔体育馆");
    }
    else if(index==10){
        this->setWindowTitle("五四体育场");
        img[0].load(":/new/prefix2/intro_imgs/imgs/93.jpg");
        img[1].load(":/new/prefix2/intro_imgs/imgs/91.jpg");
        img[2].load(":/new/prefix2/intro_imgs/imgs/92.jpg");
        ui->Last->setText("上个景点：邱德拔体育馆");
        ui->Next->setText("下个景点：计算中心");
        ui->label_image->setPixmap(QPixmap::fromImage(img[0]));
        ui->label->setText("      五四体育场是北京大学五四体育中心的主要组成部分，由中心足球场和塑胶跑道、篮球场、排球场、网球场、五人制足球场等设施组成，是北大师生员工室外体育锻炼的绝佳场地。\n      在五四，你永远可以体会到北大青春洋溢的运动氛围，如果有幸参与定期举办的“夜奔”活动，跟随不同主题的乐曲挥洒热情的汗水，一定会带给你一个难忘的夜晚。五四操场也是85km课外锻炼的指定运动场所。\n      2023年6月，五四体育场开始施工翻新，截至笔者写这段介绍时，尚未完成。");
        ui->title->setText("五四体育场");
    }
    else if(index==11){
        this->setWindowTitle("计算中心");
        img[0].load(":/new/prefix2/intro_imgs/imgs/103.png");
        img[1].load(":/new/prefix2/intro_imgs/imgs/101.jpg");
        img[2].load(":/new/prefix2/intro_imgs/imgs/102.jpg");
        ui->Last->setText("上个景点：五四体育场");
        ui->Next->setText("下个景点：博雅塔");
        ui->label_image->setPixmap(QPixmap::fromImage(img[0]));
        ui->label->setText("      你说得对，但是「计算中心」是由「北京大学信息科学技术学院」自主研发的一款全新开放世界冒险游戏。游戏发生在一个被称作「理科一号楼」的幻想世界，在这里，被「培养方案」选中的「学生」将被授予「C++之眼」，导引「Python」之力。你将扮演一位名为「类」的神秘角色在自由的旅行中邂逅性格各异、能力独特的「对象」们，和他们一起击败「bug」，找回失散的「AC」——同时，逐步发掘「绩点」的真相。");
        ui->title->setText("计算中心");
    }
    else if(index==19){
        this->setWindowTitle("生日快乐！");
        img[0].load(":/new/prefix1/lake.png");
        img[1].load(":/new/prefix1/lake.png");
        img[2].load(":/new/prefix1/lake.png");
        ui->Last->setText("上个景点：10010");
        ui->Next->setText("下个景点：10100");
        ui->label_image->setPixmap(QPixmap::fromImage(img[0]));
        ui->label->setText("       Happy Birthday! \n       2023.7.4");
        ui->title->setText("生日快乐！");
    }
}


void Introduction::on_Next_clicked()
{
    this->close();
    if(index!=0){
        next->show();
        next->on_change_background_activated(bg+1);
    }
}


void Introduction::on_Last_clicked()
{
    this->close();
    if(index!=0){
        last->show();
        last->on_change_background_activated(bg+1);
    }
}


void Introduction::on_change_background_activated(int index)
{
    if(index==2){
        bg=1;
        ui->change_background->setCurrentIndex(index);
        QPalette pal=this->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/background1.png").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
        setPalette(pal);
        QPalette pal2;
        pal2.setColor(QPalette::WindowText,Qt::black);
        ui->title->setPalette(pal2);
        ui->label->setPalette(pal2);
        ui->Last->setStyleSheet("color:black");
        ui->Next->setStyleSheet("color:black");
    }
    else if(index==3){
        bg=2;
        ui->change_background->setCurrentIndex(index);
        QPalette pal=this->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/background2.png").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
        setPalette(pal);
        QPalette pal2;
        pal2.setColor(QPalette::WindowText,Qt::black);
        ui->title->setPalette(pal2);
        ui->label->setPalette(pal2);
        ui->Last->setStyleSheet("color:black");
        ui->Next->setStyleSheet("color:black");
    }
    else if(index==4){
        bg=3;
        ui->change_background->setCurrentIndex(index);
        QPalette pal=this->palette();
        pal.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/background3.png").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
        setPalette(pal);
        QPalette pal2;
        pal2.setColor(QPalette::WindowText,Qt::white);
        ui->title->setPalette(pal2);
        ui->label->setPalette(pal2);
        ui->Last->setStyleSheet("color:white");
        ui->Next->setStyleSheet("color:white");
    }
    else{
        bg=-1;
        ui->change_background->setCurrentIndex(index);
        Introduction* tmp=new Introduction(-2);
        QPalette pal=tmp->palette();
        setPalette(pal);
        delete tmp;
        QPalette pal2;
        pal2.setColor(QPalette::WindowText,Qt::black);
        ui->title->setPalette(pal2);
        ui->label->setPalette(pal2);
        ui->Last->setStyleSheet("color:black");
        ui->Next->setStyleSheet("color:black");
    }
}



void Introduction::on_signbutton_clicked()
{
    itsbutton->setStyleSheet(tr("image:url(:/new/prefix1/locate_hl.png)"));
    this->close();
}




void Introduction::on_img_turnleft_clicked()
{
    currentimg--;
    if(currentimg<0)
        currentimg=2;
    ui->label_image->setPixmap(QPixmap::fromImage(img[currentimg]));
}


void Introduction::on_img_turnright_clicked()
{
    currentimg++;
    if(currentimg>2)
        currentimg=0;
    ui->label_image->setPixmap(QPixmap::fromImage(img[currentimg]));
}

