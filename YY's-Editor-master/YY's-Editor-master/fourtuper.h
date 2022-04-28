#ifndef FOURTUPER_H
#define FOURTUPER_H

#include <QDialog>

namespace Ui {
class fourtuper;
}

class fourtuper : public QDialog
{
    Q_OBJECT

public:
    explicit fourtuper(QWidget *parent = nullptr);
    ~fourtuper();

private slots:
    void on_pushButton_clicked();

private:
    Ui::fourtuper *ui;
};

#endif // FOURTUPER_H
