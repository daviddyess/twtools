/*
    SPDX-FileCopyrightText: 2021 David Dyess II <david.dyess@gmail.com>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#ifndef TWTOOLSWINDOW_H
#define TWTOOLSWINDOW_H

#include <KXmlGuiWindow>

#include "ui_settings.h"
#include "twtoolsSettings.h"

class twtoolsView;

/**
 * This class serves as the main window for twtools.  It handles the
 * menus, toolbars and status bars.
 *
 * @short Main window class
 * @author David Dyess II <david.dyess@gmail.com>
 * @version 0.1
 */
class twtoolsWindow : public KXmlGuiWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    twtoolsWindow();

    /**
     * Default Destructor
     */
    ~twtoolsWindow() override;

private Q_SLOTS:
    /**
     * Create a new window
     */
    void fileNew();

    /**
     * Open the settings dialog
     */
    void settingsConfigure();

private:
    // this is the name of the root widget inside our Ui file
    // you can rename it in designer and then change it here
    Ui::Settings m_settings;
    QAction *m_switchAction;
    twtoolsView *m_twtoolsView;
};

#endif // TWTOOLSWINDOW_H
