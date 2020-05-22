import QtQuick 2.0

Item {
    //set width and height based on given background
    width: bg.width
    height: bg.height
    Image {
        id: bg
        source: "../../asset/bg.png"
    }

    MouseArea{
        id:backgroundClicker
        anchors.fill: parent
        onClicked: {
            rocket1.y = 100
            rocket2.rotation = 0
            rocket3.rotation = 0
            rocket3.scale = 1.0

        }
    }

    ClickableImage{
        id:rocket1
        x:20; y:100
        source: "../../asset/rocket.png"
        onClicked: {
            y-=5
        }
    }
    ClickableImage{
        id:rocket2
        x:210; y:100
        source: "../../asset/rocket.png"
        smooth: true
        onClicked: {
            rotation+=5
        }
    }
    ClickableImage{
        id:rocket3
        x:400; y:100
        source: "../../asset/rocket.png"

//提高图片质量
//若smooth为false
//旋转图片将会使得图片变得模糊(出现锯齿)
        smooth: true
        onClicked: {
            rotation+=5
            scale-=0.05
        }
    }

}
