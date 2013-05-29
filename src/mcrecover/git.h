/***************************************************************************
 * GameCube Memory Card Recovery Program.                                  *
 * git.h: Git version macros.                                              *
 * Gens: Git version macros.                                               *
 *                                                                         *
 * Copyright (c) 2008-2011 by David Korth.                                 *
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

#ifndef __MCRECOVER_GIT_H__
#define __MCRECOVER_GIT_H__

// git_version.h is generated by git_version.sh
#include "git_version.h"

// MCRECOVER_GIT_VERSION: Macro for the git revision, if available.
#ifdef GIT_REPO
	#ifdef GIT_BRANCH
		#define MCRECOVER_GIT_TMP_BRANCH GIT_BRANCH
		#ifdef GIT_SHAID
			#define MCRECOVER_GIT_TMP_SHAID "/" GIT_SHAID
		#else /* !GIT_SHAID */
			#define MCRECOVER_GIT_TMP_SHAID
		#endif /* GIT_SHAID */
	#else /* !GIT_BRANCH */
		#define MCRECOVER_GIT_TMP_BRANCH
		#ifdef GIT_SHAID
			#define MCRECOVER_GIT_TMP_SHAID GIT_SHAID
		#else /* !GIT_SHAID */
			#define MCRECOVER_GIT_TMP_SHAID
		#endif /* GIT_SHAID */
	#endif /* GIT_BRANCH */
	
	#ifdef GIT_DIRTY
		#define MCRECOVER_GIT_TMP_DIRTY "+"
	#else /* !GIT_DIRTY */
		#define MCRECOVER_GIT_TMP_DIRTY
	#endif /* GIT_DIRTY */
	
	#define MCRECOVER_GIT_VERSION "git: " MCRECOVER_GIT_TMP_BRANCH MCRECOVER_GIT_TMP_SHAID MCRECOVER_GIT_TMP_DIRTY
#else /* !GIT_REPO */
	#ifdef MCRECOVER_GIT_VERSION
		#undef MCRECOVER_GIT_VERSION
	#endif /* MCRECOVER_GIT_VERSION */
#endif /* GIT_REPO */

#endif /* __MCRECOVER_GIT_H__ */