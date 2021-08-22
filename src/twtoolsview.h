/*
    SPDX-FileCopyrightText: 2021 David Dyess II <david.dyess@gmail.com>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#ifndef TWTOOLSVIEW_H
#define TWTOOLSVIEW_H

#include "ui_twtoolsview.h"


/**
 * This class serves as the main window for twtools.  It handles the
 * menus, toolbars and status bars.
 *
 * @short Main window class
 * @author David Dyess II <david.dyess@gmail.com>
 * @version 0.1
 */
class twtoolsView : public QWidget
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    explicit twtoolsView(QWidget *parent);

    /**
     * Default Destructor
     */
    ~twtoolsView() override;

public Q_SLOTS:
    void switchColors();
    void handleSettingsChanged();

private:
    // this is the name of the root widget inside our Ui file
    // you can rename it in designer and then change it here
    Ui::twtoolsView m_ui;
};

#endif // TWTOOLSVIEW_H
