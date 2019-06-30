#ifndef FORM_H
#define FORM_H

#include "mainwindow.h"
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlError>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(MainWindow *anafrm, QWidget *parent = nullptr);
    ~Form();

    void list() ;
    QString Result  = 0 ;

private slots:
    void on_dele_clicked();

    void on_tableView2_clicked(const QModelIndex &index);



private:
    Ui::Form *ui;

    QSqlQuery *query1 , *general1 ;
    QSqlQueryModel *model1 ;
    QString numin ; // index

};

#endif // FORM_H
