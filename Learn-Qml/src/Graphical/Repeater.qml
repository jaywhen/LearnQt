import QtQuick 2.0

DarkSquare{
    id:root
    width: 252; height: 252
    property variant colorArray: ["red", "blue", "green"]
    Grid{
        anchors.fill: parent
        anchors.margins: 8
        spacing: 4
        Repeater{
            property int modelNums: 16
            model: modelNums
            Rectangle{
                width: 56; height: 56
                property int colorIndex: Math.floor((Math.random()*3))
                color: root.colorArray[colorIndex]
                border.color: Qt.lighter(color)
                Text {
                    anchors.centerIn: parent
                    color: "#f0f0f0"
                    text: "Cell"+index
                }
            }

        }

    }

}
