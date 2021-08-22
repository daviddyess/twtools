/*
    SPDX-FileCopyrightText: 2021 David Dyess II <david.dyess@gmail.com>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

// application headers
#include "twtoolswindow.h"

#include "twtoolsview.h"
#include "twtoolsdebug.h"

// KF headers
#include <KActionCollection>
#include <KConfigDialog>


twtoolsWindow::twtoolsWindow()
    : KXmlGuiWindow()
{
    m_twtoolsView = new twtoolsView(this);
    setCentralWidget(m_twtoolsView);

    KActionCollection* actionCollection = this->actionCollection();
    m_switchAction = actionCollection->addAction(QStringLiteral("switch_action"));
    m_switchAction->setText(i18nc("@action", "Switch Colors"));
    m_switchAction->setIcon(QIcon::fromTheme(QStringLiteral("fill-color")));
    connect(m_switchAction, &QAction::triggered, m_twtoolsView, &twtoolsView::switchColors);

    KStandardAction::openNew(this, SLOT(fileNew()), actionCollection);
    KStandardAction::quit(qApp, SLOT(closeAllWindows()), actionCollection);
    KStandardAction::preferences(this, SLOT(settingsConfigure()), actionCollection);

    setupGUI();
}

twtoolsWindow::~twtoolsWindow()
{
}

void twtoolsWindow::fileNew()
{
    qCDebug(TWTOOLS) << "twtoolsWindow::fileNew()";
    (new twtoolsWindow)->show();
}

void twtoolsWindow::settingsConfigure()
{
    qCDebug(TWTOOLS) << "twtoolsWindow::settingsConfigure()";
    // The preference dialog is derived from prefs_base.ui
    //
    // compare the names of the widgets in the .ui file
    // to the names of the variables in the .kcfg file
    //avoid to have 2 dialogs shown
    if (KConfigDialog::showDialog(QStringLiteral("settings"))) {
        return;
    }

    KConfigDialog *dialog = new KConfigDialog(this, QStringLiteral("settings"), twtoolsSettings::self());
    QWidget *generalSettingsPage = new QWidget;
    m_settings.setupUi(generalSettingsPage);
    dialog->addPage(generalSettingsPage, i18nc("@title:tab", "General"), QStringLiteral("package_setting"));
    connect(dialog, &KConfigDialog::settingsChanged, m_twtoolsView, &twtoolsView::handleSettingsChanged);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}
