import QtQuick
import QtQuick.Controls
import QtQuick.Shapes

Popup {
    id: root

    property alias buttonWidth: button.implicitWidth

    modal: false
    closePolicy: Popup.NoAutoClose
    padding: 4

    visible: false

    Overlay.modal: Rectangle {
        color: ВадькаVPNStyle.color.translucentMidnightBlack
    }

    background: Rectangle {
        color: ВадькаVPNStyle.color.transparent
    }

    ImageButtonType {
        id: button

        image: "qrc:/images/controls/close.svg"
        imageColor: ВадькаVPNStyle.color.paleGray

        implicitWidth: 40
        implicitHeight: 40

        onClicked: {
            PageController.goToDrawerRootPage()
        }
    }
}
