import QtQuick 2.12
import QtQuick.Controls 1.4 //To use TextArea, it must be this version1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4



ApplicationWindow {
    id: root
    visible: true
    width: 640; height: 480
    title: qsTr("Untitled-")+qsTr("Notepad")


    Action {
        id: newAction
        text: qsTr("&New")
        shortcut: "ctrl+n"
        onTriggered: {
            textarea.text = "";
        }
    }

    Action {
        id: openAction
        text: qsTr("&Open")
        shortcut: "ctrl+o"
        onTriggered: {
            fileDialog.selectExisting = true
            fileDialog.open()
        }

    }

    Action {
        id: saveAction
        text: qsTr("&Save")
        shortcut: "ctrl+s"
        onTriggered: {
            fileDialog.selectExisting = false
            fileDialog.open()
        }


    }



    Action {
        id: undoAction
        text: qsTr("Undo")
        shortcut: "ctrl+z"
    }

    Action {
        id: copyAction
        text: qsTr("Copy")
        shortcut: "ctrl+c"
    }

    Action {
        id: pasteAction
        text: qsTr("Paste")
        shortcut: "ctrl+p"
    }

    Action {
        id: cutAction
        text: qsTr("Cut")
        shortcut: "ctrl+x"
    }

    Action {
        id: aboutAction
        text: qsTr("About")
        onTriggered: {
            aboutDialog.open()
        }
    }

    Action {
        id: darkThemeAction
        text: qsTr("Dark")
    }







    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {action: newAction}
            MenuSeparator{}
            MenuItem {action: openAction}
            MenuItem {action: saveAction}


        }

        Menu {
            title: qsTr("&Edit")
            MenuItem {action: undoAction}
            MenuSeparator{}
            MenuItem {action: cutAction}
            MenuItem {action: copyAction}
            MenuItem {action: pasteAction}


        }

        Menu {
            title: qsTr("&Themes")
            MenuItem {action: darkThemeAction}
        }

        Menu {
            title: qsTr("&Help")
            MenuItem {action: aboutAction}
        }

    }



    property var nametype: [
        "All files (*.*)",
        "Text files (*.txt)", "HTML files (*.html, *.htm)",
        "C files (*.c)", "C++ files (*.cpp, *.cc)",
        "JS files (*js)", "JSON files (*.json)", "Java files (*.java)",
        "Python files (*py)", "QML files (*.qml)", "XML files (*.xml)"



                           ]

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        nameFilters: nametype
        folder: shortcuts.home
        onAccepted: {

        }

    }


    MessageDialog {
        id: aboutDialog
        title: "About Notepad"
        text: "A boring notepad application"
        icon: StandardIcon.Information
    }


    TextArea {
        id: textarea
        anchors.fill: parent
        style: TextAreaStyle {
            textColor: "#333"
            selectionColor: "steelblue"
            selectedTextColor: "#eee"
            //backgroundColor: "#eee"
            font.pointSize: 16

        }


        textFormat: TextEdit.AutoText
        wrapMode: TextEdit.Wrap

    }

//    TextArea {
//        Accessible.name: "document"
//        id: textarea
//        anchors.fill:  parent

//        property variant multiAnswersStrArray: []
//        property variant multiAnswersStrArrayIndex: 0

//        frameVisible: true
//        width: parent.width
//        height: parent.height/2


//        baseUrl: "qrc:/"
//        text: document.text
//        textFormat: Qt.RichText
//        Component.onCompleted: forceActiveFocus()

//    }





}
