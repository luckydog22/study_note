#ifndef BOSS_H
#define BOSS_H

#include <QMainWindow>

namespace Ui {
class boss;
}

class boss : public QMainWindow
{
    Q_OBJECT

public:
    explicit boss(QWidget *parent = 0);
    ~boss();

public slots:
    void slot_btn();

signals:
    void my_signal();

private:
    Ui::boss *ui;
};

#endif // BOSS_H
