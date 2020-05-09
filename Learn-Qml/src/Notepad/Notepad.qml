import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640; height: 480
    title: qsTr("Notepad")

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            contentData: [
                actions.opneAction
            ]

        }
    }

    Actions {
        id: actions
        //openAction.onTriggered:
    }

    Dialogs {
        id: dialogs
        //fileOpenDialog.onAccepted:

    }


}
