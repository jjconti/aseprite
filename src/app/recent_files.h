/* Aseprite
 * Copyright (C) 2001-2013  David Capello
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef APP_RECENT_FILES_H_INCLUDED
#define APP_RECENT_FILES_H_INCLUDED
#pragma once

#include "base/recent_items.h"

#include <string>

namespace app {
  
  class RecentFiles {
  public:
    typedef base::RecentItems<std::string> List;
    typedef List::iterator iterator;
    typedef List::const_iterator const_iterator;

    // Iterate through recent files.
    const_iterator files_begin() { return m_files.begin(); }
    const_iterator files_end() { return m_files.end(); }

    // Iterate through recent paths.
    const_iterator paths_begin() { return m_paths.begin(); }
    const_iterator paths_end() { return m_paths.end(); }

    RecentFiles();
    ~RecentFiles();

    void addRecentFile(const char* filename);
    void removeRecentFile(const char* filename);

  private:
    List m_files;
    List m_paths;
  };

} // namespace app

#endif
