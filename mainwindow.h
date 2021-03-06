#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChart>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  void on_horizontalSlider_valueChanged(int value);

  void on_btnStart_clicked();

 private:
  Ui::MainWindow* ui;
  QtCharts::QChart* chart;

  // QWidget interface
 protected:
  virtual void keyReleaseEvent(QKeyEvent* event) override;
};
#endif  // MAINWINDOW_H
