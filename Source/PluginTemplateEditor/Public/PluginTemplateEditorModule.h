#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
class UPluginTemplateEditor;
DECLARE_LOG_CATEGORY_EXTERN(LogPlugin, Log, All)
class PLUGINTEMPLATEEDITOR_API FPluginTemplateEditorModule : public IModuleInterface
{

public:

	/** IModuleInterface implementation */
	void StartupModule() override;
	void ShutdownModule() override;

#if (ENGINE_MAJOR_VERSION == 5)
	virtual FString GetReferencerName() const {return TEXT("FPluginTemplateEditor");}
#endif

protected:

	/**
	 * Do stuff after engine is initialized.
	 */
	void OnPostEngineInit();

private:
	//TStrongObjectPtr<UPluginTemplateEditor> plugin;
	/** OnPostEngineInit delegate handler. */
	FDelegateHandle OnPostEngineInitDelegateHandle;
	TStrongObjectPtr<UPluginTemplateEditor> PluginTemplateEditor;
};
