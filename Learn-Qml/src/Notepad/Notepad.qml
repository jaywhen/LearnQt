import QtQuick 2.12
import QtQuick.Controls 1.4 //To use TextArea, it must be this version1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: root
    visible: true
    width: 640; height: 480
    title: qsTr("Untitled--")+qsTr("Notepad")


    Action {
        id: newAction
        text: qsTr("&New")
        onTriggered: {
            textarea.text = "";
        }
    }

    Action {
        id: openAction
        text: qsTr("&Open")
        onTriggered: {
            openDialog.open()
        }

    }


    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {action: newAction}
            MenuSeparator{}
            MenuItem {action: openAction}


        }
    }





//    menuBar: MenuBar {
//        Menu {
//            title: qsTr("&File")
//            Action {
//                text: qsTr("&New")
//            }
//            //MenuSeparator { }
//            Action {
//                text: qsTr("&Open")
//                onTriggered: {
//                    fileDialog.open()
//                }
//            }
//            Action {
//                text: qsTr("&Save")
//            }

//        }
//        Menu {
//            title: qsTr("&Help")
//            Action {
//                text: qsTr("&About Notepad")
//            }
//            Action {
//                text: qsTr("A&bout Qt")
//            }
//        }
//    }


    FileDialog {
        id: openDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + openDialog.fileUrls)

        }

    }


    TextArea {
        id: textarea
        anchors.fill: parent
//        textColor: "orange"

    }

}
