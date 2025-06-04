/**
 * @file   layer.h
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

#ifndef __LAYER_H__
#define __LAYER_H__

#include <QGraphicsScene>

#include "layerfeatures.h"
#include "graphicslayer.h"
#include "graphicslayerscene.h"
#include "components.h"
#include "notes.h"
#include "symbol.h"
#include <QTextEdit>

class Layer: public GraphicsLayer {
public:
  Layer(QString step, QString layer);
  virtual ~Layer();

  QString step();
  QString layer();
  Notes* notes();
  QStandardItemModel* reportModel(void);

  void setHighlightEnabled(bool status);
  void setShowStepRepeat(bool status);

  virtual void setPen(const QPen& pen);
  virtual void setBrush(const QBrush& brush);

protected:
  virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
  virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

private:
  Symbol* m_features;
  QString m_step;
  QString m_layer;
  Notes* m_notes;
};

#endif /* __LAYER_H__ */
