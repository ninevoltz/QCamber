#ifndef __COMPONENTS_H__
#define __COMPONENTS_H__

#include "symbol.h"
#include <QList>
#include <QString>

class ComponentsDataStore;
class QGraphicsScene;

class Components : public Symbol {
public:
  Components(QString step, QString path);
  ~Components();

  void addToScene(QGraphicsScene* scene);

private:
  QList<Symbol*> m_symbols;
};

#endif /* __COMPONENTS_H__ */
