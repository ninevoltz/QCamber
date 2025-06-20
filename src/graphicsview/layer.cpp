/**
 * @file   layer.cpp
 * @author Wei-Ning Huang (AZ) <aitjcize@gmail.com>
 *
 * Copyright (C) 2012 - 2014 Wei-Ning Huang (AZ) <aitjcize@gmail.com>
 * All Rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "layer.h"

#include <QtWidgets>

#include "context.h"
#include "odbppgraphicsscene.h"
#include "components.h"

Layer::Layer(QString step, QString layer):
  GraphicsLayer(NULL), m_step(step), m_layer(layer), m_notes(NULL)
{
  GraphicsLayerScene* scene = new GraphicsLayerScene;
  QString featurePath = ctx.loader->featuresPath(QString("steps/%1/layers/%2").arg(step).arg(layer));
  if (QFile(featurePath).size() > 0) {
    m_features = new LayerFeatures(step, "steps/%1/layers/" + layer + "/features");
  } else {
    bool bottom = layer.contains("bot", Qt::CaseInsensitive) ||
                 layer.contains("bottom", Qt::CaseInsensitive);
    m_features = new Components(step,
                                "steps/%1/layers/" + layer + "/components",
                                bottom);
  }

  if (auto lf = dynamic_cast<LayerFeatures*>(m_features))
    lf->addToScene(scene);
  else if (auto cmp = dynamic_cast<Components*>(m_features))
    cmp->addToScene(scene);

  setLayerScene(scene);
}

Layer::~Layer()
{
  if (m_notes) {
    delete m_notes;
  }
  delete m_features;
}

QString Layer::step()
{
  return m_step;
}

QString Layer::layer()
{
  return m_layer;
}

Notes* Layer::notes()
{
  if (!m_notes) {
    m_notes = new Notes(m_step, m_layer);
  }
  return m_notes;
}

QStandardItemModel* Layer::reportModel(void)
{
  if (LayerFeatures* lf = dynamic_cast<LayerFeatures*>(m_features))
    return lf->reportModel();
  return new QStandardItemModel;
}

void Layer::setHighlightEnabled(bool status)
{
  m_layerScene->setHighlightEnabled(status);
}

void Layer::setShowStepRepeat(bool status)
{
  if (LayerFeatures* lf = dynamic_cast<LayerFeatures*>(m_features))
    lf->setShowStepRepeat(status);
  forceUpdate();
}

void Layer::setPen(const QPen& pen)
{
  m_features->setPen(pen);
  GraphicsLayer::setPen(pen);
}

void Layer::setBrush(const QBrush& brush)
{
  m_features->setBrush(brush);
  GraphicsLayer::setBrush(brush);
}

void Layer::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  QGraphicsItem::mousePressEvent(event);
}

void Layer::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
  QGraphicsItem::mouseDoubleClickEvent(event);
}
