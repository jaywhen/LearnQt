// 2018051604079 Xiang Jiewen
import QtQuick 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.0
import FilesIO 1.0


ApplicationWindow {
    id: root
    visible: true
    width: 640; height: 480


    title: qsTr("XNotepad")
    /* TODO: let window title be like this: "untitled-*Notepad;
     * if text changed the "*" will be disappear and display file name
     */
//    property string currentfile
//    property bool tchanged: false
//    property bool isSave: false
//    property bool isopen: false
    minimumWidth: 400
    minimumHeight: 300

    //property string filetitle: currentfile

    //property string windowTitle: qsTr("Untitled")+(tchanged ? "*" : "")+qsTr("-Notepad")

    property string about: qsTr("<h2>XNotePad 0.6</h2>"+
                                "<p style=\"font-family:'Sans Serif'; font-weight:300; font-size:12pt;\">👻This is a boring notepad application.\n"+
                                " You can spread it without any license."+
                                "<p style=\"font-family:'Sans Serif'; font-weight:300; font-size:12pt;\">🤷‍If you want choose a editor\n, I'll recommend <a href=\"https://kate-editor.org/\">Kate</a> or <a href=\"https://code.visualstudio.com/\">VsCode</a>."+
                                "<p>----------------------------------------------------------------------------------------------"+
                                "<p style=\"font-family:'Sans Serif'; font-weight:300; font-size:12pt;\">😀And if you have leisure, you can visit the author's home page: "+


                                "<p style=\"font-size:11pt;\"><a href=\"https://jaywhen.com/\">Author's home page</a>"+
                                " ----- "+
                                "<a href=\"https://github.com/jaywhen/LearnQt/tree/master/learn-QtQuick/XNotePad\">Code Repositories </a>")


    property string bkcolor: "white"
    property string textscolor: "black"
    property var fontsize: 12
    property var fontweight: 50


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
        iconSource: "qrc:/img/open.png"
        onTriggered: {
            openFileDialog.open()
            //tchanged = false
        }

    }

    Action {
        id: saveAction
        text: qsTr("&Save")
        shortcut: "ctrl+s"
        onTriggered: {
            filesio.save(textarea.text, currentfile)
        }
    }

    Action {
        id: saveASAction
        text: qsTr("S&ave as")
        onTriggered: {
            //isSave = true
            saveAsDialog.selectExisting = false
            saveAsDialog.open()
        }
    }

    Action {
        id: undoAction
        text: qsTr("Undo")
        shortcut: "ctrl+z"
        onTriggered: textarea.undo()
    }

    Action {
        id: copyAction
        text: qsTr("Copy")
        shortcut: "ctrl+c"
        onTriggered: textarea.copy()
    }

    Action {
        id: pasteAction
        text: qsTr("Paste")
        shortcut: "ctrl+p"
        onTriggered: textarea.paste()
    }

    Action {
        id: cutAction
        text: qsTr("Cut")
        shortcut: "ctrl+x"
        onTriggered: textarea.cut()
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
        onTriggered: {
            bkcolor = "darkslategray"
            textscolor = "ghostwhite"
        }
    }

    Action {
        id: whiteyThemeAction
        text: qsTr("Whitey")
        onTriggered: {
            bkcolor = "white"
            textscolor = "black"
        }
    }

    Action {
        id: boldAction
        text: qsTr("&Bold")
        iconSource: "qrc:/img/bold.png"
        onTriggered: fontweight+=75
    }
    Action {
        id: fontplusAction
        text: qsTr("&Plus")
        iconSource: "qrc:/img/fontplus.png"
        onTriggered: fontsize+=1
    }
    Action {
        id: fontreduceAction
        text: qsTr("&Reduce")
        iconSource: "qrc:/img/fontreduce.png"
        onTriggered: fontsize-=1
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {action: newAction}
            MenuSeparator{}
            MenuItem {action: openAction}
            MenuItem {action: saveAction}
            MenuItem {action: saveASAction}
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
            MenuItem {action: whiteyThemeAction}
        }

        Menu {
            title: qsTr("&Help")
            MenuItem {action: aboutAction}
        }

    }

    toolBar: ToolBar {
        id: toolbar
        width: parent.width
        Row {
            anchors.fill: parent
            //spacing: 0
            ToolButton {action: openAction}
            ToolBarSeparator{}
            ToolButton {action: fontplusAction}
            ToolButton {action: fontreduceAction}
            ToolBarSeparator{}
            ToolButton {action: boldAction}

        }


    }


    property var nametype: [
        "All files ()",
        "Text files (*.txt)", "HTML files (*.html, *.htm)",
        "C files (*.c)", "C++ files (*.cpp, *.cc)",
        "JS files (*js)", "JSON files (*.json)", "Java files (*.java)",
        "Python files (*py)", "QML files (*.qml)", "XML files (*.xml)"
                           ]

    FileDialog {
        id: openFileDialog
        title: "Choose a file! bala~bala~"
        nameFilters: nametype
        onAccepted: {
            textarea.text = filesio.open(openFileDialog.fileUrl)
            //currentfile = openFileDialog.fileUrl
            //tchanged = false

        }
    }

    FileDialog {
        id: saveAsDialog
        title: "Choose a file~~~~"
        nameFilters: nametype

        onAccepted: {
            filesio.save(textarea.text, saveAsDialog.fileUrl)
            //currentfile = saveAsDialog.fileUrl
        }

    }


    MessageDialog {
        id: aboutDialog
        title: "About Notepad"
        text: about
        icon: StandardIcon.Information
    }


    TextArea {

        id: textarea
        anchors.fill: parent

        style: TextAreaStyle {
            id: textareastyle

            textColor: textscolor
            selectionColor: "steelblue"
            selectedTextColor: "#eee"
            backgroundColor: bkcolor
            font.pointSize: fontsize
            font.weight: fontweight
        }

        //onTextChanged: tchanged = true


        textFormat: TextEdit.AutoText
        wrapMode: TextEdit.Wrap

    }



    FilesIO {
        id: filesio
    }
}
