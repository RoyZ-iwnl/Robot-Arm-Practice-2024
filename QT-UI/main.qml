import QtQuick 2.0
import QtQuick.Controls 2.0
import QtGamepad 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: qsTr("机械臂控制中心")

    GamepadHandler {
        id: gamepadHandler
        onAxisChanged: (axis, value) => {
            mainWindow.onGamepadAxisChanged(axis, value)
        }
        onTriggerChanged: (leftTrigger, rightTrigger) => {
            mainWindow.onGamepadTriggerChanged(leftTrigger, rightTrigger)
        }
    }

    Rectangle {
        anchors.centerIn: parent
        width: 200
        height: 100
        color: gamepadHandler.gamepadConnected ? "green" : "red"
        Text {
            anchors.centerIn: parent
            text: gamepadHandler.gamepadConnected ? "Gamepad Connected" : "No Gamepad"
        }
    }
}
