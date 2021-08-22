add_executable(twtools)

target_sources(twtools PRIVATE
    main.cpp
    twtoolswindow.cpp
    twtoolsview.cpp
)

ecm_qt_declare_logging_category(twtools
    HEADER twtoolsdebug.h
    IDENTIFIER TWTOOLS
    CATEGORY_NAME "twtools"
)
kconfig_add_kcfg_files(twtools twtoolsSettings.kcfgc)
ki18n_wrap_ui(twtools
    twtoolsview.ui
    settings.ui
)

target_link_libraries(twtools
    KF5::CoreAddons
    KF5::I18n
    KF5::XmlGui
    KF5::ConfigWidgets
    KF5::DBusAddons
    KF5::Crash
    Qt5::Widgets
)

install(TARGETS twtools ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
install(PROGRAMS org.example.twtools.desktop  DESTINATION ${KDE_INSTALL_APPDIR})
install(FILES org.example.twtools.appdata.xml DESTINATION ${KDE_INSTALL_METAINFODIR})
install(FILES twtoolsui.rc DESTINATION ${KDE_INSTALL_KXMLGUI5DIR}/twtools)
