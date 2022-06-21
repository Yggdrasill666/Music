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

    Actions {
        id: actions
    }

    RowLayout {
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
        Slider {}
    }
}
