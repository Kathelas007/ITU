#ifndef CLOCKWINDOW_H
#define CLOCKWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ClockWindow; }
QT_END_NAMESPACE

class ClockWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClockWindow(QWidget *parent = nullptr);
    ~ClockWindow();

private slots:
    void on_toolButton_clicked();

private:
    Ui::ClockWindow *ui;
};
#endif // CLOCKWINDOW_H
