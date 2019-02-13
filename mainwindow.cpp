#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->calculationChoiceComboBox->addItems(possibleCalculations);
    auto a = new QAction(this);
    auto w = new QWidget(this);
    QObject::connect(a, &QComboBox::currentTextChanged, w, &MainWindow::setListInBox));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setListInBox(const QString &arg1)
{
    if(arg1 == "Aire") {
        ui->shapeComboBox->addItems(areaShapes);
        ui->shapeLabel->setText("De quelle figure voulez vous calculer l'aire ?");
    }

    else if(arg1 == "Périmètre") {
        ui->shapeComboBox->addItems(perimeterShapes);
        ui->shapeLabel->setText("De quelle figure voulez vous calculer le périmètre ?");
    }

    else if(arg1 == "Volume") {
        ui->shapeComboBox->addItems(volumeShapes);
        ui->shapeLabel->setText("De quelle figure voulez vous calculer le volume ?");
    }

    else if(arg1 == "Théorème") {
        ui->shapeComboBox->addItems(theorems);
        ui->shapeLabel->setText("Quel théorème voulez vous utiliser ?");
    }
}
