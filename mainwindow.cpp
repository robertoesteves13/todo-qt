#include <QInputDialog>
#include <QLabel>
#include <widgets/TodoItem.h>
#include <QWidgetAction>
#include <iostream>
#include <QDebug>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    readFile("text.txt");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::deleteTodo(TodoItem *item) {
    ui->todo_list->removeWidget(item);
    delete item;
}

void MainWindow::addTodo() {
    QString text = QInputDialog::getText(this, tr("Add Todo"), tr("Todo name"), QLineEdit::Normal);

    TodoItem *item = new TodoItem(text);
    QObject::connect(item, SIGNAL(buttonClick(TodoItem * )), this, SLOT(deleteTodo(TodoItem * )));

    ui->todo_list->addWidget(item);
}

void MainWindow::readFile(QString filename) {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        while (!stream.atEnd()) {
            QString line = stream.readLine();

            TodoItem *item = new TodoItem(line);
            ui->todo_list->addWidget(item);
            QObject::connect(item, SIGNAL(buttonClick(TodoItem * )), this, SLOT(deleteTodo(TodoItem * )));
        }
    }

    file.close();
}
