TEMPLATE = app
QT += widgets
CONFIG += debug_and_release

MOC_DIR = .build
UI_DIR = .build
RCC_DIR = .build
OBJECTS_DIR = .build
BUILD_DIR = .build

include (parser/parser.pri)
include (symbol/symbol.pri)
include (graphicsview/graphicsview.pri)
include (gui/gui.pri)

HEADERS += \
  archiveloader.h \
  context.h \
  macros.h \
  settings.h \
  symbolpool.h

SOURCES += \
  archiveloader.cpp \
  context.cpp \
  main.cpp \
  settings.cpp \
  symbolpool.cpp

RESOURCES += \
    resources.qrc

INCLUDEPATH += . .build parser parser/odbpp symbol gui graphicsview

DESTDIR = ../bin
TARGET = qcamber

# Product information
VERSION = 0.1.0
QMAKE_TARGET_PRODUCT = "QCamber"
QMAKE_TARGET_DESCRIPTION = "ODB++ Viewer"
QMAKE_TARGET_COPYRIGHT = "Copyright 2013 - 2025 QCamber Authors"
