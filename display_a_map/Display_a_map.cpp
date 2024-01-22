// Copyright 2024 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

#include "Display_a_map.h"

#include "Map.h"
#include "MapTypes.h"
#include "MapQuickView.h"
#include "Point.h"
#include "Viewpoint.h"
#include "SpatialReference.h"
#include <QFuture>
#include "SketchEditor.h"

using namespace Esri::ArcGISRuntime;

Display_a_map::Display_a_map(QObject* parent /* = nullptr */):
    QObject(parent),
    m_map(new Map(BasemapStyle::ArcGISTopographic, this))
{
}

Display_a_map::~Display_a_map()
{
}

MapQuickView* Display_a_map::mapView() const
{
    return m_mapView;
}
void Display_a_map::setupViewpoint()
{

    const Point center(-118.80543, 34.02700, SpatialReference::wgs84());
    const Viewpoint viewpoint(center, 100000.0);
    m_mapView->setViewpointAsync(viewpoint);

}

// Set the view (created in QML)
void Display_a_map::setMapView(MapQuickView* mapView)
{
    if (!mapView || mapView == m_mapView)
    {
        return;
    }

    m_mapView = mapView;
    m_mapView->setMap(m_map);
    setupViewpoint();
    emit mapViewChanged();
}
