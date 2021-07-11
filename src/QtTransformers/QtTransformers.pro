NAME         = QtTransformers
TARGET       = $${NAME}
QT           = core
QT          -= gui
QT          -= script
QT          += QtUUID

INCLUDEPATH += $${PWD}
HEADERS     += $${PWD}/qttransformers.h

SOURCES     += $${PWD}/transformers.cpp

load(qt_module)
