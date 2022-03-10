import QtQuick 2.9
import QtQuick.Window 2.2
import QtLocation 5.6
import QtPositioning 5.6



Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Property Location")
    property double lat
    property double lng
    Plugin {
        id: mapPlugin
        name: "osm"
    }



    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(lat,lng)
        zoomLevel: 14
        Component.onCompleted:addMarker(lat,lng)
    }

    function addMarker(lat,lng)
    {

 console.log(lat);
        console.log(lng);
        var Component = Qt.createComponent("qrc:/marker.qml")
        var item = Component.createObject(window, {
                                              coordinate: QtPositioning.coordinate(lat,lng)
                                          })
        mapView.addMapItem(item)



    }

}
