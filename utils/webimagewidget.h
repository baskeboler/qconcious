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

#include <QBuffer>
#include <QLabel>

class WebImageWidget : public QLabel
{
  Q_OBJECT
  Q_PROPERTY(QString url READ getUrl WRITE setUrl)
public:
  explicit WebImageWidget(const QString& url, QWidget* parent = nullptr);

  WebImageWidget(QWidget* parent = nullptr);
  QString getUrl() const;
  void setUrl(const QString& value);

public slots:
  void downloadFinished(QNetworkReply* reply);
  void readyReadSlot();
  void errorSlot();
  void sslErrorSlot();
  void startDownload();

signals:

  void loadingFailure(const QString& msg);
  void urlChanged();

private:
  QNetworkReply* reply;
  QBuffer buffer;
  QImage* image;
  QString url;
};

#endif // WEBIMAGEWIDGET_H
