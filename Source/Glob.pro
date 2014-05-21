TEMPLATE = app
win32:QT += opengl
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
CONFIG(debug, release|debug):DEFINES += _DEBUG

DEFINES += CLIP_NEAR_Z_MINUS_ONE

SOURCES += \
    Main.cpp

include(Controls/Controls.pri)
include(Core/Core.pri)
include(Game/Game.pri)
include(Rendering/Rendering.pri)

win32:INCLUDEPATH += .

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Qt_5_3_0_MSVC2013_64bit-Release/Core/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Qt_5_3_0_MSVC2013_64bit-Debug/Core/debug -lCore
else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Release/Core/ -lCore
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Core/ -lCore

INCLUDEPATH += $$PWD/../../Substitute/Source/Core
DEPENDPATH += $$PWD/../../Substitute/Source/Core

win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Qt_5_3_0_MSVC2013_64bit-Release/Core/release/Core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Qt_5_3_0_MSVC2013_64bit-Debug/Core/debug/Core.lib
else:unix:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Release/Core/libCore.a
else:unix:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Core/libCore.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Qt_5_3_0_MSVC2013_64bit-Release/Backend/release/ -lBackend
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Qt_5_3_0_MSVC2013_64bit-Debug/Backend/debug/ -lBackend
else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Release/Backend/ -lBackend
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Backend/ -lBackend

INCLUDEPATH += $$PWD/../../Substitute/Source/Backend
DEPENDPATH += $$PWD/../../Substitute/Source/Backend

win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Qt_5_3_0_MSVC2013_64bit-Release/Backend/release/Backend.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Qt_5_3_0_MSVC2013_64bit-Debug/Backend/debug/Backend.lib
else:unix:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Release/Backend/libBackend.a
else:unix:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Backend/libBackend.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Qt_5_3_0_MSVC2013_64bit-Release/Base/release/ -lBase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Qt_5_3_0_MSVC2013_64bit-Debug/Base/debug/ -lBase
else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Release/Base/ -lBase
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Base/ -lBase

INCLUDEPATH += $$PWD/../../Substitute/Source/Base
DEPENDPATH += $$PWD/../../Substitute/Source/Base

win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Qt_5_3_0_MSVC2013_64bit-Release/Base/release/Base.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Qt_5_3_0_MSVC2013_64bit-Debug/Base/debug/Base.lib
else:unix:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Release/Base/libBase.a
else:unix:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Substitute/build-Substitute-Desktop_Clang_64bit-Debug/Base/libBase.a

unix: LIBS += -lGL
else:win32: LIBS += -lopengl32

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Libraries/physfs-2.0.3/build/Release/ -lphysfs
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Libraries/physfs-2.0.3/build/Debug/ -lphysfs
else:unix: LIBS += -lphysfs

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Libraries/angelscript_2.28.2/angelscript/lib/ -langelscript64
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Libraries/angelscript_2.28.2/angelscript/lib/ -langelscript64d
else:unix: LIBS += -langelscript

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Libraries/FreeImage-3.16.0/Dist/ -lFreeImage
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Libraries/FreeImage-3.16.0/Dist/ -lFreeImaged
else:unix: LIBS += -lfreeimage

unix: LIBS += -lpthread

win32:CONFIG(release, debug|release):  LIBS += -L$$PWD/../../../Libraries/glew-1.10.0/lib/Release/x64/ -lglew32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Libraries/glew-1.10.0/lib/Debug/x64/ -lglew32d
else:unix: LIBS += -lGLEW

unix: LIBS += -ldl

win32: LIBS += -L$$PWD/../../../Libraries/SDL2-2.0.3/lib\x64/ -lSDL2
else:unix: LIBS += -l:libSDL2.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Libraries/freetype-2.5.3/lib/ -lfreetype253
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Libraries/freetype-2.5.3/lib/ -lfreetype253_D
else:unix: LIBS += -lfreetype
