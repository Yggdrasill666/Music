import QtQuick
import QtQuick.Dialogs
import QtQuick.Controls as QQC
import QtMultimedia

Rectangle {
    anchors.fill: parent
    property alias mediaplay: mediaplayer
    property var url

    function setFilesModel() {
        for (var j = 0; j < arguments[0].length; j++) {
            url = arguments[0] //保存文件路径
            lm.append({
                          "media": arguments[0][j]
                      })
        }
    }
    function setValue() {
        mediaplayer.value = arguments[0]
    }

    function playMedia() {
        //播放功能
        mediaplayer.play()
    }
    function pauseMedia() {
        //暂停功能
        mediaplayer.pause()
    }
    function stopMedia() {
        //停止功能
        mediaplayer.stop()
    }
    function nextMedia() {
        //下一首
        for (var i = 0; i < url.length; i++) {
            if (mediaplayer.source == url[i]) {
                mediaplayer.stop()
                i = i + 1
                if (i == url.length)
                    mediaplayer.source = url[0]
                else
                    mediaplayer.source = url[i]
                mediaplayer.play()
                break
            }
        }
    }
    function lastMedia() {
        //上一首
        for (var i = 0; i < url.length; i++) {
            if (mediaplayer.source == url[i]) {
                mediaplayer.stop()
                i = i - 1
                if (i < 0)
                    mediaplayer.source = url[url.length - 1]
                else
                    mediaplayer.source = url[i]
                mediaplayer.play()
                break
            }
        }
    }

    ListView {
        id: listview
        anchors.fill: parent
        model: ListModel {
            id: lm
        }
        delegate: Rectangle {
            id: rect
            height: 24
            width: parent.width
            Text {
                id: tx
                anchors.fill: parent
                text: media //文件路径名
            }
            TapHandler {
                onTapped: {
                    mediaplayer.stop() //将上一首歌曲结束
                    mediaplayer.source = media //将资源导入mediaplayer
                    mediaplayer.play() //mediaplayer进行播放的实现
                }
            }
        }
    }
    MediaPlayer {
        id: mediaplayer
        audioOutput: AudioOutput {}
    }
}
