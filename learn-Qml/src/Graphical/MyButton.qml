//MyButton.qml
import QtQuick 2.0
Item{
    id:root
    Rectangle{
        anchors.fill: parent
        color: "midnightblue"
        width: 116;height: 26
        Text {
            anchors.centerIn: parent
            id: name; color:"whitesmoke"
            text: qsTr("text")
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log("hi")
            }
        }
    }

}

