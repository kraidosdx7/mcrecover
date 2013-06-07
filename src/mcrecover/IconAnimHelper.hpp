/***************************************************************************
 * GameCube Memory Card Recovery Program.                                  *
 * IconAnimHelper.hpp: Icon animation helper.                              *
 *                                                                         *
 * Copyright (c) 2012-2013 by David Korth.                                 *
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

#ifndef __MCRECOVER_ICONANIMHELPER_HPP__
#define __MCRECOVER_ICONANIMHELPER_HPP__

// Qt includes.
#include <QtCore/QObject>
#include <QtGui/QPixmap>

class MemCardFile;

class IconAnimHelperPrivate;

class IconAnimHelper : public QObject
{
	Q_OBJECT

	public:
		IconAnimHelper();
		IconAnimHelper(const MemCardFile *file);
		~IconAnimHelper();

	private:
		friend class IconAnimHelperPrivate;
		IconAnimHelperPrivate *const d;
		Q_DISABLE_COPY(IconAnimHelper);

	public:
		/**
		 * Time, in ms, for each frame for "fast" animated icons.
		 * TODO: Figure out the correct timer interval.
		 */
		static const int FAST_ANIM_TIMER = 125;

		/**
		 * Get the MemCardFile this IconAnimHelper is handling.
		 * @return MemCardFile.
		 */
		const MemCardFile *file(void) const;

		/**
		 * Set the MemCardFile this IconAnimHelper should handle.
		 * @param file MemCardFile.
		 */
		void setFile(const MemCardFile *file);

		/**
		 * Reset the animation state.
		 */
		void reset(void);

		/**
		 * Does this file have an animated icon?
		 * @return True if the icon is animated; false if not, or if no file is loaded.
		 */
		bool isAnimated(void) const;

		/**
		 * Get the current icon for this file.
		 * @return Current icon.
		 */
		QPixmap icon(void) const;

		/**
		 * Timer tick for the animation counter.
		 * @return True if the current icon has been changed; false if not.
		 */
		bool tick(void);

	protected slots:
		/**
		 * MemCardFile object was destroyed.
		 * @param obj QObject that was destroyed.
		 */
		void memCardFile_destroyed_slot(QObject *obj = 0);
};

#endif /* __MCRECOVER_ICONANIMHELPER_HPP__ */