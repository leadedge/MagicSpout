// =======================================================================================
//
//		MagicSpoutSender
//
//		Module plugin for Magic Music Visuals to send textures between programs.
//		This module is Windows only
//
//		Using :
//		 Magic Module Development Kit (MDK) v2.3 https://magicmusicvisuals.com/
//		 Copyright(c) 2012 - 2020 Color & Music, LLC.All rights reserved.
//
//		 Spout SDK
//		 Copyright(C) 2018 - 2021 Lynn Jarvis https://spout.zeal.co/
//
// =======================================================================================
//	This program is free software : you can redistribute it and/or modify
//	it under the terms of the GNU Lesser General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
//	GNU Lesser General Public License for more details.
//
//	You should have received a copy of the GNU Lesser General Public License
//	along with this program.If not, see <http://www.gnu.org/licenses/>.
//
//	Revisions :
//
//	17.06.19	- Create based on MagicNDIsender and Freeframe SpoutSender64
//				  Version 1.000
//	12.06.21	- Update to 2.007 SpoutGL
//				  Update to MDK v2.3
//				  Version 2.000 for testing
//	13.06.21	- Scene change working
//	14.06.21	- Version 2.001 GitHub release
//
// =======================================================================================

// Necessary for OpenGL
#include <windows.h>
#include <gl/gl.h>
#pragma comment(lib, "OpenGL32.Lib")

#include "MagicModule.h"
#include "..\SpoutGL\SpoutSender.h"

// Convenience definitions
#define PARAM_SenderName 0

// Number of parameters
#define NumParams 1

class MagicSpoutSenderModule : public MagicModule
{
	// see below (after class definition) for static value assignments
	static const MagicModuleSettings settings;
	static const MagicModuleParam params[NumParams];

public:

	MagicSpoutSenderModule() {
		SenderName[0] = 0; // no sender name to begin
	}

	~MagicSpoutSenderModule() {
		sender.ReleaseSender();
	}

	// getSettings() and getParams() are called whenever
	// a new instance of the module is created.
	const MagicModuleSettings *getSettings() {
		return &settings;
	}

	const MagicModuleParam *getParams() { 
		return params; 
	}

	// glInit, glClose, drawBefore not used

	void drawAfter(MagicUserData *userData) {
		if (userData->glState->currentFramebuffer > 0) {
			// Send a texture from the host fbo.
			// If there is no sender name, wait for user entry.
			if (SenderName[0])
				sender.SendFbo(userData->glState->currentFramebuffer, (unsigned int)userData->glState->viewportWidth, (unsigned int)userData->glState->viewportHeight);
		}
	}

	bool fixedParamValueChanged(const int whichParam, const char* newValue) {

		if (!newValue || !newValue[0])
			return false;

		switch (whichParam) {
			// Sender name entry
			// The sender is re-created by SendFbo
			case PARAM_SenderName:
				if (strcmp(newValue, SenderName) != 0) {
					sender.ReleaseSender(); // for repeats
					strcpy_s(SenderName, 256, newValue);
					sender.SetSenderName(SenderName); // for SendFbo
				}
				break;
		}

		return true;
	
	}

	const char *getHelpText() {
		return "Magic Spout Sender - Vers 2.001\n"
			"Lynn Jarvis 2019-2021\n\n"
			"Sends textures to Spout receivers\n"
			"Spout - https://spout.zeal.co/ \n\n"
			"Sender : sender name\n";
	}

protected:

	SpoutSender sender;
	char SenderName[256];

};


MagicModule *CreateInstance() {
	return new MagicSpoutSenderModule();
}

const MagicModuleSettings MagicSpoutSenderModule::settings = MagicModuleSettings(NumParams);

const MagicModuleParam MagicSpoutSenderModule::params[NumParams] = {
	MagicModuleParam("Sender", NULL, NULL, NULL, MVT_STRING, MWT_TEXTBOX, true, "Sender name")
};
