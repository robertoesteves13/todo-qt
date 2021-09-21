//
// Created by robertolopesesteves on 21/09/2021.
//

#include <mainwindow.h>
#include <QStackedWidget>
#include <QAbstractItemView>
#include <QTextStream>
#include <QDebug>
#include "TodoItem.h"

TodoItem::TodoItem(const QString &label) {
    todoTitle->setText(label);
    todoTitle->setFlat(true);
    todoTitle->setStyleSheet("text-align: left;");
    connect(todoTitle, SIGNAL(clicked()), this, SLOT(changeToLineEdit()));

    connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(changeToTodoTitle()));

    todoDelete->setText("x");

    QFont font;
    font.setPointSize(8);
    todoDelete->setFont(font);

    todoDelete->setStyleSheet("text-align: right;");
    todoDelete->setMaximumWidth(25);
    todoDelete->setFlat(true);
    connect(todoDelete, SIGNAL(pressed()), this, SLOT(buttonListener()));

    connect(checkBox, SIGNAL(stateChanged(int)), this, SLOT(changeTitleDecoration(int)));

    stack->addWidget(todoTitle);
    stack->addWidget(lineEdit);

    layout->addWidget(todoDelete);
    layout->addWidget(stack);
    layout->addWidget(checkBox);
    this->setLayout(layout);
}

void TodoItem::buttonListener() {
    this->checkBox->setChecked(true);
    emit buttonClick(this);
}

void TodoItem::changeToLineEdit() {
    lineEdit->setText(todoTitle->text());
    stack->setCurrentWidget(lineEdit);
}

void TodoItem::changeToTodoTitle() {
    todoTitle->setText(lineEdit->text());
    stack->setCurrentWidget(todoTitle);
}

TodoItem::~TodoItem() {
    this->writeFile();
    this->destroy();
}

void TodoItem::changeTitleDecoration(int isChecked) {
    QFont font;
    if (isChecked) {
        font.setStrikeOut(true);
        font.setItalic(true);
    } else {
        font.setOverline(false);
    }

    todoTitle->setFont(font);
}

void TodoItem::writeFile() {
    QFile file("text.txt");

    if (file.open(QIODevice::WriteOnly) && !this->checkBox->isChecked()) {
        QTextStream stream(&file);
        stream << this->todoTitle->text() << endl;
    }

    file.close();
}
