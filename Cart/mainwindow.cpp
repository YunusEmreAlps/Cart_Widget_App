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
    db.setDatabaseName("C:/Users/Dell/Desktop/Git_Qt/4. ) Cart_Widget_App/Cart/database.db") ; // database file extension

    if(! db.open())
    {
        QMessageBox::critical(this,"database connection error",db.lastError().text()) ;
    }

    query = new QSqlQuery(db) ;
    general = new QSqlQuery(db) ;
    model = new QSqlQueryModel() ;

}

MainWindow::~MainWindow()
{
    delete ui;
}

// list information
void MainWindow::on_list_info_clicked()
{
    if(! query->exec("select * from products")) // !! database table name
    {
        QMessageBox::critical(this,"database connection error",query->lastError().text()) ;
    }

    model->setQuery(*query) ;
    ui->tableView->setModel(model); // change tableview name
}


// this function important for delete and update
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    num = 1 ;
    num2 = 1 ;
    num4 = 1 ;

    num =  model->index(index.row(),0).data().toString() ;
    num2 = model->index(index.row(),2).data().toString() ;
    num3 = model->index(index.row(),3).data().toInt() ;

    num4 = ui->Adet->text().toInt();

    control = 1 ;

}


// add information
void MainWindow::on_add_clicked()
{

    if(control == 1)
    {

        general ->prepare(" insert into cart values(?,?,?,?,?)") ; // database table name

        general ->addBindValue(num)  ;
        general ->addBindValue(num2) ;

        if(num3 > 10000)
        {
            num3 = 1 ;
        }

        general ->addBindValue(num3) ;

        if((num4 < 1)||(num4 > 30))
        {
            num4 = 1 ;

            ui->Adet->setText("1") ;
        }
        general ->addBindValue(num4) ;

        general ->addBindValue(num3*num4) ;


        if(! general->exec())
        {
            QMessageBox::critical(this,"add problem",general->lastError().text()) ;
        }


    }

    else {

        QMessageBox::critical(this,"Error","Please choose  product") ;

    }

    control = 0 ;

    // list() ;
}

void MainWindow::on_Box_clicked()
{
    Form *sep = new Form(this);
    sep->show();
}






