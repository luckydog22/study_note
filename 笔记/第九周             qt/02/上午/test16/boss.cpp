#include "boss.h"
#include "ui_boss.h"

boss::boss(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::boss)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_btn()));
}

boss::~boss()
{
    delete ui;
}

void boss::slot_btn()
{
    emit my_signal();
}
