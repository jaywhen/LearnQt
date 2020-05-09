import QtQuick 2.5
import QtQuick.Controls 2.12

Item {
    property alias openAction: open
    Action {
        id: open
        text: qsTr("&Open")
    }


}
