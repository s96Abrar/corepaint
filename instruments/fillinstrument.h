/*
CorePaint is paint app

CorePaint is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see {http://www.gnu.org/licenses/}. */

#ifndef FILLINSTRUMENT_H
#define FILLINSTRUMENT_H

#include "abstractinstrument.h"
#include "../imagearea.h"
#include "../datasingleton.h"

#include <QObject>
#include <QPen>
#include <QPainter>


class FillInstrument : public AbstractInstrument
{
    Q_OBJECT
public:
    explicit FillInstrument(QObject *parent = 0);
    
    void mousePressEvent(QMouseEvent *event, ImageArea &imageArea);
    void mouseMoveEvent(QMouseEvent *event, ImageArea &imageArea);
    void mouseReleaseEvent(QMouseEvent *event, ImageArea &imageArea);

protected:
    void paint(ImageArea &imageArea, bool isSecondaryColor = false, bool additionalFlag = false);

private:
    void fillRecurs(int x, int y, QRgb switchColor, QRgb oldColor, QImage &tempImage);
    
};

#endif // FILLINSTRUMENT_H
