#include "record.h"
#include "componentsdatastore.h"
#include "packagedatastore.h"
#include "componentsymbol.h"
#include "context.h"
#include "nullsymbol.h"

ComponentRecord::ComponentRecord(ComponentsDataStore* ds, const QStringList& param)
  : Record(ds, AttribData())
{
  int i = 0;
  pkg_ref = param[++i].toInt();
  x = param[++i].toDouble();
  y = param[++i].toDouble();
  rot = param[++i].toDouble();
  mirror = (param[++i] == "M");
  comp_name = param[++i];
  if (param.size() > i+1)
    part_name = param[++i];
}

Symbol* ComponentRecord::createSymbol(void) const
{
  ComponentsDataStore* cds = static_cast<ComponentsDataStore*>(ds);
  PackageDataStore* pkgs = cds->packages();
  if (!pkgs)
    return new NullSymbol("null", P, AttribData());
  PackageDataStore::PackageInfo info = pkgs->package(pkg_ref);
  QRectF rect(info.xmin, info.ymin, info.xmax - info.xmin, info.ymax - info.ymin);
  Symbol* symbol = new ComponentSymbol(rect);
  symbol->setPos(x, -y);
  if (mirror) {
    QTransform t; t.scale(-1, 1); symbol->setTransform(t, true);
  }
  symbol->setRotation(rot);
  symbol->setToolTip(QString("%1 (%2)").arg(comp_name).arg(part_name));
  return symbol;
}
