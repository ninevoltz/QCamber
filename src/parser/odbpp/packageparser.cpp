#include "packageparser.h"

#include <QtCore>
#include <QRegularExpression>
#include <QtDebug>

PackageParser::PackageParser(const QString& filename) : Parser(filename)
{
}

PackageParser::~PackageParser()
{
}

PackageDataStore* PackageParser::parse(void)
{
  QFile file(m_fileName);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug("parse: can't open `%s' for reading", qPrintable(m_fileName));
    return NULL;
  }

  PackageDataStore* ds = new PackageDataStore;
  int index = -1;
  while (!file.atEnd()) {
    QString line = file.readLine().trimmed();
    if (line.startsWith("PKG")) {
      ++index;
      QString record = line.section(';', 0, 0).trimmed();
      QStringList p = record.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
      if (p.size() >= 7) {
        PackageDataStore::PackageInfo info;
        info.name = p[1];
        info.pitch = p[2].toDouble();
        info.xmin = p[3].toDouble();
        info.ymin = p[4].toDouble();
        info.xmax = p[5].toDouble();
        info.ymax = p[6].toDouble();
        ds->addPackage(index, info);
      }
    }
  }
  return ds;
}
