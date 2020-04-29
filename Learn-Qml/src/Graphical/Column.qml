//Column.qml
import QtQuick 2.0

DarkSquare{
    id:root
    width: 120
    height: 240

    Column{
        id:column
        anchors.centerIn: parent
        spacing: 8
        RedSquare{}
        WhitesmokeSquare{width:96}
        BlueSquare{}

    }
}
