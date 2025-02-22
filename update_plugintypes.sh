export QML2_IMPORT_PATH=/data/sources/kdab/DeclarativeWidgets/build-rel-no-webengine6/qml
cmake --preset=rel-no-webengine6 &&
	cmake --build build-dev &&
	/usr/lib/qt6/bin/qmlplugindump QtWidgets 1.0 >src/qtwidgets.qmltypes &&
	grep -v "^[[:space:]]*exportMetaObjectRevisions: \[0\]" src/qtwidgets.qmltypes >tmp.qmltypes && mv tmp.qmltypes src/qtwidgets.qmltypes
