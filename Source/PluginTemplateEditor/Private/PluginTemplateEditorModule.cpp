#include "PluginTemplateEditorModule.h"
#include "PluginTemplateEditor.h"

IMPLEMENT_MODULE(FPluginTemplateEditorModule, FPluginTemplateEditor)
DEFINE_LOG_CATEGORY(LogPlugin);
void FPluginTemplateEditorModule::StartupModule()
{
	// Add OnPostEngineInit delegate.
	OnPostEngineInitDelegateHandle = FCoreDelegates::OnPostEngineInit.AddRaw(this, &FPluginTemplateEditorModule::OnPostEngineInit);
}

void FPluginTemplateEditorModule::ShutdownModule()
{
	// Remove OnPostEngineInit delegate
	FCoreDelegates::OnPostEngineInit.Remove(OnPostEngineInitDelegateHandle);
}

void FPluginTemplateEditorModule::OnPostEngineInit()
{
	PluginTemplateEditor.Reset( NewObject<UPluginTemplateEditor>());
	PluginTemplateEditor->Init();
	
    // Do post engine stuff here
}
