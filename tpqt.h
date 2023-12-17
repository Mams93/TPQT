#ifndef TPQT_H
#define TPQT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class TPQT;
}
QT_END_NAMESPACE

class TPQT : public QMainWindow
{
    Q_OBJECT

public:
    TPQT(QWidget *parent = nullptr);
    ~TPQT();
    void affiche();
    void Boutonnotesjoueurs();
private:
    Ui::TPQT *ui;
};
#endif // TPQT_H
