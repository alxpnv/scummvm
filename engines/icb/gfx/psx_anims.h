/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
 *
 * Additional copyright for this file:
 * Copyright (C) 1999-2000 Revolution Software Ltd.
 * This code is based on source code created by Revolution Software,
 * used with permission.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef ICB_PSX_ANIMS_HH
#define ICB_PSX_ANIMS_HH

#include "engines/icb/debug.h"
#include "engines/icb/common/px_common.h"
#include "engines/icb/common/px_anims.h"

namespace ICB {

static inline PXframe_PSX *psxFrameEnOfAnim(uint32 n, PXanim_PSX *pAnim, const char *file, const int32 line) {
	// Convert to the new schema
	ConvertPXanim(pAnim);
	if (n >= pAnim->frame_qty) {
		Real_Fatal_error("Illegal frame %d %d %s %d", n, pAnim->frame_qty, file, line);
		error("Should exit with error-code -1");
		return NULL;
	}
	return (PXframe_PSX *)((uint8 *)pAnim + pAnim->offsets[n]);
}

static inline void psxMatrixToAngles(PXorient_PSX &orient, PXfloat &pan, PXfloat &tilt, PXfloat &cant) {
	pan = orient.pan;
	tilt = orient.tilt;
	cant = orient.cant;
}

} // End of namespace ICB

#endif // #ifndef PSX_ANIMS_HH