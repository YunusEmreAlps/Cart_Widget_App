#include "form.h"
#include "ui_form.h"

Form::Form(MainWindow *anafrm, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    query1 = new QSqlQuery(anafrm->db) ;
    general1 = new QSqlQuery(anafrm->db) ;
    model1 = new QSqlQueryModel() ;

    list() ;
}

Form::~Form()
{
    delete ui;
}

void Form::list()
{
    if(!query1->exec("select * from cart"))
    {
        QMessageBox::critical(this,"Query Error",query1->lastError().text());
    }


    query1->exec("select sum(result) from cart") ;
    model1->setQuery(*query1);
    ui->price->setText(model1->index(0,0).data().toString());
    query1->exec("select * from cart") ;
    model1->setQuery(*query1);
    ui->tableView2->setModel(model1);

}

void Form::on_tableView2_clicked(const QModelIndex &index)
{
    numin = model1->index(index.row(),0).data().toString() ;
}


void Form::on_dele_clicked()
{
    general1->prepare("delete from cart where cartid = ?") ;
    general1->addBindValue(numin) ;

    if(! general1->exec())
    {
        QMessageBox::critical(this,"delete problem",general1->lastError().text()) ;

    }

    list() ;
}

