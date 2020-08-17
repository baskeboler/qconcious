#ifndef WEBIMAGEWIDGET_H
#define WEBIMAGEWIDGET_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
class WebImageWidget : public QWidget
{
  Q_OBJECT
public:
  explicit WebImageWidget(const QString& url, QWidget* parent = nullptr)
    : QWidget(parent)
  {
    QNetworkAccessManager* mgr = new QNetworkAccessManager{ this };
    //    QNetworkReply* localRequest = QNetworkAccessManager::et(request)

    connect(mgr,
            &QNetworkAccessManager::finished,
            this,
            &WebImageWidget::downloadFinished);
    mgr->get(QNetworkRequest{ QUrl{ url } });
  }

public slots:
  void downloadFinished(QNetworkReply* reply) {}

signals:
};

#endif // WEBIMAGEWIDGET_H
