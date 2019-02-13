#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStringList possibleCalculations{"Périmètre", "Aire", "Volume", "Théorème"};
    QStringList areaShapes{"Rectangle", "Carré", "Disque", "Parallèlogramme", "Triangle", "Trapèze", "Losange", "Sphère", "Cône", "Cube", "Parallélépipède rectangle", "Cylindre", "Pyramide à base carrée"};
    QStringList perimeterShapes{"Rectangle", "Carré", "Cercle", "Parallèlogramme", "Triangle", "Trapèze", "Losange"};
    QStringList volumeShapes{"Cube", "Parallélépipède rectangle", "Cylindre", "Cône", "Pyramide à base carrée", "Pyramide à base rectangulaire", "Sphère"};
    QStringList theorems{"Pythagore", "Thalès"};
    QStringList pythagoreVersion{"Hypoténuse", "Autre côté"};
    QStringList thalesVersion{"Numérateur", "Dénominateur"};

private slots:
    void setListInBox(const QString &arg1);
};

#endif // MAINWINDOW_H
