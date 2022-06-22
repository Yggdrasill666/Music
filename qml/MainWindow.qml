import QtQuick 2.0
import QtQuick.Controls
import QtQuick.Window
import QtQuick.Layouts

ApplicationWindow {
    id: appWindow
    width: 870
    height: 680
    visible: true
    title: qsTr("听点音乐")

    menuBar: MenuBar {
        id: appMenuBar

        Menu {
            title: qsTr("&File")
            MenuItem {
                action: actions.openFileAction
            }
        }
    }

    RowLayout {
        id: rowlayout

        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.rightMargin: 20
        ToolButton {
            action: actions.lastAction
            text: qsTr("")
        }
        ToolButton {
            action: actions.playAction
            text: qsTr("")
        }
        ToolButton {
            action: actions.nextAction
            text: qsTr("")
        }
        Slider {
            id: slider
        }
    }

    Actions {
        id: actions
        openFileAction.onTriggered: dialogs.openFileDialog()
        aboutAction.onTriggered: dialogs.openaboutDialog()
        playAction.onTriggered: if (playAction.icon.source == "/resource/image/播放.png")
                                    content.pauseMedia()
                                else
                                    content.playMedia()
        nextAction.onTriggered: content.nextMedia()
        lastAction.onTriggered: content.lastMedia()
    }

    Dialogs {
        id: dialogs
        fileOpenDialog.onAccepted: content.setFilesModel(
                                       fileOpenDialog.selectedFiles)
    }

    Content {
        id: content
        anchors.fill: parent
        z: -1
    }
}
