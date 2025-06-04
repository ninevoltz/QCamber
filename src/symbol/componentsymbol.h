#ifndef __COMPONENT_SYMBOL_H__
#define __COMPONENT_SYMBOL_H__

#include "symbol.h"
#include <QRectF>

class ComponentSymbol : public Symbol {
public:
  ComponentSymbol(const QRectF& rect);
  virtual QPainterPath painterPath(void);
private:
  QRectF m_rect;
};

#endif /* __COMPONENT_SYMBOL_H__ */
