#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
private:
    Ui::Dialog *ui;

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void onTextChanged(QString);

};
#endif // DIALOG_H
