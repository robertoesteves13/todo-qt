//
// Created by robertolopesesteves on 21/09/2021.
//

#ifndef TODO_TODOITEM_H
#define TODO_TODOITEM_H


#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QCheckBox>

class TodoItem : public QWidget {
Q_OBJECT
public:
    TodoItem(const QString &label);

    ~TodoItem();

private:
    QHBoxLayout *layout = new QHBoxLayout();
    QCheckBox *checkBox = new QCheckBox();
    QPushButton *todoDelete = new QPushButton();
    QPushButton *todoTitle = new QPushButton();
    QStackedWidget *stack = new QStackedWidget();
    QLineEdit *lineEdit = new QLineEdit();

    void writeFile();

signals:

    TodoItem *buttonClick(TodoItem *widget);

private slots:

    void buttonListener();

    void changeToLineEdit();

    void changeToTodoTitle();

    void changeTitleDecoration(int isChecked);
};


#endif //TODO_TODOITEM_H
