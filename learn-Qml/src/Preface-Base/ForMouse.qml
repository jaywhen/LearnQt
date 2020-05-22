import QtQuick 2.0
Item {    
    width: 200
    height: 250
    Rectangle{
        id:rect1
        x:12; y:12
        width: 76; height: 96
        color: "lightsteelblue"
        Text {
            anchors.centerIn: parent
            text: qsTr("Click me !")
        }
        MouseArea{
            id:area
            width: parent.width
            height: parent.height
            onClicked: rect2.visible = !rect2.visible
        }

    }
    Rectangle{
        id:rect2
        x:112; y:12
        width: 76; height: 98
        border.color: "lightsteelblue"
        border.width: 4
        radius: 8
    }
}
