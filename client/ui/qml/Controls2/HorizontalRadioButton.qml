import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Style 1.0

import "TextTypes"

RadioButton {
    id: root

    property string hoveredColor: ВадькаVPNStyle.color.barelyTranslucentWhite
    property string defaultColor: ВадькаVPNStyle.color.transparent
    property string checkedColor: ВадькаVPNStyle.color.transparent
    property string disabledColor: ВадькаVPNStyle.color.transparent

    property string textColor: ВадькаVPNStyle.color.paleGray
    property string textDisabledColor: ВадькаVPNStyle.color.mutedGray

    property string pressedBorderColor: ВадькаVPNStyle.color.charcoalGray
    property string checkedBorderColor: ВадькаVPNStyle.color.goldenApricot
    property string defaultBodredColor: ВадькаVPNStyle.color.transparent
    property string checkedDisabledBorderColor: ВадькаVPNStyle.color.mutedBrown
    property string borderFocusedColor: ВадькаVPNStyle.color.paleGray
    property int borderWidth: 0

    implicitWidth: content.implicitWidth
    implicitHeight: content.implicitHeight

    property bool isFocusable: true

    Keys.onTabPressed: {
        FocusController.nextKeyTabItem()
    }

    Keys.onBacktabPressed: {
        FocusController.previousKeyTabItem()
    }

    Keys.onUpPressed: {
        FocusController.nextKeyUpItem()
    }
    
    Keys.onDownPressed: {
        FocusController.nextKeyDownItem()
    }
    
    Keys.onLeftPressed: {
        FocusController.nextKeyLeftItem()
    }

    Keys.onRightPressed: {
        FocusController.nextKeyRightItem()
    }

    indicator: Rectangle {
        anchors.fill: parent
        radius: 16

        color: {
            if (root.enabled) {
                if (root.hovered) {
                    return root.hoveredColor
                } else if (root.checked) {
                    return root.checkedColor
                }
                return root.defaultColor
            } else {
                return root.disabledColor
            }
        }

        border.color: {
            if (root.enabled) {
                if (root.pressed) {
                    return root.pressedBorderColor
                } else if (root.checked) {
                    return root.checkedBorderColor
                } else if (root.activeFocus) {
                    return root.borderFocusedColor
                }
                return root.defaultBodredColor
            } else {
                if (root.checked) {
                    return root.checkedDisabledBorderColor
                }
                return root.defaultBodredColor
            }
        }

        border.width: {
            if(root.checked || root.activeFocus) {
                return 1
            }
            return root.pressed ? 1 : 0
        }

        Behavior on color {
            PropertyAnimation { duration: 200 }
        }
        Behavior on border.color {
            PropertyAnimation { duration: 200 }
        }
    }

    ColumnLayout {
        id: content
        anchors.fill: parent
        spacing: 0

        ButtonTextType {
            text: root.text
            color: root.enabled ? root.textColor : root.textDisabledColor

            Layout.fillWidth: true
            Layout.rightMargin: 24
            Layout.leftMargin: 24
            Layout.topMargin: 12
            Layout.bottomMargin: 12

            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
        }
    }

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        enabled: false
    }

    Keys.onEnterPressed: {
        this.clicked()
    }

    Keys.onReturnPressed: {
        this.clicked()
    }
}
