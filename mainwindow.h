#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widgets/TodoItem.h"
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void addTodo();

    void deleteTodo(TodoItem *item);

private:
    Ui::MainWindow *ui;

    void readFile(QString filename);
};

#endif // MAINWINDOW_H
