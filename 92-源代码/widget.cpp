#include"introduction.h"
#include "widget.h"
#include "ui_widget.h"
#include "error.h"
#include<QWheelEvent>
#include<QMessageBox>
#include<QMenu>
#include"welcome.h"

void Widget::change_buttons(int x){
    if(x>0)
    {
        for(int i=0;i<NN;i++){
            buttons[i]->setGeometry(1.2*buttons[i]->x(),1.2*buttons[i]->y(),1.2*buttons[i]->width(),1.2*buttons[i]->height());
        }
    }
    else
        for(int i=0;i<NN;i++){
            buttons[i]->setGeometry(buttons[i]->x()/1.2,buttons[i]->y()/1.2,buttons[i]->width()/1.2,buttons[i]->height()/1.2);
        }
}
void Widget::unset_buttons(){

    for(int i=0;i<NN;i++){
        buttons[i]->setGeometry(mapbuttonxy[i][0],mapbuttonxy[i][1],mapbuttonsize[0],mapbuttonsize[1]);
    }

}
int next_number(int x){
    if(x>=NN-1) return 0;
    else return x+1;
}
int last_number(int x){
    if(x<=0) return NN-1;
    else return x-1;
}
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
    this->setWindowTitle("燕园地图导览");
    Qt::WindowFlags flags;
    flags|=Qt::Window;
    flags|=Qt::WindowCloseButtonHint;
    flags|=Qt::MSWindowsFixedSizeDialogHint;
    this->setWindowFlags(flags);
    //加载地图
    smallimg.load(":/new/prefix1/B_Map2.png");
    middleimg.load(":/new/prefix1/B_Map.png");
    bigimg.load(":/new/prefix1/map.jpg");
    routes[1].load(":/new/prefix3/route/west_route.png");
    routes[2].load(":/new/prefix3/route/east_route.png");
    routes[3].load(":/new/prefix3/route/south_route.png");
    //
    ui->map_label->setPixmap(QPixmap::fromImage(smallimg));
    search_input=ui->search_line->text();
   //初始化buttons，方便批处理（虽然有点丑陋）
    buttons[0]=ui->button1;
    buttons[1]=ui->button2;
    buttons[2]=ui->button3;
    buttons[3]=ui->button4;
    buttons[4]=ui->button5;
    buttons[5]=ui->button6;
    buttons[6]=ui->button7;
    buttons[7]=ui->button8;
    buttons[8]=ui->button9;
    buttons[9]=ui->button10;
    buttons[10]=ui->button11;
    //初始化一些数据
    mapwidth=ui->map_label->width();
    mapheight=ui->map_label->height();


    mapbuttonsize[0]=ui->button1->width();
    mapbuttonsize[1]=ui->button1->height();
    originalmapsize[0]= mapwidth;
    originalmapsize[1]= mapheight;
    for(int i=0;i<NN;i++){ //变量NN代表intro的个数
        mapbuttonxy[i][0]=buttons[i]->x()-1;
        mapbuttonxy[i][1]=buttons[i]->y();
    }
    //初始化intro
    for(int i=0;i<NN;++i){
        intro[i].loadimage();
        intro[i].last=&(intro[last_number(i)]);
        intro[i].next=&(intro[next_number(i)]);
        intro[i].itsbutton=buttons[i];
    }
    this->setStyleSheet("Widget {background-color:rgb(240, 233,216)}");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::wheelEvent(QWheelEvent *event)//实现地图放大缩小
{
    QPoint numDegrees;                                     // 定义指针类型参数numDegrees用于获取滚轮转角
    numDegrees = event->angleDelta();
        // 获取滚轮转角
    int step = 0;// 设置中间参数step用于将获取的数值转换成整数型


    if(!(event->position().rx()>=0&&event->position().rx()<=585&&event->position().ry()>=0&&event->position().ry()<=800))
        return ;
    if (!numDegrees.isNull())                              // 判断滚轮是否转动
    {
        step = numDegrees.y();                             // 将滚轮转动数值传给中间参数step
    }
    event->accept();                                       // 获取事件
    int currentWidth = mapwidth ;             // 获取当前图像的宽
    int currentHeight = mapheight;                // 获取当前图像的高

    if (step > 0)                                          // 判断图像是放大还是缩小
    {
        if(mapsize<10)
        {
            currentWidth *= 1.2;
            currentHeight *=1.2;
            change_buttons(1);
            mapsize++;
        }
    }
    else
    {
        if(mapsize>1)
        {
            currentWidth /= 1.2;
            currentHeight /=1.2;
            change_buttons(0);
            mapsize--;
        }
        if(mapsize==1){
            currentWidth = originalmapsize[0];
            currentHeight= originalmapsize[1];

            unset_buttons();
        }
    }
    QImage* imgScaled = new QImage;
    if(mapsize>3&&mapsize<=6)
    {
        *imgScaled=middleimg.scaled(currentWidth,currentHeight, Qt::KeepAspectRatio);
    }
    else if(mapsize<=3)
    {
        *imgScaled=smallimg.scaled(currentWidth, currentHeight, Qt::KeepAspectRatio);
    }
    else{
        *imgScaled=bigimg.scaled(currentWidth, currentHeight, Qt::KeepAspectRatio);
    }

    ui->scrollAreaWidgetContents->setMinimumSize(currentWidth, currentHeight);

    ui->map_label->setGeometry(0,0,currentWidth, currentHeight);
    ui->map_label->setPixmap(QPixmap::fromImage(*imgScaled)); // 通过更新图像显示控件的大小来更新图像大小

    QImage* imgScaled1 = new QImage;
    *imgScaled1=routes[routeindex].scaled(currentWidth, currentHeight, Qt::KeepAspectRatio);
    ui->routelabel->setGeometry(0,0,currentWidth, currentHeight);
    ui->routelabel->setPixmap(QPixmap::fromImage(*imgScaled1));

    mapwidth=currentWidth;
    mapheight= currentHeight;
}

void Widget::on_introduce_button_activated(int index)
{


    if(index!=0){
        intro[index-1].loadimage();
        intro[index-1].show();
       }

}

void Widget::respond_search(){
       if(search_input=="博雅塔"){
        intro[0].show();
       }
       else if(search_input=="未名湖"){
        intro[1].show();
       }
       else if(search_input=="俄文楼" || search_input=="元培楼"){
        intro[2].show();
       }
       else if(search_input=="北大图书馆"|| search_input=="图书馆"){
        intro[3].show();
       }
       else if(search_input=="静园"|| search_input=="静园草坪"){
        intro[4].show();
       }
       else if(search_input=="燕南园"){
        intro[5].show();
       }
       else if(search_input=="蔡元培铜像" || search_input=="蔡元培像"){
        intro[6].show();
       }
       else if(search_input=="北大西门" || search_input=="西门"){
        intro[7].show();
       }
       else if(search_input=="邱德拔体育馆" || search_input=="邱德拔" || search_input=="游泳馆"){
        intro[8].show();
       }
       else if(search_input=="五四体育场" || search_input=="五四" || search_input=="五四操场" || search_input=="五四运动场"){
        intro[9].show();
       }
       else if(search_input=="计算中心" || search_input=="理科一号楼" || search_input=="迷宫" || search_input=="Google"){
        intro[10].show();
       }
       else if(search_input=="20230704"){
        h.loadimage();
        h.show();
       }
       else{
        error[0].setWindowTitle("功能暂未开发");
        error[0].show();
       }
}


void Widget::on_search_line_editingFinished()
{
    search_input=ui->search_line->text();
    if(search_input!=""){
        this->respond_search();
    }
    ui->search_line->setText("");
}


void Widget::on_button1_clicked()
{
    intro[0].show();
}


void Widget::on_button2_clicked()
{
    intro[1].show();
}


void Widget::on_button3_clicked()
{
    intro[2].show();
}


void Widget::on_button4_clicked()
{
    intro[3].show();
}


void Widget::on_button5_clicked()
{
    intro[4].show();
}

void Widget::on_button6_clicked()
{
    intro[5].show();
}


void Widget::on_button7_clicked()
{
    intro[6].show();
}

void Widget::on_button8_clicked()
{
    intro[7].show();
}

void Widget::on_button9_clicked()
{
    intro[8].show();
}


void Widget::on_button10_clicked()
{
    intro[9].show();
}


void Widget::on_button11_clicked()
{
    intro[10].show();
}


void Widget::on_pushButton_clicked()
{
    for(int i=0;i<NN;++i){
        buttons[i]->setStyleSheet(tr("image:url(:/new/prefix1/locate.png)"));
    }
}


void Widget::on_button1_customContextMenuRequested()
{
    QMenu *cmenu = new QMenu();
    QAction *action1 = new QAction(tr("标记"),this);
    QAction *action2 = new QAction(tr("清除标记"), this);
    action1->setData(1);
    action2->setData(2);
    cmenu->addAction(action1);
    cmenu->addAction(action2);
    connect(action1, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_1_1()));
    connect(action2, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_1_2()));
    cmenu->exec(QCursor::pos());
}

void Widget::on_menu_clicked_1_1(){
    ui->button1->setStyleSheet(tr("image:url(:/new/prefix1/locate_hl.png)"));
}
void Widget::on_menu_clicked_1_2(){
    ui->button1->setStyleSheet(tr("image:url(:/new/prefix1/locate.png)"));
}

void Widget::on_button2_customContextMenuRequested()
{
    QMenu *cmenu = new QMenu();
    QAction *action1 = new QAction(tr("标记"),this);
    QAction *action2 = new QAction(tr("清除标记"), this);
    action1->setData(1);
    action2->setData(2);
    cmenu->addAction(action1);
    cmenu->addAction(action2);
    connect(action1, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_2_1()));
    connect(action2, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_2_2()));
    cmenu->exec(QCursor::pos());
}

void Widget::on_menu_clicked_2_1(){
    ui->button2->setStyleSheet(tr("image:url(:/new/prefix1/locate_hl.png)"));
}
void Widget::on_menu_clicked_2_2(){
    ui->button2->setStyleSheet(tr("image:url(:/new/prefix1/locate.png)"));
}

void Widget::on_button3_customContextMenuRequested()
{
    QMenu *cmenu = new QMenu();
    QAction *action1 = new QAction(tr("标记"),this);
    QAction *action2 = new QAction(tr("清除标记"), this);
    action1->setData(1);
    action2->setData(2);
    cmenu->addAction(action1);
    cmenu->addAction(action2);
    connect(action1, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_3_1()));
    connect(action2, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_3_2()));
    cmenu->exec(QCursor::pos());
}

void Widget::on_menu_clicked_3_1(){
    ui->button3->setStyleSheet(tr("image:url(:/new/prefix1/locate_hl.png)"));
}
void Widget::on_menu_clicked_3_2(){
    ui->button3->setStyleSheet(tr("image:url(:/new/prefix1/locate.png)"));
}


void Widget::on_button4_customContextMenuRequested()
{
    QMenu *cmenu = new QMenu();
    QAction *action1 = new QAction(tr("标记"),this);
    QAction *action2 = new QAction(tr("清除标记"), this);
    action1->setData(1);
    action2->setData(2);
    cmenu->addAction(action1);
    cmenu->addAction(action2);
    connect(action1, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_4_1()));
    connect(action2, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_4_2()));
    cmenu->exec(QCursor::pos());
}

void Widget::on_menu_clicked_4_1(){
    ui->button4->setStyleSheet(tr("image:url(:/new/prefix1/locate_hl.png)"));
}
void Widget::on_menu_clicked_4_2(){
    ui->button4->setStyleSheet(tr("image:url(:/new/prefix1/locate.png)"));
}


void Widget::on_button5_customContextMenuRequested()
{
    QMenu *cmenu = new QMenu();
    QAction *action1 = new QAction(tr("标记"),this);
    QAction *action2 = new QAction(tr("清除标记"), this);
    action1->setData(1);
    action2->setData(2);
    cmenu->addAction(action1);
    cmenu->addAction(action2);
    connect(action1, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_5_1()));
    connect(action2, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_5_2()));
    cmenu->exec(QCursor::pos());
}

void Widget::on_menu_clicked_5_1(){
    ui->button5->setStyleSheet(tr("image:url(:/new/prefix1/locate_hl.png)"));
}
void Widget::on_menu_clicked_5_2(){
    ui->button5->setStyleSheet(tr("image:url(:/new/prefix1/locate.png)"));
}


void Widget::on_button6_customContextMenuRequested()
{
    QMenu *cmenu = new QMenu();
    QAction *action1 = new QAction(tr("标记"),this);
    QAction *action2 = new QAction(tr("清除标记"), this);
    action1->setData(1);
    action2->setData(2);
    cmenu->addAction(action1);
    cmenu->addAction(action2);
    connect(action1, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_6_1()));
    connect(action2, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_6_2()));
    cmenu->exec(QCursor::pos());
}

void Widget::on_menu_clicked_6_1(){
    ui->button6->setStyleSheet(tr("image:url(:/new/prefix1/locate_hl.png)"));
}
void Widget::on_menu_clicked_6_2(){
    ui->button6->setStyleSheet(tr("image:url(:/new/prefix1/locate.png)"));
}


void Widget::on_button7_customContextMenuRequested()
{
    QMenu *cmenu = new QMenu();
    QAction *action1 = new QAction(tr("标记"),this);
    QAction *action2 = new QAction(tr("清除标记"), this);
    action1->setData(1);
    action2->setData(2);
    cmenu->addAction(action1);
    cmenu->addAction(action2);
    connect(action1, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_7_1()));
    connect(action2, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_7_2()));
    cmenu->exec(QCursor::pos());
}

void Widget::on_menu_clicked_7_1(){
    ui->button7->setStyleSheet(tr("image:url(:/new/prefix1/locate_hl.png)"));
}
void Widget::on_menu_clicked_7_2(){
    ui->button7->setStyleSheet(tr("image:url(:/new/prefix1/locate.png)"));
}


void Widget::on_button8_customContextMenuRequested()
{
    QMenu *cmenu = new QMenu();
    QAction *action1 = new QAction(tr("标记"),this);
    QAction *action2 = new QAction(tr("清除标记"), this);
    action1->setData(1);
    action2->setData(2);
    cmenu->addAction(action1);
    cmenu->addAction(action2);
    connect(action1, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_8_1()));
    connect(action2, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_8_2()));
    cmenu->exec(QCursor::pos());
}

void Widget::on_menu_clicked_8_1(){
    ui->button8->setStyleSheet(tr("image:url(:/new/prefix1/locate_hl.png)"));
}
void Widget::on_menu_clicked_8_2(){
    ui->button8->setStyleSheet(tr("image:url(:/new/prefix1/locate.png)"));
}


void Widget::on_button9_customContextMenuRequested()
{
    QMenu *cmenu = new QMenu();
    QAction *action1 = new QAction(tr("标记"),this);
    QAction *action2 = new QAction(tr("清除标记"), this);
    action1->setData(1);
    action2->setData(2);
    cmenu->addAction(action1);
    cmenu->addAction(action2);
    connect(action1, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_9_1()));
    connect(action2, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_9_2()));
    cmenu->exec(QCursor::pos());
}

void Widget::on_menu_clicked_9_1(){
    ui->button9->setStyleSheet(tr("image:url(:/new/prefix1/locate_hl.png)"));
}
void Widget::on_menu_clicked_9_2(){
    ui->button9->setStyleSheet(tr("image:url(:/new/prefix1/locate.png)"));
}


void Widget::on_button10_customContextMenuRequested()
{
    QMenu *cmenu = new QMenu();
    QAction *action1 = new QAction(tr("标记"),this);
    QAction *action2 = new QAction(tr("清除标记"), this);
    action1->setData(1);
    action2->setData(2);
    cmenu->addAction(action1);
    cmenu->addAction(action2);
    connect(action1, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_10_1()));
    connect(action2, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_10_2()));
    cmenu->exec(QCursor::pos());
}

void Widget::on_menu_clicked_10_1(){
    ui->button10->setStyleSheet(tr("image:url(:/new/prefix1/locate_hl.png)"));
}
void Widget::on_menu_clicked_10_2(){
    ui->button10->setStyleSheet(tr("image:url(:/new/prefix1/locate.png)"));
}


void Widget::on_button11_customContextMenuRequested()
{
    QMenu *cmenu = new QMenu();
    QAction *action1 = new QAction(tr("标记"),this);
    QAction *action2 = new QAction(tr("清除标记"), this);
    action1->setData(1);
    action2->setData(2);
    cmenu->addAction(action1);
    cmenu->addAction(action2);
    connect(action1, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_11_1()));
    connect(action2, SIGNAL(triggered(bool)), this, SLOT(on_menu_clicked_11_2()));
    cmenu->exec(QCursor::pos());
}

void Widget::on_menu_clicked_11_1(){
    ui->button11->setStyleSheet(tr("image:url(:/new/prefix1/locate_hl.png)"));
}
void Widget::on_menu_clicked_11_2(){
    ui->button11->setStyleSheet(tr("image:url(:/new/prefix1/locate.png)"));
}


void Widget::on_pkulife_combox_activated(int index)
{

    if(index==1){
        aa.show();
        aa.load_image();
    }
    if(index==2){
        bb.show();
        bb.load_image();
    }
    if(index==3){
        cc.show();
        cc.load_image();
    }
    if(index==4){
        dd.show();
        dd.load_image();
    }
}


void Widget::on_viewline_button_activated(int index)
{
    routeindex=index;
    QImage* imgScaled1 = new QImage;
    *imgScaled1=routes[routeindex].scaled(mapwidth, mapheight, Qt::KeepAspectRatio);
    ui->routelabel->setGeometry(0,0,mapwidth, mapheight);
    ui->routelabel->setPixmap(QPixmap::fromImage(*imgScaled1));
}


void Widget::on_AI_qa_line_editingFinished()
{
    ask_input=ui->AI_qa_line->text();
    if(ask_input!=""){
        this->respond_asking();
    }
    ui->AI_qa_line->setText("");
}

void Widget::respond_asking(){
    if(ask_input=="距离博雅塔最近的景点"
        ||ask_input=="离博雅塔最近的景点"
        ||ask_input=="搜索距离博雅塔最近的景点"
        ||ask_input=="哪个景点离博雅塔最近？"
        ||ask_input=="哪里离博雅塔最近？"
        ||ask_input=="距离博雅塔最近的景点是哪里？"
        ||ask_input=="离博雅塔最近的景点是哪里？"
        ||ask_input=="博雅塔附近的湖叫什么？"){
        answer[0].formore_ptr=&intro[1];
        answer[0].setWindowTitle("智能问答助手");
        answer[0].setText("检测到您的问题是：距离博雅塔最近的景点\n\n距离博雅塔最近的景点是：未名湖");
        answer[0].show();
    }
    else if(ask_input=="《程序设计实习》的上机地点在哪里？"
        ||ask_input=="程序设计实习的上机地点在哪里？"
        ||ask_input=="程序设计实习在哪上机？"
        ||ask_input=="程序设计实习在哪上机"
        ||ask_input=="程设在哪上机？"
        ||ask_input=="程设在哪上机"
        ||ask_input=="程设上机在哪签到"
        ||ask_input=="程设上机在哪签到？"){
        answer[1].formore_ptr=&intro[10];
        answer[1].setWindowTitle("智能问答助手");
        answer[1].setText("检测到您的问题是：《程序设计实习》的上机地点在哪里？\n\n《程序设计实习》的上机地点是：计算中心1235");
        answer[1].show();
    }
    else if(ask_input=="元培学院的院楼在哪？"
             ||ask_input=="元培院楼在哪里？"
             ||ask_input=="俄文楼是什么？"
             ||ask_input=="如何找到元培学院的教务？"
             ||ask_input=="如何找到元培学院的院楼？"
             ||ask_input=="李大钊像在哪里？"
             ||ask_input=="如何找到元培学院的老师？"
             ||ask_input=="元培院楼在哪里"){
        answer[2].formore_ptr=&intro[2];
        answer[2].setWindowTitle("智能问答助手");
        answer[2].setText("检测到与您问题相关的景点：俄文楼");
        answer[2].show();
    }
    else if(ask_input=="有哪些问题可以问？"
             ||ask_input=="有哪些问题可以问"
             ||ask_input=="可以问哪些问题"
             ||ask_input=="都能问哪些问题"
             ||ask_input=="可以问哪些问题？"
             ||ask_input=="都能问哪些问题？"){
        error[1].setWindowTitle("实际上可以问的问题");
        error[1].setText("距离博雅塔最近的景点/离博雅塔最近的景点/搜索距离博雅塔最近的景点/哪个景点离博雅塔最近/哪里离博雅塔最近？/距离博雅塔最近的景点是哪里？/离博雅塔最近的景点是哪里？/博雅塔附近的湖叫什么？/《程序设计实习》的上机地点在哪里？/程序设计实习的上机地点在哪里？/程序设计实习在哪上机？/程序设计实习在哪上机/程设在哪上机？/程设在哪上机/程设上机在哪签到/程设上机在哪签到？/元培学院的院楼在哪?/元培院楼在哪里?/俄文楼是什么？/如何找到元培学院的教务？/如何找到元培学院的院楼？/李大钊像在哪里？/如何找到元培学院的老师?/元培院楼在哪里");
        error[1].show();
    }
    else{
        error[1].setWindowTitle("您的试用次数已达上限");
        error[1].setText("抱歉！您的智能问答功能试用次数已达上限！\n如需继续使用，请升级至会员版。");
        error[1].show();
    }
}

void Widget::on_backbutton_clicked()
{
    Welcome*ww=new Welcome;
    this->close();
    ww->show();


}


void Widget::on_clearsign_clicked()
{
    for(int i=0;i<NN;++i){
        buttons[i]->setStyleSheet(tr("image:url(:/new/prefix1/locate.png)"));
    }
}

