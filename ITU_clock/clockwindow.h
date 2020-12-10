#ifndef CLOCKWINDOW_H
#define CLOCKWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QToolButton>
#include <QGridLayout>

class ClockWindow : public QMainWindow
{
    Q_OBJECT

public:
    ClockWindow(QWidget *parent = nullptr);

private slots:

private:
    QGridLayout* buttonLayout;

    QToolButton* closeButton;
    QToolButton* minimButton;
    QToolButton* settingsButton;

    QGridLayout* setup_layout(QWidget* widget);
    QToolButton* display_close_button(QGridLayout* layout);
    QToolButton* display_minimize_button(QGridLayout* layout);
    QToolButton* display_settings_button(QGridLayout* layout);

    void display_clock();
};
#endif // CLOCKWINDOW_H
