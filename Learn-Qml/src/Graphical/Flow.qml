//Flow.qml
import QtQuick 2.0

WhitesmokeSquare{
    id:root
    width: 160
    height: 160
    Flow{
        anchors.fill: parent
        anchors.margins: 20
        spacing: 20
        RedSquare{}
        DarkSquare{}
        BlueSquare{}
        RedSquare{}
        DarkSquare{}

    }
}
