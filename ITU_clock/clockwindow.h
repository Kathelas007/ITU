#ifndef CLOCKWINDOW_H
#define CLOCKWINDOW_H

#include <QMainWindow>
#include <QWidget>

class ClockWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClockWindow(QWidget *parent = nullptr);

private slots:

private:
    void setup_layout();
    void display_close_button();
    void display_minimize_button();

    void display_clock();
};
#endif // CLOCKWINDOW_H
