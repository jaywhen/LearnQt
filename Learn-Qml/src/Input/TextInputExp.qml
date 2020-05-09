//TextInput.qml

import QtQuick 2.5

Rectangle {
    width: 200; height: 80
    color: "linen"

    TextInput {
        id: input1
        x: 8; y: 8;
        width: 96; height: 20
        focus: true
        text: "Text Input 1"

        //press `tab` turn to input2
        KeyNavigation.tab: input2
    }
    TextInput {
        id: input2
        x: 8; y: 36;
        width: 96; height: 20
        //focus: true
        text: "Text Input 2"
        KeyNavigation.tab: input1
    }
}
