/*
    SPDX-FileCopyrightText: 2021 David Dyess II <david.dyess@gmail.com>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

// application header
#include "twtoolswindow.h"
#include "twtoolsdebug.h"

// KF headers
#include <KCrash>
#include <KDBusService>
#include <KAboutData>
#include <KLocalizedString>

// Qt headers
#include <QApplication>
#include <QCommandLineParser>
#include <QIcon>
#include <QLoggingCategory>


int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    KLocalizedString::setApplicationDomain("twtools");
    KCrash::initialize();

    KAboutData aboutData( QStringLiteral("twtools"),
                          i18n("twtools"),
                          QStringLiteral("0.1"),
                          i18n("A Simple Application written with KDE Frameworks"),
                          KAboutLicense::GPL,
                          i18n("Copyright 2021, David Dyess II <david.dyess@gmail.com>"));

    aboutData.addAuthor(i18n("David Dyess II"),i18n("Author"), QStringLiteral("david.dyess@gmail.com"));
    aboutData.setOrganizationDomain("example.org");
    aboutData.setDesktopFileName(QStringLiteral("org.example.twtools"));

    KAboutData::setApplicationData(aboutData);
    application.setWindowIcon(QIcon::fromTheme(QStringLiteral("twtools")));

    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);

    parser.process(application);
    aboutData.processCommandLine(&parser);

    KDBusService appDBusService(KDBusService::Multiple | KDBusService::NoExitOnFailure);

    twtoolsWindow *window = new twtoolsWindow;
    window->show();

    return application.exec();
}
