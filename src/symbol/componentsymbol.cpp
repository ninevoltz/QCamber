#include "componentsymbol.h"

#include <QtWidgets>

ComponentSymbol::ComponentSymbol(const QRectF& rect)
  : Symbol("component"), m_rect(rect)
{
  m_bounding = QRectF(m_rect.left(), -m_rect.bottom(), m_rect.width(), m_rect.height());
}

QPainterPath ComponentSymbol::painterPath(void)
{
  QPainterPath path;
  path.addRect(QRectF(m_rect.left(), -m_rect.bottom(), m_rect.width(), m_rect.height()));
  return path;
}
