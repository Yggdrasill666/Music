#ifndef KUGOU_H
#define KUGOU_H
#include <QNetworkAccessManager>
#include <QNetworkReply>

class KuGou : public QObject {
 private:
  QNetworkAccessManager *network_manager;
  QNetworkAccessManager *network_manager2;
  QNetworkRequest *network_request;
  QNetworkRequest *network_request2;
  QList<QString> m_albumId;  //专辑的唯一标识符
  QList<QString> m_fileHash;
  QList<QString> m_albumName;  //专辑名
  QList<QString> m_songName;
  QList<QString> m_singerName;
  QList<double> m_duration;

 public:
  void parseJson_getAlbumID(QString json);

 protected slots:
  void replyFinished(QNetworkReply *reply);
  void replyFinished2(QNetworkReply *reply);

 public:
  void search(QString str);
  KuGou(QObject *parent = nullptr);
};

#endif  // KUGOU_H
