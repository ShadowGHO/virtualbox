/* $Id$ */
/** @file
 * VBox Qt GUI - UIVisoBrowserBase class declaration.
 */

/*
 * Copyright (C) 2006-2019 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifndef FEQT_INCLUDED_SRC_medium_viso_UIVisoBrowserBase_h
#define FEQT_INCLUDED_SRC_medium_viso_UIVisoBrowserBase_h
#ifndef RT_WITHOUT_PRAGMA_ONCE
# pragma once
#endif

/* Qt includes: */
#include <QModelIndex>
#include <QWidget>

/* GUI includes: */
#include "QIWithRetranslateUI.h"

/* Forward declarations: */
class QItemSelection;
class QGridLayout;
class QLabel;
class QMenu;
class QSplitter;
class QVBoxLayout;
class QTableView;
class QTreeView;
class UIToolBar;

class UIVisoBrowserBase : public QIWithRetranslateUI<QWidget>
{
    Q_OBJECT;

public:
    /** @p pMenu is the pointer to the menu related to this browser widget.
     *  any member actions will be added to this menu. */
    UIVisoBrowserBase(QWidget *pParent = 0, QMenu *pMenu = 0);
    ~UIVisoBrowserBase();
    virtual void showHideHiddenObjects(bool bShow) = 0;

public slots:

    void sltHandleTableViewItemDoubleClick(const QModelIndex &index);

protected:

    void prepareObjects();
    void prepareConnections();

    virtual void tableViewItemDoubleClick(const QModelIndex &index) = 0;
    virtual void treeSelectionChanged(const QModelIndex &selectedTreeIndex) = 0;
    virtual void setTableRootIndex(QModelIndex index = QModelIndex()) = 0;
    virtual void setTreeCurrentIndex(QModelIndex index = QModelIndex()) = 0;


    QTreeView          *m_pTreeView;
    QLabel             *m_pTitleLabel;
    QWidget            *m_pRightContainerWidget;
    QGridLayout        *m_pRightContainerLayout;
    UIToolBar          *m_pVerticalToolBar;
    QMenu              *m_pMenu;
private:
    QGridLayout    *m_pMainLayout;
    QSplitter      *m_pHorizontalSplitter;

private slots:

    void sltHandleTreeSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void sltHandleTreeItemClicked(const QModelIndex &modelIndex);

private:

};

#endif /* !FEQT_INCLUDED_SRC_medium_viso_UIVisoBrowserBase_h */
