import QtQuick 2.0

WhitesmokeSquare{
    id:root
    width:400; height: 120
    Row{
        id:row
        anchors.centerIn: parent
        spacing: 20
        BlueSquare{}
        DarkSquare{}
        RedSquare{}
    }


}
