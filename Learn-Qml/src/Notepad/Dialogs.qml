import QtQuick 2.0
import QtQuick.Controls 2.5 as QQC
import QtQuick.Dialogs 1.3

Item {
    property alias fileOpenDialog: fileOpen

    function openFileDialog() { fileOpen.open(); }
    FileDialog {
        id: fileOpen
        title: "Select an image file"
        folder: shortcuts.documents
        nameFilters: [ "Image files (*.png *.jpeg *.jpg)" ]
    }
}
