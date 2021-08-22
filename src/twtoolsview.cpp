/*
    SPDX-FileCopyrightText: 2021 David Dyess II <david.dyess@gmail.com>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

// application headers
#include "twtoolsview.h"

#include "twtoolsSettings.h"
#include "twtoolsdebug.h"


twtoolsView::twtoolsView(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);
    handleSettingsChanged();
}

twtoolsView::~twtoolsView()
{
}

void twtoolsView::switchColors()
{
    // switch the foreground/background colors of the label
    QColor color = twtoolsSettings::colorBackground();
    twtoolsSettings::setColorBackground(twtoolsSettings::colorForeground());
    twtoolsSettings::setColorForeground(color);

    handleSettingsChanged();
}

void twtoolsView::handleSettingsChanged()
{
    qCDebug(TWTOOLS) << "twtoolsView::handleSettingsChanged()";
    QPalette palette = m_ui.templateLabel->palette();
    palette.setColor(QPalette::Window, twtoolsSettings::colorBackground());
    palette.setColor(QPalette::WindowText, twtoolsSettings::colorForeground());
    m_ui.templateLabel->setPalette(palette);

    // i18n : internationalization
    m_ui.templateLabel->setText(i18n("This project is %1 days old", twtoolsSettings::ageInDays()));
}

