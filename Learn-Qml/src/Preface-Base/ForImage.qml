import QtQuick 2.0

Image {
    id:image
    width:image.width
    height: image.height
    source: "../../asset/simpleG.png"
    //保持比例
    fillMode: Image.PreserveAspectCrop
}
