import QtQuick 2.0
import QtQuick.Controls

Item {
    property alias searchAction: search
    property alias nextAction: next
    property alias lastAction: last
    property alias playAction: play
    property alias openFileAction: openFile
    Action {
        id: search
        text: qsTr("搜索歌曲")
    }
    Action {
        id: next
        text: qsTr("下一首")
        icon.source: "/resource/image/下一曲.png"
    }
    Action {
        id: last
        text: qsTr("上一首")
        icon.source: "/resource/image/上一曲.png"
    }
    Action {
        id: play
        text: qsTr("播放")
        icon.source: "/resource/image/播放.png"
        onTriggered: {
            if (icon.source == "/resource/image/播放.png") {
                icon.source = "/resource/image/暂停.png"
            } else {
                icon.source = "/resource/image/播放.png"
            }
        }
    }
    Action {
        id: openFile
        text: qsTr("打开文件")
    }
}
