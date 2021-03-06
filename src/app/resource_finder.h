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

#ifndef APP_RESOURCE_FINDER_H_INCLUDED
#define APP_RESOURCE_FINDER_H_INCLUDED
#pragma once

#include "base/disable_copying.h"

#include <string>
#include <vector>

namespace app {

  // Helper class to find configuration files in different directories
  // in a priority order (e.g. first in the $HOME directory, then in
  // data/ directory, etc.).
  class ResourceFinder {
  public:
    ResourceFinder(bool log = true);

    // Returns the current possible path. You cannot call this
    // function if you haven't call first() or next() before.
    const std::string& filename() const;
    const std::string& defaultFilename() const;

    // Goes to next possible path.
    bool next();

    // Iterates over all possible paths and returns true if the file
    // is exists. Returns the first existent file.
    bool findFirst();

    // These functions add possible full paths to find files.
    void addPath(const std::string& path);
    void includeBinDir(const char* filename);
    void includeDataDir(const char* filename);
    void includeHomeDir(const char* filename);

    // Tries to add the given filename in these locations:
    // For Windows:
    // - If the app is running in portable mode, the filename
    //   will be in the same location as the .exe file.
    // - If the app is installed, the filename will be inside
    //   %AppData% location
    // For Unix-like platforms:
    // - The filename will be in $HOME/.config/aseprite/
    void includeUserDir(const char* filename);

    // Returns the first file found or creates the whole directory
    // structure to create the file in its default location.
    std::string getFirstOrCreateDefault();

  private:
    bool m_log;
    std::vector<std::string> m_paths;
    int m_current;
    std::string m_default;

    DISABLE_COPYING(ResourceFinder);
  };

} // namespace app

#endif
