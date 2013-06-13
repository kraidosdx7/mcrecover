/***************************************************************************
 * GameCube Memory Card Recovery Program.                                  *
 * VarReplace.hpp: Variable replacement functions.                         *
 *                                                                         *
 * Copyright (c) 2013 by David Korth.                                      *
 *                                                                         *
 * This program is free software; you can redistribute it and/or modify it *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation; either version 2 of the License, or (at your  *
 * option) any later version.                                              *
 *                                                                         *
 * This program is distributed in the hope that it will be useful, but     *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License along *
 * with this program; if not, write to the Free Software Foundation, Inc., *
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.           *
 ***************************************************************************/

#ifndef __MCRECOVER_VARREPLACE_HPP__
#define __MCRECOVER_VARREPLACE_HPP__

// Qt includes.
#include <QtCore/qglobal.h>
#include <QtCore/QHash>
#include <QtCore/QString>
#include <QtCore/QVector>

class VarReplace
{
	private:
		VarReplace();
		~VarReplace();

	private:
		Q_DISABLE_COPY(VarReplace);

	public:
		/**
		 * Replace variables in a given string.
		 * @param str String to replace variables in.
		 * @param vars QHash containing variables for replacement.
		 *
		 * QHash format:
		 * - key: variable name
		 * - value: variable value
		 *
		 * @return str with replaced variables.
		 */
		static QString Exec(QString str, QHash<QString, QString> vars);

		/**
		 * Replace variables in a given string.
		 * @param str String to replace variables in.
		 * @param gameDescVars Game description variables. ($G1, $G2, etc)
		 * @param gameDescVars Game description variables. ($F1, $F2, etc)
		 *
		 * NOTE: The first variable in each QVector ($G0, $F0) is
		 * the full match from PCRE. This usually won't be used,
		 * but is included in the variable hash anyway.
		 *
		 * @return str with replaced variables.
		 */
		static QString Exec(QString str,
				    QVector<QString> gameDescVars,
				    QVector<QString> fileDescVars);
};

#endif /* __MCRECOVER_VARREPLACE_HPP__ */