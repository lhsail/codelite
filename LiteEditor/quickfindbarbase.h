//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: quickfindbarbase.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef QUICKFINDBARBASE_BASE_CLASSES_H
#define QUICKFINDBARBASE_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/panel.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>

class QuickFindBarBase : public wxPanel
{
protected:
    wxCheckBox* m_checkBoxCase;
    wxCheckBox* m_checkBoxRegex;
    wxCheckBox* m_checkBoxWord;
    wxCheckBox* m_checkBoxHighlight;
    wxCheckBox* m_checkBoxWildcard;
    wxCheckBox* m_checkBoxMultipleSelections;
    wxTextCtrl* m_findWhat;
    wxTextCtrl* m_replaceWith;

protected:
    virtual void OnCheckBoxRegex(wxCommandEvent& event) { event.Skip(); }
    virtual void OnHighlightMatches(wxCommandEvent& event) { event.Skip(); }
    virtual void OnHighlightMatchesUI(wxUpdateUIEvent& event) { event.Skip(); }
    virtual void OnCheckWild(wxCommandEvent& event) { event.Skip(); }
    virtual void OnText(wxCommandEvent& event) { event.Skip(); }
    virtual void OnKeyDown(wxKeyEvent& event) { event.Skip(); }
    virtual void OnEnter(wxCommandEvent& event) { event.Skip(); }
    virtual void OnFindFocus(wxFocusEvent& event) { event.Skip(); }
    virtual void OnFindKillFocus(wxFocusEvent& event) { event.Skip(); }
    virtual void OnReplace(wxCommandEvent& event) { event.Skip(); }
    virtual void OnReplaceFocus(wxFocusEvent& event) { event.Skip(); }
    virtual void OnReplcaeKillFocus(wxFocusEvent& event) { event.Skip(); }

public:
    QuickFindBarBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(400,-1), long style = wxTAB_TRAVERSAL|wxTRANSPARENT_WINDOW);
    virtual ~QuickFindBarBase();
};

#endif
