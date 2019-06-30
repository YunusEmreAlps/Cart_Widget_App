#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlError>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSqlDatabase db ;
    QString num , num1, num2 ; // index

    int num3 , num4 ;

private slots:

    void on_list_info_clicked();

    void on_add_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_Box_clicked();

private:
    Ui::MainWindow *ui;

    // database process (list, add, update, delete)

    QSqlQuery *query , *general ;
    QSqlQueryModel *model ;


    QString ch ;
};

#endif // MAINWINDOW_H
