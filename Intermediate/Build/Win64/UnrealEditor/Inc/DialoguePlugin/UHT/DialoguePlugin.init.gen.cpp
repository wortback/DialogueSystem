// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDialoguePlugin_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_DialoguePlugin;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_DialoguePlugin()
	{
		if (!Z_Registration_Info_UPackage__Script_DialoguePlugin.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/DialoguePlugin",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xF83A798B,
				0x5BC6130B,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_DialoguePlugin.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_DialoguePlugin.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_DialoguePlugin(Z_Construct_UPackage__Script_DialoguePlugin, TEXT("/Script/DialoguePlugin"), Z_Registration_Info_UPackage__Script_DialoguePlugin, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xF83A798B, 0x5BC6130B));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
