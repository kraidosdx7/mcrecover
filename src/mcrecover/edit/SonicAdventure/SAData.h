/***************************************************************************
 * GameCube Memory Card Recovery Program.                                  *
 * SAData.h: Sonic Adventure - Miscellaneous data.                         *
 *                                                                         *
 * Copyright (c) 2015-2016 by David Korth.                                 *
 * Original data from SASave by MainMemory.                                *
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

#ifndef __MCRECOVER_EDIT_SONICADVENTURE_SADATA_H__
#define __MCRECOVER_EDIT_SONICADVENTURE_SADATA_H__

// NOTE: Many of the event flags are unused, so instead of using
// an array, we're using a struct of event flags.
// FIXME: Alignment on 64-bit?
#include "../models/bit_flag.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SA_EVENT_FLAGS_COUNT 127
extern const bit_flag_t sa_event_flags_desc[SA_EVENT_FLAGS_COUNT+1];

#define SADX_MISSION_FLAGS_COUNT 60
extern const bit_flag_t sadx_mission_flags_desc[SADX_MISSION_FLAGS_COUNT+1];

/**
 * Character mapping for missions.
 * 0 == Sonic, 1 == Tails, 2 == Knuckles,
 * 3 == Amy, 4 == Gamma, 5 == Big
 */
extern const uint8_t sadx_mission_flags_char[SADX_MISSION_FLAGS_COUNT];

/**
 * Level names. (ASCII, untranslated)
 * Contains Action Stages only, in the order of Sonic's story,
 * with "Hot Shelter" afterwards.
 */
#define SA_LEVEL_NAMES_ACTION_COUNT 11
extern const char *const sa_level_names_action[SA_LEVEL_NAMES_ACTION_COUNT];

/**
 * Level names. (ASCII, untranslated)
 * Contains all levels, not just Action Stages.
 * NOTE: Chao Gardens have line breaks for formatting purposes.
 */
#define SA_LEVEL_NAMES_ALL_COUNT 43
extern const char *const sa_level_names_all[SA_LEVEL_NAMES_ALL_COUNT];

/** User Interface **/

/**
 * Character icons. (Main characters only)
 */
#define SA_UI_CHAR_ICONS_COUNT 6
extern const char *const sa_ui_char_icons[SA_UI_CHAR_ICONS_COUNT];

/**
 * Character names. (Main characters only)
 */
#define SA_UI_CHAR_NAMES_COUNT SA_UI_CHAR_ICONS_COUNT
extern const char *const sa_ui_char_names[SA_UI_CHAR_NAMES_COUNT];

/**
 * Character icons. (With Super Sonic)
 * This array includes a placeholder for an unused character.
 */
#define SA_UI_CHAR_ICONS_SUPER_COUNT 8
extern const char *const sa_ui_char_icons_super[SA_UI_CHAR_ICONS_SUPER_COUNT];

/**
 * Character names. (With Super Sonic)
 * This array includes a placeholder for an unused character.
 */
#define SA_UI_CHAR_NAMES_SUPER_COUNT SA_UI_CHAR_ICONS_SUPER_COUNT
extern const char *const sa_ui_char_names_super[SA_UI_CHAR_NAMES_SUPER_COUNT];

/**
 * Qt CSS for Emblem checkboxes.
 * Reference: http://stackoverflow.com/questions/5962503/qt-checkbox-toolbutton-with-custom-distinct-check-unchecked-icons
 */
extern const char sa_ui_css_emblem_checkbox[];

/**
 * Qt CSS for Emblem checkboxes. (large size)
 * Reference: http://stackoverflow.com/questions/5962503/qt-checkbox-toolbutton-with-custom-distinct-check-unchecked-icons
 */
extern const char sa_ui_css_emblem_checkbox_large[];

#ifdef __cplusplus
}
#endif

#endif /* __MCRECOVER_EDIT_SONICADVENTURE_SADATA_H__ */
