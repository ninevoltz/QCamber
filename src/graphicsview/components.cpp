#include "components.h"

#include <QtWidgets>

#include "componentsparser.h"
#include "record.h"
#include "context.h"

Components::Components(QString step, QString path) : Symbol("components")
{
  ComponentsParser parser(ctx.loader->absPath(path.arg(step)));
  ComponentsDataStore* ds = parser.parse();
  if (!ds)
    return;

  for (ComponentRecord* rec : ds->records()) {
    Symbol* s = rec->createSymbol();
    addChild(s);
    m_symbols.append(s);
  }
}

Components::~Components()
{
}

void Components::addToScene(QGraphicsScene* scene)
{
  for (Symbol* s : m_symbols) {
    scene->addItem(s);
  }
}
