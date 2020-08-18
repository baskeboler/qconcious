#include "webimagewidget.h"

#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QNetworkRequest>
#include <utility>

WebImageWidget::WebImageWidget(const QString& url, QWidget* parent)
    : QLabel(parent), url{url} {
  //  setMinimumSize(100, 100);
  setAutoFillBackground(false);

  buffer.open(QIODevice::WriteOnly);
  connect(this, &WebImageWidget::urlChanged, this,
          &WebImageWidget::startDownload);
  startDownload();
}

WebImageWidget::WebImageWidget(QWidget* parent) : WebImageWidget{"", parent} {}

void WebImageWidget::downloadFinished(QNetworkReply* reply) {
  qInfo() << "download finished!";
  buffer.close();
  buffer.open(QBuffer::ReadOnly);
  QImage im = QImage::fromData(buffer.buffer());
  reply->deleteLater();
  reply = nullptr;

  //  QLabel* label = new QLabel(this);
  //  label->setMinimumSize(100, 100);
  setPixmap(QPixmap::fromImage(std::move(im)));
}

void WebImageWidget::readyReadSlot() {
  qInfo() << "readyread slot ";
  buffer.write(reply->readAll());
}

void WebImageWidget::errorSlot() {
  qInfo() << "error slot ";
  emit loadingFailure(reply->errorString());
  reply->deleteLater();
  reply = nullptr;
}

void WebImageWidget::sslErrorSlot() {
  qInfo() << "ssl error slot";
  emit loadingFailure("SSL error: " + reply->errorString());
  reply->deleteLater();
  reply = nullptr;
}

void WebImageWidget::startDownload() {
  if (url.isEmpty()) {
    qWarning() << "url is empty";
    return;
  }
  qInfo() << "url is not empty";
  buffer.close();
  buffer.reset();
  buffer.open(QIODevice::WriteOnly);
  QNetworkAccessManager* mgr = new QNetworkAccessManager{this};
  mgr->setRedirectPolicy(QNetworkRequest::RedirectPolicy::ManualRedirectPolicy);
  connect(mgr, &QNetworkAccessManager::finished, this,
          &WebImageWidget::downloadFinished);
  reply = mgr->get(QNetworkRequest{QUrl{url}});

  connect(reply, &QIODevice::readyRead, this, &WebImageWidget::readyReadSlot);

#if QT_VERSION >= QT_VERSION_CHECK(5, 15, 0)
  connect(reply, &QNetworkReply::errorOccurred, this,
          &WebImageWidget::errorSlot);
#else
  connect(reply, &QNetworkReply::error, this, &WebImageWidget::errorSlot);
#endif
  connect(reply, &QNetworkReply::sslErrors, this,
          &WebImageWidget::sslErrorSlot);
  //  mgr->deleteLater();
}

QString WebImageWidget::getUrl() const { return url; }

void WebImageWidget::setUrl(const QString& value) {
  url = value;
  emit urlChanged();
}
