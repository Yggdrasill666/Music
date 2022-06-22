import QtQuick
import QtCore
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Controls 2.5 as QQC

Item {
    property alias fileOpenDialog: fileopen

    function openFileDialog() {
        fileopen.open()
    }
    function openaboutDialog() {
        about.open()
    }

    FileDialog {
        id: fileopen
        title: "Select some music files"
        currentFolder: StandardPaths.writableLocation(
                           StandardPaths.DocumentsLocation)
        fileMode: FileDialog.OpenFiles
        nameFilters: ["Music files (*.mp3 *.ogg)"] //设置文件类型
    }

    QQC.Dialog {
        id: about
        contentItem: Text {
            id: name
            text: qsTr("2020051615218zhangyu")
        }
    }
}
