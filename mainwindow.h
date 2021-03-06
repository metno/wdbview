/*
 wdbview

 Copyright (C) 2013 met.no

 Contact information:
 Norwegian Meteorological Institute
 Box 43 Blindern
 0313 OSLO
 NORWAY
 E-mail: post@met.no

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 MA  02110-1301, USA
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QPixmap>

class GridData;
class GridDataDisplayWidget;


/**
 * Main window, putting data selection and display together, along with menus
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void mouseOverValue(float value) const;

public slots:
    void updateStatus(const GridData * gridData);
    void updateCurrentValue(float mousovervalue);

private slots:

    void mouseAtImageIndex(int x,int y) const;
    void mouseLeftImageDisplay() const;

    void zoomIn();
    void zoomOut();

private:
    const GridData * gridData_;
    GridDataDisplayWidget * display;
    double zoom_;
};

#endif // MAINWINDOW_H
