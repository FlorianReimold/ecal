@echo off

pushd "%~dp0\.."

call build_win\win_set_vars.bat

set CMAKE_OPTIONS_COMPLETE=-DCMAKE_INSTALL_PREFIX=_install ^
-DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=cmake/submodule_dependencies.cmake ^
-DECAL_USE_HDF5=ON ^
-DECAL_USE_QT=ON ^
-DECAL_USE_CURL=ON ^
-DECAL_USE_CAPNPROTO=OFF ^
-DECAL_USE_FTXUI=ON ^
-DECAL_BUILD_DOCS=ON ^
-DECAL_BUILD_APPS=ON ^
-DECAL_BUILD_SAMPLES=ON ^
-DECAL_BUILD_TIMEPLUGINS=ON ^
-DECAL_BUILD_PY_BINDING=OFF ^
-DECAL_BUILD_CSHARP_BINDING=ON ^
-DECAL_BUILD_TESTS=ON ^
-DECAL_INSTALL_SAMPLE_SOURCES=ON ^
-DECAL_USE_NPCAP=ON ^
-DECAL_THIRDPARTY_BUILD_CMAKE_FUNCTIONS=ON ^
-DECAL_THIRDPARTY_BUILD_PROTOBUF=ON ^
-DECAL_THIRDPARTY_BUILD_TINYXML2=ON ^
-DECAL_THIRDPARTY_BUILD_FINEFTP=ON ^
-DECAL_THIRDPARTY_BUILD_CURL=ON ^
-DECAL_THIRDPARTY_BUILD_GTEST=ON ^
-DECAL_THIRDPARTY_BUILD_HDF5=ON ^
-DECAL_THIRDPARTY_BUILD_RECYCLE=ON ^
-DECAL_THIRDPARTY_BUILD_TCP_PUBSUB=ON ^
-DECAL_THIRDPARTY_BUILD_QWT=ON ^
-DECAL_THIRDPARTY_BUILD_UDPCAP=ON ^
-DBUILD_SHARED_LIBS=OFF ^
-DCMAKE_BUILD_TYPE=Release ^
-DECAL_CPACK_PACK_WITH_INNOSETUP=ON

set CMAKE_OPTIONS_SDK=-DCMAKE_INSTALL_PREFIX=_install ^
-DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=cmake/submodule_dependencies.cmake ^
-DECAL_USE_HDF5=ON ^
-DECAL_USE_QT=ON ^
-DECAL_USE_CURL=OFF ^
-DECAL_USE_CAPNPROTO=OFF ^
-DECAL_USE_FTXUI=ON ^
-DECAL_BUILD_DOCS=OFF ^
-DECAL_BUILD_APPS=OFF ^
-DECAL_BUILD_SAMPLES=OFF ^
-DECAL_BUILD_TIMEPLUGINS=ON ^
-DECAL_BUILD_PY_BINDING=OFF ^
-DECAL_BUILD_CSHARP_BINDING=OFF ^
-DECAL_BUILD_TESTS=OFF ^
-DECAL_INSTALL_SAMPLE_SOURCES=OFF ^
-DECAL_USE_NPCAP=ON ^
-DECAL_THIRDPARTY_BUILD_CMAKE_FUNCTIONS=ON ^
-DECAL_THIRDPARTY_BUILD_PROTOBUF=ON ^
-DECAL_THIRDPARTY_BUILD_TINYXML2=ON ^
-DECAL_THIRDPARTY_BUILD_FINEFTP=OFF ^
-DECAL_THIRDPARTY_BUILD_CURL=OFF ^
-DECAL_THIRDPARTY_BUILD_GTEST=OFF ^
-DECAL_THIRDPARTY_BUILD_HDF5=ON ^
-DECAL_THIRDPARTY_BUILD_RECYCLE=ON ^
-DECAL_THIRDPARTY_BUILD_TCP_PUBSUB=ON ^
-DECAL_THIRDPARTY_BUILD_QWT=OFF ^
-DECAL_THIRDPARTY_BUILD_UDPCAP=ON ^
-DBUILD_SHARED_LIBS=OFF ^
-DCMAKE_BUILD_TYPE=Debug ^
-DECAL_CPACK_PACK_WITH_INNOSETUP=OFF

if not exist "%BUILD_DIR_COMPLETE%" mkdir "%BUILD_DIR_COMPLETE%"
if not exist "%BUILD_DIR_SDK%" mkdir "%BUILD_DIR_SDK%"

echo Creating Python venv
if not exist "%BUILD_DIR_COMPLETE%\.venv" mkdir "%BUILD_DIR_COMPLETE%\.venv"
python -m venv "%BUILD_DIR_COMPLETE%\.venv"
CALL "%BUILD_DIR_COMPLETE%\.venv\Scripts\activate.bat"

echo Upgrading pip
python -m pip install --upgrade pip

echo Installing python requirements
pip install wheel
pip install -r doc\requirements.txt

cd /d "%WORKSPACE%\%BUILD_DIR_COMPLETE%"
cmake ../.. -A x64 %CMAKE_OPTIONS_COMPLETE% %*

cd /d "%WORKSPACE%\%BUILD_DIR_SDK%"
cmake ../.. -A x64 %CMAKE_OPTIONS_SDK% %*

popd
