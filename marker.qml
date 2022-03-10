import QtQuick 2.0
import QtLocation 5.6

MapQuickItem{
    id: marker
    anchorPoint.x: marker.width / 4
    anchorPoint.y: marker.height
    sourceItem: Image{
        id: icon
        source: "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_red.png"
        sourceSize.width: 40
        sourceSize.height: 40
    }
}
