/*
  declarativesyntaxhighlighter_p.h

  This file is part of DeclarativeWidgets, library and tools for creating QtWidget UIs with QML.

  Copyright (C) 2025 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com

  Licensees holding valid commercial KDAB DeclarativeWidgets licenses may use this file in
  accordance with DeclarativeWidgets Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "declarativesyntaxhighlighter_p.h"

DeclarativeSyntaxHighlighter::DeclarativeSyntaxHighlighter(QObject *parent)
    : QSyntaxHighlighter(parent)
{
}

DeclarativeSyntaxHighlighter::DeclarativeSyntaxHighlighter(QTextDocument *document)
    : QSyntaxHighlighter(document)
{
}

void DeclarativeSyntaxHighlighter::highlightBlock(const QString &text)
{
    Q_EMIT highlightRequested(text);
}

void DeclarativeSyntaxHighlighter::setFormat(int start, int count, QColor color)
{
    QSyntaxHighlighter::setFormat(start, count, color);
}

QTextDocument* DeclarativeSyntaxHighlighter::document() const
{
    return QSyntaxHighlighter::document();
}

void DeclarativeSyntaxHighlighter::setDocument(QTextDocument* document)
{
    if (document != this->document()) {
        QSyntaxHighlighter::setDocument(document);
        emit documentChanged();
    }
}
