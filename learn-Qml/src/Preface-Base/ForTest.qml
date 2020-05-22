import QtQuick 2.12
Rectangle {
    width: 240
    height: 100
    Text {
        id: label
        anchors.centerIn: parent
        property int spacePresses: 0
        text: "Space pressed: " + spacePresses + " times"
        color: "blue"
        font.family: "Ubuntu"
        font.pixelSize: 20
        onTextChanged: console.log("text changed to:", text)
        focus: true
        Keys.onSpacePressed: {
            increment()
        }
        Keys.onEscapePressed: {
            label.text = ''
        }

        function increment(){
            spacePresses+=1
        }
    }

}
