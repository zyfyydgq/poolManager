#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include "circular.h"
#include "rectangle.h"
#include "math.h"
#include <QString>
#include <QDebug>
#include <QButtonGroup>
#include <QPushButton>
#include <calculate.h>
#include <QMessageBox>
#include <QFile>


double pre_budget = 0;
double pre_area = 0;
bool same = false;
int pre_btn_type = -1;


MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("方案生成器");
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}



void MyMainWindow::on_btn_1_clicked()
{
    double budget = ui->input_1->text().toDouble();
    double area = ui->input_2->text().toDouble();

    double use_budget = 0;
    double side = 0;
    int flag = 0;
    QString plan, plan_res;

    if (pre_budget == budget and pre_area == area){
        same = true;
    }else
        same = false;

    QButtonGroup *grp=new QButtonGroup(this);
    grp->addButton(ui->type1);
    grp->addButton(ui->type2);
    ui->label_title->setText(QString("方案草图"));
    ui->label_title_2->setText(QString("方案详情"));
    ui->label_image->setPixmap(QPixmap(":/image/img/plan.jpg"));
    ui->label_image->setScaledContents(true);
    if (ui->type2 == grp->checkedButton())
    {
        flag = 0;
        // 初始化
        if (pre_btn_type == -1){
            pre_btn_type = 0;
        }
    }
    else if (ui->type1 == grp->checkedButton()) {
        flag = 1;
        if (pre_btn_type == -1){
            pre_btn_type = 1;
        }
    }
    plan = QString("树造价：%1元/平方米\n").arg(tree_price);
    plan.append(QString("树造价：%1元/平方米\n").arg(tree_price));
    plan.append(QString("超市造价：%1元/平方米\n").arg(shop_price));
    plan.append(QString("更衣室造价：%1元/平方米\n").arg(locker_price));
    plan.append(QString("泳池造价：%1元/平方米\n").arg(poor_price));
    plan.append(QString("过道造价：%1元/米\n").arg(fence_price));
    plan.append(QString("休息区造价：%1元/平方米\n").arg(reat_price));
    plan.append(QString("草总造价：%1元\n").arg(grass_price));
    plan_res = calculate(area, budget, use_budget, side, flag);
    plan.append(plan_res);
    this->ui->res->setText(plan);


    if (!same or pre_btn_type != flag){
        // 将方案写入文件
        QString filename = "res.txt";        //当前文件夹中
        QFile file(filename);
        if(!file.open(QIODevice::ReadWrite|QIODevice::Text | QIODevice::Append))
        {
            QMessageBox::warning(this,"file write","can't open",QMessageBox::Yes);
        }
        QTextStream in(&file);
        in << plan << endl;

    }
    // 更新全局变量的值
    pre_budget = budget;
    pre_area = area;
    pre_btn_type = flag;

}
