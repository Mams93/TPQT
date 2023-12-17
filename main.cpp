#include "tpqt.h"
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TPQT w;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("Joueurs");

    db.setUserName("student");
    db.setPassword("crif2024sn");
    if(db.open())
    {
        qDebug() << "Vous etes maintenat connecté a" <<db.hostName() ;
                                                        QSqlQuery query;

        query.exec("SELECT * FROM `Foot` ");
        while(query.next() ) {
            QString ID = query.value(0).toString();
            QString Prenom = query.value(1).toString();
            QString Age =query.value(2).toString();
            QString Club = query.value(3).toString();
            qDebug() <<"\t|"<< ID <<"\t|" << Prenom << "\t|" <<Age <<"\t|"<<Club;

        }
        qDebug() << "Requete ok ! :)" ;
        db.close();
    }
    else
    {
        qDebug() <<"La connexion a échouée, désolé" << db.lastError().text();
    }

    w.show();
    w.affiche();
    return a.exec();
}
