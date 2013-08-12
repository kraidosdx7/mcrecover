/***************************************************************************
 * GameCube Memory Card Recovery Program.                                  *
 * TaskbarButtonManager.cpp: Taskbar button manager base class.            *
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

#include "TaskbarButtonManager.hpp"

// Qt includes.
#include <QtGui/QWidget>

class TaskbarButtonManagerPrivate
{
	public:
		TaskbarButtonManagerPrivate(TaskbarButtonManager *const q);
		~TaskbarButtonManagerPrivate();

	private:
		TaskbarButtonManager *const q;
		Q_DISABLE_COPY(TaskbarButtonManagerPrivate);

	public:
		// Window.
		QWidget *window;

		// Status elements.
		int progressBarValue;	// Current progress. (-1 for no bar)
		int progressBarMax;	// Maximum progress.
};


TaskbarButtonManagerPrivate::TaskbarButtonManagerPrivate(TaskbarButtonManager *const q)
	: q(q)
	, window(nullptr)
	, progressBarValue(0)
	, progressBarMax(100)
{ }


TaskbarButtonManagerPrivate::~TaskbarButtonManagerPrivate()
{ }


/** TaskbarButtonManager **/


TaskbarButtonManager::TaskbarButtonManager(QObject* parent)
	: QObject(parent)
	, d(new TaskbarButtonManagerPrivate(this))
{ }

TaskbarButtonManager::~TaskbarButtonManager()
	{ delete d; }


/**
 * Get the window this TaskbarButtonManager is managing.
 * @return Window.
 */
QWidget *TaskbarButtonManager::window(void) const
	{ return d->window; }

/**
 * Set the window this TaskbarButtonManager should manage.
 * This must be a top-level window in order to work properly.
 * @param window Window.
 */
void TaskbarButtonManager::setWindow(QWidget *window)
{
	if (d->window) {
		// Disconnect slots from the existing window.
		disconnect(d->window, SIGNAL(destroyed(QObject*)),
			   this, SLOT(windowDestroyed_slot(QObject*)));
	}

	d->window = window;

	if (d->window) {
		// Connect slots to the new window.
		connect(d->window, SIGNAL(destroyed(QObject*)),
			this, SLOT(windowDestroyed_slot(QObject*)));
	}
}


/**
 * Clear the progress bar.
 */
void TaskbarButtonManager::clearProgressBar(void)
{
	d->progressBarValue = -1;
	d->progressBarMax = -1;
	this->update();
}

/**
 * Get the progress bar value.
 * @return Value.
 */
int TaskbarButtonManager::progressBarValue(void) const
	{ return d->progressBarValue; }

/**
 * Set the progress bar value.
 * @param value Value.
 */
void TaskbarButtonManager::setProgressBarValue(int value)
{
	if (d->progressBarValue != value) {
		d->progressBarValue = value;
		this->update();
	}
}

/**
 * Get the progress bar's maximum value.
 * @return Maximum value.
 */
int TaskbarButtonManager::progressBarMax(void) const
	{ return d->progressBarMax; }

/**
 * Set the progress bar's maximum value.
 * @param max Maximum value.
 */
void TaskbarButtonManager::setProgressBarMax(int max)
{
	if (d->progressBarMax != max) {
		d->progressBarMax = max;
		this->update();
	}
}


/** Slots **/


/**
 * Window we're managing was destroyed.
 * @param obj QObject that was destroyed.
 */
void TaskbarButtonManager::windowDestroyed_slot(QObject *obj)
{
	if (!d->window || !obj)
		return;

	if (obj == d->window) {
		// This was our window.
		// TODO: Make a base close() function?
		this->setWindow(nullptr);
	}
}
