#pragma once

#include "AEConfig.h"

#ifdef AE_OS_WIN
	typedef unsigned short PixelType;
	#include <Windows.h>
#endif

#include <iostream>

#include "entry.h"
#include "AE_Effect.h"
#include "Param_Utils.h"
#include "AE_EffectCBSuites.h"


enum class STAGE_VERSION {
	DEVELOP,
	ALPHA,
	BETA,
	RELEASE,
};

#define MAJOR_VERSION 1
#define MINOR_VERSION 0
#define BUG_VERSION   0
#define STAGE_VERSION STAGE_VERSION::DEVELOP
#define BUILD_VERSION 0


extern "C" {
	DllExport PF_Err EffectMain (
		PF_Cmd         cmd,
		PF_InData      *in_data,
		PF_OutData     *out_data,
		PF_ParamDef    *params[],
		PF_LayerDef    *output,
		void           *extra
	);
}
