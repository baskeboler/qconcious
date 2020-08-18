#include "mainwindow.h"

#include <QtCharts/QLineSeries>
#include <QtCharts>

#include "./ui_mainwindow.h"
#include "cheater.h"
#include "cooperator.h"
#include "gameagent.h"
#include "gameimpl.h"
#include "randomagent.h"
#include "strategies.h"
#include "strategygameagent.h"
#include "titsfortatsagent.h"
#include "utils.h"

using namespace QtCharts;

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
  , chart{ new QChart }
{
  ui->setupUi(this);

  ui->webImage->setUrl(
    "http://searchengineland.com/figz/wp-content/seloads/2015/12/"
    "google-amp-fast-speed-travel-ss-1920-800x450.jpg");

  //    chart = new QChart();
  QChartView* view = new QChartView(chart);
  chart->setTitle("the whole story");
  chart->setDropShadowEnabled(true);
  chart->setAnimationOptions(QChart::AllAnimations);
  chart->setAnimationDuration(2000);
  auto layout = new QVBoxLayout(ui->chartWidget);

  layout->addWidget(view);
  //    ui->chartWidget->layout()->widget()
  ui->chartWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void
MainWindow::on_horizontalSlider_valueChanged(int value)
{
  ui->roundCountLabel->setNum(value);
}

GameAgent*
fromComboIndex(int idx)
{
  switch (idx) {
    case 0:
      return StrategyGameAgent::buildAgent<CheaterStrategy>(); // new Cheater;
    case 1:
      return StrategyGameAgent::buildAgent<CooperatorStrategy>();
      ;
    case 2:
      return StrategyGameAgent::buildAgent<RandomStrategy>();
      ;
    case 3:
      return StrategyGameAgent::buildAgent<ForgivingStrategy<3>>();
      ;
    default:
      break;
  }
  return nullptr;
}

void
MainWindow::on_btnStart_clicked()
{
  auto a = fromComboIndex(ui->comboBox->currentIndex());
  auto b = fromComboIndex(ui->comboBox_2->currentIndex());

  chart->removeAllSeries();
  QLineSeries *series = new QLineSeries(), *series2 = new QLineSeries;
  int rounds = ui->horizontalSlider->value();
  auto axis = new QValueAxis;
  axis->setGridLineVisible();
  axis->setLabelsVisible();
  axis->setMin(ui->progressBar->minimum());
  axis->setMax(ui->progressBar->maximum());
  //  series->attachAxis(axis);
  auto g = new GameImpl{ a, b, rounds };
  ui->progressBar->setValue(0);
  ui->progressBar->setMaximum(g->getRounds() - 1);
  ui->progressBar->setMinimum(0);
  connect(g, &AbstractGame::roundPlayed, this, [&](const RoundResult& result) {
    series->append(result.round, g->getScore(*g->getAgent1()));
    series2->append(result.round, g->getScore(*g->getAgent2()));
    ui->lcdNumber->display(g->getScore(*a));
    ui->lcdNumber_2->display(g->getScore(*b));
    ui->progressBar->setValue(result.round);
  });
  g->playGame();

  ui->lcdNumber->display(g->getScore(*a));
  ui->lcdNumber_2->display(g->getScore(*b));

  series->setName("agent 1");
  series2->setName("agent 2");
  chart->addSeries(new QAreaSeries(series));
  chart->addSeries(new QAreaSeries(series2));
  chart->setAxisX(axis);
  delete g;
  delete a;
  delete b;
}

void
MainWindow::keyReleaseEvent(QKeyEvent* event)
{
  auto escapePressed = event->key() == Qt::Key::Key_Escape;
  if (escapePressed)
    QApplication::quit();
}
