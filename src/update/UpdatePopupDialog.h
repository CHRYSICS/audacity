/*!********************************************************************
 Audacity: A Digital Audio Editor

 @file UpdatePopupDialog.h
 @brief Define a dialog for notifying users about new version available.

 Anton Gerasimov
 **********************************************************************/

#pragma once

#include "widgets/wxPanelWrapper.h"
#include "wx/string.h"

#include "Project.h"

#include "update/UpdateManager.h"

class HtmlWindow;
class wxWindow;
class AudacityProject;
class UpdateManager;

class UpdatePopupDialog final : public wxDialogWrapper
{
    DECLARE_DYNAMIC_CLASS (AboutDialog)
public:
    explicit UpdatePopupDialog (wxWindow* parent, UpdateManager *updateManager);
    virtual ~UpdatePopupDialog();

    void OnUpdate (wxCommandEvent& event);
    void OnSkip (wxCommandEvent& event);
    void OnDontShow (wxCommandEvent& event);

    DECLARE_EVENT_TABLE()

private:
    HtmlWindow* AddHtmlContent (wxWindow* parent);

    UpdateManager* const mUpdateManager;
};