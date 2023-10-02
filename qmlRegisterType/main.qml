import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.VirtualKeyboard 2.4
import UI 1.0
Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        anchors.centerIn: parent
        id: data
        text: Database.dataDB
    }

}
