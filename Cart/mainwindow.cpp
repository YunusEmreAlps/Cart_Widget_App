#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include "Form.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase :: addDatabase("QSQLITE") ;
    db.setDatabaseName("C:/Users/Dell/Desktop/Qt-SQL/17010011005_YunusEmreAlpu/YunusEmreAlpu/database.db") ; // database file extension

    if(! db.open())
    {
        QMessageBox::critical(this,"database connection error",db.lastError().text()) ;
    }

    sorgu = new QSqlQuery(db) ;
    genel = new QSqlQuery(db) ;
    model = new QSqlQueryModel() ;

}

MainWindow::~MainWindow()
{
    delete ui;
}

// list information
void MainWindow::on_list_info_clicked()
{
    if(! sorgu->exec("select * from urunler")) // !! database table name
    {
        QMessageBox::critical(this,"database connection error",sorgu->lastError().text()) ;
    }

    model->setQuery(*sorgu) ;
    ui->tableView->setModel(model); // change tableview name
}


// this function important for delete and update
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    num =  model->index(index.row(),0).data().toString() ;
    num2 = model->index(index.row(),2).data().toString() ;
    num3 = model->index(index.row(),3).data().toInt() ;

    num4 = ui->Adet->text().toInt();



}


// add information
void MainWindow::on_add_clicked()
{
    genel ->prepare(" insert into sepet values(?,?,?,?,?)") ; // database table name

    genel ->addBindValue(num)  ;
    genel ->addBindValue(num2) ;
    genel ->addBindValue(num3) ;

    if(num4 < 1)
    {
        num4 = 1 ;

        ui->Adet->setText("1") ;
    }
    genel ->addBindValue(num4) ;

    genel ->addBindValue(num3*num4) ;


    if(! genel->exec())
    {
        QMessageBox::critical(this,"add problem",genel->lastError().text()) ;
    }

    // list() ;
}

void MainWindow::on_Box_clicked()
{
    Form *sep = new Form(this);
    sep->show();
}






