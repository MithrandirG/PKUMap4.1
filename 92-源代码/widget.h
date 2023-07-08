
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QWheelEvent>
#include<QFileDialog>
#include<QImage>
#include"introduction.h"
#include "error.h"
#include"pkulife.h"
#include "answer.h"
#define NN 11
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void wheelEvent(QWheelEvent *event);
    QString get_search_input(){
        return search_input;
    }
    QPushButton*buttons[15];
    void respond_search();

    void respond_asking();

    void change_buttons(int x);

    void unset_buttons();

private slots:

    void on_introduce_button_activated(int index);
    void on_search_line_editingFinished();

    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

    void on_button8_clicked();

    void on_button4_clicked();

    void on_button5_clicked();

    void on_button6_clicked();

    void on_button7_clicked();

    void on_button9_clicked();

    void on_button10_clicked();

    void on_button11_clicked();

    void on_pushButton_clicked();

    void on_button1_customContextMenuRequested();
    void on_button2_customContextMenuRequested();
    void on_button3_customContextMenuRequested();
    void on_button4_customContextMenuRequested();
    void on_button5_customContextMenuRequested();
    void on_button6_customContextMenuRequested();
    void on_button7_customContextMenuRequested();
    void on_button8_customContextMenuRequested();
    void on_button9_customContextMenuRequested();
    void on_button10_customContextMenuRequested();
    void on_button11_customContextMenuRequested();

    void on_menu_clicked_1_1();
    void on_menu_clicked_1_2();
    void on_menu_clicked_2_1();
    void on_menu_clicked_2_2();
    void on_menu_clicked_3_1();
    void on_menu_clicked_3_2();
    void on_menu_clicked_4_1();
    void on_menu_clicked_4_2();
    void on_menu_clicked_5_1();
    void on_menu_clicked_5_2();
    void on_menu_clicked_6_1();
    void on_menu_clicked_6_2();
    void on_menu_clicked_7_1();
    void on_menu_clicked_7_2();
    void on_menu_clicked_8_1();
    void on_menu_clicked_8_2();
    void on_menu_clicked_9_1();
    void on_menu_clicked_9_2();
    void on_menu_clicked_10_1();
    void on_menu_clicked_10_2();
    void on_menu_clicked_11_1();
    void on_menu_clicked_11_2();


    void on_viewline_button_activated(int index);

    void on_AI_qa_line_editingFinished();

    void on_backbutton_clicked();

    void on_clearsign_clicked();

    void on_pkulife_combox_activated(int index);

private:
    Ui::Widget *ui;
    int mapheight;//地图高度
    int mapwidth;//地图宽度
    int originalmapsize[2];
    int mapsize=1;//地图缩放倍数
    QString search_input=""; //搜索框输入的文本
    QString ask_input=""; //问答框输入的文本
    QImage smallimg;
    QImage middleimg;
    QImage bigimg;
    QImage routes[4];
    int routeindex=0;
    Error error[2];
    Answer answer[3]={Answer(1),Answer(2),Answer(3)};
    int mapbuttonsize[2];//记录button初始大小（避免精度误差）
    int mapbuttonxy[11][2];//记录button初始位置
    Introduction intro[11]={
        Introduction(1),
        Introduction(2),
        Introduction(3),
        Introduction(4),
        Introduction(5),
        Introduction(6),
        Introduction(7),
        Introduction(8),
        Introduction(9),
        Introduction(10),
        Introduction(11)};
    Introduction h=Introduction(19);
    Pkulife aa = Pkulife(1);
    Pkulife bb = Pkulife(2);
    Pkulife cc = Pkulife(3);
    Pkulife dd = Pkulife(4);
};

#endif // WIDGET_H
