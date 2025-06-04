#include "componentsymbol.h"
#include <QtWidgets>

ComponentSymbol::ComponentSymbol(const PackageDataStore::PackageInfo& info,
                                 const QString& designator)
  : Symbol("component"), m_pin1(0,0), m_designator(designator)
{
  m_path = info.bodyPath;
  for (const auto& pin : info.pins) {
    m_path.addPath(pin.path);
    if (pin.number == 1)
      m_pin1 = QPointF(pin.x, -pin.y);
  }
  m_bounding = m_path.boundingRect();
}

QPainterPath ComponentSymbol::painterPath(void)
{
  return m_path;
}

void ComponentSymbol::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
    QWidget *widget)
{
  Symbol::paint(painter, option, widget);
  painter->setPen(Qt::NoPen);
  painter->setBrush(QBrush(m_pen.color()));
  painter->drawEllipse(m_pin1, 0.01, 0.01);
  painter->setPen(m_pen);
  painter->setBrush(Qt::NoBrush);
  painter->drawText(m_bounding, Qt::AlignCenter, m_designator);
}
