import QtQuick 2.0
import QtGamepad 1.0

Item {
    id: gamepadHandler

    property bool gamepadConnected: gamepad.deviceId !== -1
    signal axisChanged(int axis, double value)
    signal triggerChanged(double leftTrigger, double rightTrigger)

    GamepadManager {
        id: gamepadManager
    }

    Gamepad {
        id: gamepad
        deviceId: gamepadManager.connectedGamepads.length > 0 ? gamepadManager.connectedGamepads[0] : -1

        onAxisLeftXChanged: gamepadHandler.axisChanged(0, axisLeftX)
        onAxisLeftYChanged: gamepadHandler.axisChanged(1, axisLeftY)
        onAxisRightXChanged: gamepadHandler.axisChanged(2, axisRightX)
        onAxisRightYChanged: gamepadHandler.axisChanged(3, axisRightY)
        onButtonL2Changed: gamepadHandler.triggerChanged(buttonL2, gamepad.buttonR2)
        onButtonR2Changed: gamepadHandler.triggerChanged(gamepad.buttonL2, buttonR2)
    }

    Component.onCompleted: {
        console.log("GamepadHandler initialized")
    }
}
