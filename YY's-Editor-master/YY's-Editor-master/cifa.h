#ifndef CIFA_H
#define CIFA_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class cifa;
}

class cifa : public QDialog
{
    Q_OBJECT

public:
    explicit cifa(QWidget *parent = nullptr);
    ~cifa();

private slots:
    void on_pushButton_clicked();

private:
    Ui::cifa *ui;
};

#endif // CIFA_H
