#ifndef KUGOU_H
#define KUGOU_H
#include <QNetworkAccessManager>
#include <QNetworkRequest>

class KuGou {
 private:
  QNetworkAccessManager *network_manager;
  QNetworkAccessManager *network_manager2;
  QNetworkRequest *network_request;
  QNetworkRequest *network_request2;
  QList<QString> m_albumId;
  QList<QString> m_hash;
  QList<QString> m_albumName;  //专辑名
  QList<QString> m_songName;
  QList<QString> m_singerName;

 public:
  KuGou();
};

#endif  // KUGOU_H
