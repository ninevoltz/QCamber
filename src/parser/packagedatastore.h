#ifndef __PACKAGE_DATASTORE_H__
#define __PACKAGE_DATASTORE_H__

#include "datastore.h"
#include <QMap>
#include <QString>
#include <QRectF>

class PackageDataStore : public DataStore {
public:
  struct PackageInfo {
    QString name;
    qreal pitch;
    qreal xmin;
    qreal ymin;
    qreal xmax;
    qreal ymax;
  };

  void addPackage(int index, const PackageInfo& info);
  PackageInfo package(int index) const;
  const QMap<int, PackageInfo>& packages() const { return m_packages; }

  virtual void dump(void) {}

private:
  QMap<int, PackageInfo> m_packages;
};

#endif /* __PACKAGE_DATASTORE_H__ */
