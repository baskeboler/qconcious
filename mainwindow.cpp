#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "gameagent.h"
#include "cheater.h"
#include "cooperator.h"
#include "randomagent.h"
#include "titsfortatsagent.h"
#include "gameimpl.h"
#include <QtCharts/QLineSeries>
#include <QtCharts>
using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), chart{new QChart}
{
    ui->setupUi(this);

    //    chart = new QChart();
    QChartView *view = new QChartView(chart);
    chart->setTitle("the whole story");
    chart->setDropShadowEnabled(true);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(2000);
    auto layout= new QVBoxLayout(ui->chartWidget);

    layout->addWidget(view);
//    ui->chartWidget->layout()->widget()
    ui->chartWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->roundCountLabel->setNum(value);
}

GameAgent *fromComboIndex(int idx) {
    switch (idx) {
    case 0: return new Cheater;
    case 1: return new Cooperator;
    case 2: return new RandomAgent;
    case 3: return new TitsForTatsAgent;
    default: break;
    }
    return nullptr;
}

void MainWindow::on_btnStart_clicked()
{
    auto a = fromComboIndex(ui->comboBox->currentIndex());
    auto b = fromComboIndex(ui->comboBox_2->currentIndex());

    chart->removeAllSeries();
    QLineSeries * series = new QLineSeries(), *series2= new QLineSeries;
    int rounds =ui->horizontalSlider->value();

    auto g = new GameImpl{a, b, rounds};
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(g->getRounds() - 1);
    ui->progressBar->setMinimum(0);
    connect(g, &AbstractGame::roundPlayed, this, [&](const RoundResult &result) {
        series->append(result.round, g->getScore(*g->getAgent1()));
        series2->append(result.round, g->getScore(*g->getAgent2()));
//        series->append(result.round, result.score1);
//        series2->append(result.round, result.score2);
        ui->lcdNumber->display(g->getScore(*a));
        ui->lcdNumber_2->display(g->getScore(*b));
        ui->progressBar->setValue(result.round);
    });
    g->playGame();

    ui->lcdNumber->display(g->getScore(*a));
    ui->lcdNumber_2->display(g->getScore(*b));

//    chart.set
    series->setName("agent 1");
    series2->setName("agent 2");
    chart->addSeries(new QAreaSeries(series));
    chart->addSeries(new QAreaSeries(series2));
//    chart.set
    delete g;
    delete a;
    delete b;
}
