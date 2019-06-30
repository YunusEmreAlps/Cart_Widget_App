#include "form.h"
#include "ui_form.h"

Form::Form(MainWindow *anafrm, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    sorgu1 = new QSqlQuery(anafrm->db) ;
    genel1 = new QSqlQuery(anafrm->db) ;
    model1 = new QSqlQueryModel() ;

    list() ;
}

Form::~Form()
{
    delete ui;
}

void Form::list()
{
    if(!sorgu1->exec("select * from sepet"))
    {
        QMessageBox::critical(this,"Sorgu Hatasi",sorgu1->lastError().text());
    }


    sorgu1->exec("select sum(tutar) from sepet") ;
    model1->setQuery(*sorgu1);
    ui->price->setText(model1->index(0,0).data().toString());
    sorgu1->exec("select * from sepet") ;
    model1->setQuery(*sorgu1);
    ui->tableView2->setModel(model1);

}

void Form::on_tableView2_clicked(const QModelIndex &index)
{
    numin = model1->index(index.row(),0).data().toString() ;
}


void Form::on_dele_clicked()
{
    genel1->prepare("delete from sepet where sepetid = ?") ;
    genel1->addBindValue(numin) ;

    if(! genel1->exec())
    {
        QMessageBox::critical(this,"delete problem",genel1->lastError().text()) ;

    }

    list() ;
}

