#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->calculationChoiceComboBox->addItems(possibleCalculations);
    if(ui->calculationChoiceComboBox->currentText() == "Aire") {
        ui->shapeLabel->setText("De quelle figure voulez vous calculer l'aire");
        ui->shapeComboBox->addItems(areaShapes);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
