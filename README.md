## MagicSpout

MagicSpoutSender is a module for Magic Music Visuals to send textures to receivers using the Spout protocol. It supplements the main Magic Spout output so that individual outputs can be included in a project.

## Updates
14.06.21 - Create repository

## Setup

1. MagicSpoutSender project files are for Visual studio 2017 for Windows.
Before opening the solution or project, the following files must be added.
2. The Magic Music Visuals Module Development Kit (MDK)
    - [Visit the MDK download page](https://magicmusicvisuals.com/developers) and download "Magic MDK v2.3" and save to a convenient folder.
    - Extract the single file "MagicModule.h" and copy it to the project folder containing MagicSpoutSender.cpp.
3. The Spout 2.007 SDK for OpenGL.
    - [Visit the Spout repository](https://github.com/leadedge/Spout2)
    - Click "Clone or Download", "Download ZIP" and save to a convenient folder.
    - Unzip the contents and copy all the .cpp and .h files from the repository "../SPOUTSDK/SpoutGL/" folder to the project "SpoutGL" folder.
4. Open the project solution file with Visual Studio 2017, change to release and build.
5. The project may also be opened with Visual Studio 2019 and allow upgrade.

## Copyrights

MagicSpoutSender - Copyright(C) 2021 Lynn Jarvis [https://spout.zeal.co/]

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser  General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.  You should have received a copy of the GNU Lesser General Public License along with this program. If not, see [http://www.gnu.org/licenses/](http://www.gnu.org/licenses).

----------------------

[Magic Music Visuals](https://magicmusicvisuals.com/) Copyright (c) 2021 Color & Music, LLC.

/*
 * Magic Module Development Kit (MDK) v2.3
 * Copyright (c) 2012-2020 Color & Music, LLC.  All rights reserved.
 *
 * The MDK is provided "as is" without any express or implied warranty
 * of any kind, oral or written, including warranties of merchantability,
 * fitness for any particular purpose, non-infringement, information
 * accuracy, integration, interoperability, or quiet enjoyment.  In no
 * event shall Color & Music, LLC or its suppliers be liable for any
 * damages whatsoever (including, without limitation, damages for loss
 * of profits, business interruption, loss of information, or physical
 * damage to hardware or storage media) arising out of the use of, misuse
 * of, or inability to use the MDK, your reliance on any content in the
 * MDK, or from the modification, alteration or complete discontinuance
 * of the MDK, even if Color & Music, LLC has been advised of the
 * possibility of such damages.
 */
 
----------------------
