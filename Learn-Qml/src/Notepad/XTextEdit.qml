import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4


Item {

    property alias textDocument: edit.textDocument//用于语法高亮
    property int lincount: edit.lineCount
    property color textcolor: "black"
    property color selectTextcolor: "white"
    property color selectioncolor: "royalblue"
    property real fontsize: 16

    Flickable{
        id: flick
        anchors.fill: parent
        contentWidth: edit.paintedWidth
        contentHeight: edit.paintedHeight + 5
        clip: true
        boundsBehavior:Flickable.StopAtBounds
        function ensureVisible(r) {
           if (contentX >= r.x)
               contentX = r.x;
           else if (contentX+width <= r.x+r.width)
               contentX = r.x+r.width-width;
           if (contentY >= r.y)
               contentY = r.y;
           else if (contentY+height <= r.y+r.height)
               contentY = r.y+r.height-height + 10;
        }



        Column{
            id:lineNumberLabel
            anchors.left:  parent.left
            Repeater {
               model: edit.lineCount;
               Rectangle {
                   width: lineNumberWidth(edit.lineCount)
                   height: panding.contentHeight
                   color: "ghostwhite"
                   Text {
                       id:showLineNumber
                       anchors{
                           bottom:parent.bottom
                           bottomMargin: 0
                           horizontalCenter: parent.horizontalCenter
                       }
                       text:index + 1
                       color: "indigo"
                       font.pointSize: fontsize
                   }
               }
            }
        }


        TextEdit{
            id: panding
            font.pointSize: fontsize
            visible: false
            text: " "
        }


        TextEdit {
            property bool ctrlPressed: false
            id: edit
            anchors.left: lineNumberLabel.right
            anchors.leftMargin: 4
            width: flick.width - 10
            height: edit.contentHeight > flick.height ? edit.contentHeight : flick.height
            selectByMouse: true
            tabStopDistance: 35
            wrapMode: TextEdit.Wrap
            activeFocusOnPress: true
            cursorVisible: true
            selectedTextColor: selectTextcolor
            selectionColor: selectioncolor
            color: textcolor
            font.pointSize: fontsize
            cursorDelegate: cursorDelegate
            onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)

            MouseArea{
                anchors.fill: parent
                acceptedButtons: Qt.RightButton
                onWheel: {
                    var datl = wheel.angleDelta.y / 120
                    if (datl>0 && edit.ctrlPressed) {
                        fontsize += 1
                    } else if (datl<0 && edit.ctrlPressed) {
                        fontsize -= 1
                    }
                    wheel.accepted = false
                }
                onClicked: {
                    edit.forceActiveFocus();
                    if(mouse.button === Qt.RightButton)
                        contentMenu.popup()
                }
            }
            Keys.onPressed: {
                if(event.modifiers === Qt.ControlModifier) {
                    ctrlPressed = true
                }
                event.accepted = false
            }
            Keys.onReleased: {
                if(!(event.modifiers&Qt.ControlModifier)) {
                    ctrlPressed = false
                }
                event.accepted = false
            }
        }

        ScrollIndicator.horizontal: ScrollIndicator { width: 15}
        ScrollIndicator.vertical: ScrollIndicator { width: 15 }
    }

    Component {
        id: cursorDelegate
        Rectangle {
            id: cursor
            color: "Blue"
            width: 2;
            height: 5
            SequentialAnimation {
                running: true;
                loops: ColorAnimation.Infinite
                NumberAnimation {
                    easing {
                        type: Easing.InQuint
                    }
                    property: "opacity"
                    target: cursor; from: 1.0; to: 0.0; duration: 800;
                }
                NumberAnimation {
                    easing {
                        type: Easing.InQuint
                    }
                    property: "opacity"
                    target: cursor;
                    from: 0.0;
                    to: 1.0;
                    duration: 800;
                }
            }
            Behavior on x {
                SpringAnimation { spring: 3; damping: 0.2  }
            }
            Behavior on y {
                SpringAnimation { spring: 3; damping: 0.2 }
            }
        }
    }

    function lineNumberWidth(lineCount) {
        var width = 1;
        var space = 0;
        while(lineCount >= 10) {
           lineCount /= 10;
           ++width;
        }
        return space = width * fontsize
    }
}

