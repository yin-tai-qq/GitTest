#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
  ui->comboBox->clear();
}

void MainWindow::on_pushButton_clicked()
{
  ui->comboBox->clear();
  QStringList strList;
  strList<<"北京"<<"shanghai"<<"tianjin";
  ui->comboBox->addItems(strList);
}


void MainWindow::on_pushButton_3_clicked()
{
    QMap<QString,int> mapCity;
    mapCity.insert("beijing",10);
    mapCity.insert("tianjin",20);
    ui->comboBox_2->clear();
    foreach (const QString &str, mapCity.keys()) {
        ui->comboBox_2->addItem(str,mapCity.value(str));
    }
}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString zone=ui->comboBox_2->currentData().toString();
    ui->plainTextEdit->appendPlainText(arg1+","+zone);

}

void MainWindow::on_pushButton_4_clicked()
{
    QTextDocument *doc=ui->plainTextEdit->document();
    int cnt=doc->blockCount();
    ui->comboBox->clear();
    for (int i= 0; i < cnt;i ++) {
        QTextBlock textLine=doc->findBlockByNumber(i);
        QString str=textLine.text();
        ui->comboBox->addItem(str);
    }
}

void MainWindow::on_plainTextEdit_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu=ui->plainTextEdit->createStandardContextMenu();
    menu->exec(pos);
}
