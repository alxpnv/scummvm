/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef ASYLUM_RESOURCE_H
#define ASYLUM_RESOURCE_H

#include "common/str.h"
#include "common/array.h"

#define RES_FILE_PREFIX			"res.0%02d"
#define RESVOICE_FILE_PREFIX	"res.%d04"


namespace Asylum {

class ResourceItem;

class Resource {
public:
	Resource();
	Resource(uint32 resource);
    ~Resource();

	int load(uint32 resource);
	int load(Common::String filename);
	void dump();

	uint32 getSize() {
		return _size;
	}
	uint32 getNumEntries() {
		return _numEntries;
	}
	ResourceItem getResource(uint32 pos);
	
	// TODO: add new getResource methods which by resource index and position
	// return ResourceItem without reading the entire resource file

private:
	uint32 getNextValidOffset(uint8 startPos);

    Common::String _filename;
	bool _loaded;
	uint32 _size;
	uint32 _numEntries;
	Common::Array<ResourceItem> _items;

}; // end of class Resource

class ResourceItem {
public:
	ResourceItem();
	~ResourceItem();

	void dump();
	int save(Common::String filename);

	uint32 offset;
	uint32 size;
	uint8 *data;

}; // end of class ResourceItem


} // end of namespace Asylum

#endif