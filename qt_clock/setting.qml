import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    width: 100; height: 100

    Text {
        anchors.centerIn: parent
        text: qsTr("Hello World.")
    }
}

