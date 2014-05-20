TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
CONFIG(debug, release|debug):DEFINES += _DEBUG
unix:DEFINES += CLIP_NEAR_Z_MINUS_ONE

SOURCES += \
    Main.cpp

include(Controls/Controls.pri)
include(Core/Core.pri)
include(Game/Game.pri)
include(Rendering/Rendering.pri)

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Core/debug/ -lCore
else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Release/Core/ -lCore
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Core/ -lCore

INCLUDEPATH += $$PWD/../../Substitute/Source/Core
DEPENDPATH += $$PWD/../../Substitute/Source/Core

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Core/release/libCore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Core/debug/libCore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Core/release/Core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Core/debug/Core.lib
else:unix:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Release/Core/libCore.a
else:unix:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Core/libCore.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Backend/release/ -lBackend
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Backend/debug/ -lBackend
else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Release/Backend/ -lBackend
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Backend/ -lBackend

INCLUDEPATH += $$PWD/../../Substitute/Source/Backend
DEPENDPATH += $$PWD/../../Substitute/Source/Backend

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Backend/release/libBackend.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Backend/debug/libBackend.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Backend/release/Backend.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Backend/debug/Backend.lib
else:unix:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Release/Backend/libBackend.a
else:unix:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Backend/libBackend.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Base/release/ -lBase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Base/debug/ -lBase
else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Release/Base/ -lBase
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Base/ -lBase

INCLUDEPATH += $$PWD/../../Substitute/Source/Base
DEPENDPATH += $$PWD/../../Substitute/Source/Base

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Base/release/libBase.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Base/debug/libBase.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Base/release/Base.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Base/debug/Base.lib
else:unix:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Release/Base/libBase.a
else:unix:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Base/libBase.a

unix|win32: LIBS += -lGL
unix|win32: LIBS += -lphysfs
unix|win32: LIBS += -langelscript
unix|win32: LIBS += -lfreeimage
unix|win32: LIBS += -lpthread
unix|win32: LIBS += -lGLEW

unix|win32: LIBS += -ldl
unix|win32: LIBS += -l:libSDL2.a

unix|win32: LIBS += -lfreetype
