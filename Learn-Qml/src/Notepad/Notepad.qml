import QtQuick 2.12
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: root
    visible: true
    width: 640; height: 480
    title: qsTr("Untitled--")+qsTr("Notepad")
    property string currentFile



    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            Action {
                text: qsTr("&New")
            }
            MenuSeparator { }
            Action {
                text: qsTr("&Open")
                onTriggered: {
                    fileDialog.open()
                }
            }
            Action {
                text: qsTr("&Save")
            }

        }
        Menu {
            title: qsTr("&Help")
            Action {
                text: qsTr("&About Notepad")
            }
            Action {
                text: qsTr("A&bout Qt")
            }
        }
    }


    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)

        }
        onRejected: {
            console.log("Canceled")
        }
    }

    TextArea {
        id: textarea
        anchors.fill: parent
        onTextChanged: {
            root.title = qsTr("Untitled*--")+qsTr("Notepad")
        }
    }

}
