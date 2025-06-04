#ifndef __COMPONENT_SYMBOL_H__
#define __COMPONENT_SYMBOL_H__

#include "symbol.h"
#include "packagedatastore.h"
#include <QPainterPath>

class ComponentSymbol : public Symbol {
public:
  ComponentSymbol(const PackageDataStore::PackageInfo& info);
  virtual QPainterPath painterPath(void);
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget);
private:
  QPainterPath m_path;
  QPointF m_pin1;
};

#endif /* __COMPONENT_SYMBOL_H__ */
