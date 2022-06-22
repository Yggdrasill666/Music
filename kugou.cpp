#include "kugou.h"

#include <QByteArray>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QNetworkRequest>

KuGou::KuGou(QObject *parent) : QObject(parent) {
  network_manager = new QNetworkAccessManager();
  network_request = new QNetworkRequest();
  network_manager2 = new QNetworkAccessManager();
  network_request2 = new QNetworkRequest();
  connect(network_manager, &QNetworkAccessManager::finished, this,
          &KuGou::replyFinished);
  connect(network_manager2, &QNetworkAccessManager::finished, this,
          &KuGou::replyFinished2);
}

void KuGou::search(QString str) {
  m_albumId.clear();
  m_fileHash.clear();
  m_albumName.clear();
  m_songName.clear();
  m_singerName.clear();
  QString KGAPISTR1 =
      QString(
          "http://songsearch.kugou.com/song_search_v2?keyword="
          "%1&page=&pagesize=40&userid=-1&clientver=&platform=WebFilter&tag=em&"
          "filter=2&iscorrection=1&privilege_filter=0")
          .arg(str);
  network_request->setUrl(QUrl(KGAPISTR1));
  network_manager->get(QNetworkRequest((*network_request)));
}
void KuGou::replyFinished(QNetworkReply *reply) {
  if (reply->error() == QNetworkReply::NoError) {
    // QByteArray类提供了一个字节数组
    QByteArray bytes = reply->readAll();
    QString result = QString(bytes);
  }
}
void KuGou::replyFinished2(QNetworkReply *reply) {
  if (reply->error() == QNetworkReply::NoError) {
    QByteArray bytes = reply->readAll();
    QString result = bytes;
    parseJson_getAlbumID(result);
  }
}
void KuGou::parseJson_getAlbumID(QString json) {
  QByteArray ba = json.toUtf8();
  // data()返回一个指向存储在字节数组中的数据的指针。该指针可用于访问和修改组成数组的字节。数据是'\0'终止的，也就是说，在返回的指针之后，您可以访问的字节数是size()
  //+ 1，包括'\0'终止符
  const char *ch = ba.data();
  QByteArray byte_array;
  QJsonParseError json_error;
  //将json解析为UTF-8编码的json文档，并从中创建一个QJsonDocument。如果解析成功，返回一个有效的(非空)QJsonDocument。如果失败，返回的文档将为空，可选的error变量将包含关于错误的进一步细节。
  QJsonDocument parse_doucment =
      QJsonDocument::fromJson(byte_array.append(ch), &json_error);
  // QJsonParseError类用于报告JSON解析期间的错误
  if (json_error.error == QJsonParseError::NoError) {
    //如果文档包含一个对象，则返回true
    if (parse_doucment.isObject()) {
      // QJsonObject类封装了一个JSON对象
      // object()返回文档中包含的QJsonObject。如果文档包含数组，则返回空对象
      QJsonObject rootObj = parse_doucment.object();
      //如果对象包含键key，则返回true
      if (rootObj.contains("data")) {
        QJsonValue valuedata = rootObj.value("data");
        if (valuedata.isObject()) {
          //将值转换为对象并返回
          QJsonObject valuedataObject = valuedata.toObject();
          if (valuedataObject.contains("lists")) {
            QJsonValue valueArray = valuedataObject.value("lists");
            //如果值包含数组则返回true
            if (valueArray.isArray()) {
              //返回一个QJsonValue，表示索引i的值
              QJsonArray array = valueArray.toArray();
              int size = array.size();
              for (int i = 0; i < size; i++) {
                QJsonValue value = array.at(i);
                if (value.isObject()) {
                  QJsonObject object = value.toObject();
                  if (object.contains("SingerName")) {
                    QJsonValue SingerName_value = object.take("SingerName");
                    if (SingerName_value.isString())
                      m_singerName.push_back(SingerName_value.toString());
                  }
                  if (object.contains("SongName")) {
                    QJsonValue SongName_value = object.take("SongName");
                    if (SongName_value.isString())
                      m_songName.push_back(SongName_value.toString());
                  }
                  if (object.contains("FileHash")) {
                    QJsonValue FileHash_value = object.take("FileHash");
                    if (FileHash_value.isString())
                      m_fileHash.push_back(FileHash_value.toString());
                  }
                  if (object.contains("AlbumID")) {
                    QJsonValue AlbumID_value = object.take("AlbumID");
                    if (AlbumID_value.isString())
                      m_albumId.push_back(AlbumID_value.toString());
                  }
                  if (object.contains("AlbumName")) {
                    QJsonValue AlbumName_value = object.take("AlbumName");
                    if (AlbumName_value.isString())
                      m_albumName.push_back(AlbumName_value.toString());
                  }
                  if (object.contains("Duration")) {
                    QJsonValue Duration_value = object.take("Duration");
                    if (Duration_value.isDouble())
                      m_duration.push_back(Duration_value.toDouble());
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
