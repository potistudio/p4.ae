#include "p4ae.hh"

#include <iostream>


static PF_Err About (PF_InData *in_data, PF_OutData *out_data, PF_ParamDef *params[], PF_LayerDef *output) {
	in_data->utils->ansi.sprintf (
		out_data->return_msg,
		"%s v%d.%d\r%s",
		"p4.ae",
		MAJOR_VERSION,
		MINOR_VERSION,
		"Processing for After Effects"
	);

	return PF_Err_NONE;
}

static PF_Err GlobalSetup (PF_InData *in_data, PF_OutData *out_data, PF_ParamDef *params[], PF_LayerDef *output) {
	PF_Err error = PF_Err_NONE;

	out_data->my_version = PF_VERSION (
		MAJOR_VERSION,
		MINOR_VERSION,
		BUG_VERSION,
		STAGE_VERSION,
		BUILD_VERSION
	);

	return error;
}

static PF_Err ParamsSetup (PF_InData *in_data, PF_OutData *out_data, PF_ParamDef *params[], PF_LayerDef *output) {
	PF_Err error = PF_Err_NONE;

	out_data->num_params = 1;

	return error;
}

static PF_Err Render (PF_InData *in_data, PF_OutData *out_data, PF_ParamDef *params[], PF_LayerDef *output) {
	PF_Err error = PF_Err_NONE;

	error = in_data->utils->copy (
		in_data->effect_ref,
		&params[0]->u.ld,
		output,
		NULL,
		NULL
	);

	return error;
}

extern "C" {
	DllExport PF_Err PluginDataEntryFunction2 (PF_PluginDataPtr inPtr, PF_PluginDataCB2 inPluginDataCallBackPtr, SPBasicSuite *inSPBasicSuitePtr, const char *inHostName, const char *inHostVersion) {
		PF_Err result = PF_Err_INVALID_CALLBACK;

		result = PF_REGISTER_EFFECT_EXT2 (
			inPtr,
			inPluginDataCallBackPtr,
			"p4ae",
			"POTI p4ae",
			"POTI",
			AE_RESERVED_INFO,
			"EffectMain",
			"https://github.com/potistudio"
		);

		return result;
	}
}

PF_Err EffectMain (PF_Cmd cmd, PF_InData *in_data, PF_OutData *out_data, PF_ParamDef *params[], PF_LayerDef *output, void *extra) {
	PF_Err error = PF_Err_NONE;

	try {
		switch (cmd) {
			case PF_Cmd_ABOUT:
				error = About (in_data, out_data, params, output);
				break;

			case PF_Cmd_GLOBAL_SETUP:
				error = GlobalSetup (in_data, out_data, params, output);
				break;

			case PF_Cmd_PARAMS_SETUP:
				error = ParamsSetup (in_data, out_data, params, output);
				break;

			case PF_Cmd_RENDER:
				error = Render (in_data, out_data, params, output);
				break;
		}
	} catch (PF_Err &thrown_error) {
		error = thrown_error;
	}

	return error;
}
