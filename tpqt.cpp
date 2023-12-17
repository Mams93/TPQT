#include "tpqt.h"
#include "ui_tpqt.h"
#include <QHBoxLayout>
#include <QSqlTableModel>
TPQT::TPQT(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TPQT)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("Joueurs");

    db.setUserName("student");
    db.setPassword("crif2024sn");
    if(db.open())
    {
        qDebug() << "Vous etes maintenat connecté";
    }
    else{
        qDebug() << "La connexion a échouée, désolé";
    }
    QPushButton *bouton;
    bouton = new QPushButton(QString::fromUtf8("Quitter"), this);
    QHBoxLayout *hlayout1 = new QHBoxLayout;
    hlayout1->addWidget(bouton);

    connect(ui->BoutonAffiche, &QPushButton::clicked, this, &TPQT::affiche);
}

void TPQT::affiche(){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("Select * from Foot");
    ui->tableView->setModel(model);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("Equipements");

    db.setUserName("student");
    db.setPassword("crif2024sn");

    if(db.open())
    {
        qDebug() << "Vous etes maintenat connecté";
    }
    else{
        qDebug() << "La connexion a échouée, désolé";
    }
}

TPQT::~TPQT()
{
    delete ui;
}
